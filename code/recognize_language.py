import os
import numpy as np
import re
import urllib.request
from bs4 import BeautifulSoup
import math
import sys
from tqdm import tqdm

FILE_LOCATION = os.getcwd()
MODELS = {'english' : 'english_model.txt', 'polish' : 'polish_model.txt', 'spanish' : 'spanish_model.txt',
'italian' : 'italian_model.txt'}
MODELS_UNI = {'english' : 'english_model_uni.txt', 'polish' : 'polish_model_uni.txt', 'spanish' : 'spanish_model_uni.txt',
'italian' : 'italian_model_uni.txt'}
# bigrams
def get_unique_dict():
    unique_list = open('bigrams_dictionary.txt').read()
    unique_list = unique_list.split('\n')
    bigrams = {}
    for i in unique_list:
        if len(i) == 2:
            bigrams[i] = 0
    unique_list_uni = open('unigrams_dictionary.txt').read()
    unique_list_uni = unique_list_uni.split('\n')
    unigrams = {}
    for i in unique_list_uni:
        unigrams[i] = 0
    return bigrams, unigrams


def fill_dictionary(text, bigrams, unigrams):
    amount = 0
    for i in tqdm(range(len(text) - 1),
                    desc='Creating language model of text bigrams'):
        bg = text[i] + text[i + 1]
        if bg in bigrams.keys():
            bigrams[bg] += 1
            amount += 1

    # normalize
    for i in bigrams.items():
        val = i[1] / amount
        bigrams[i[0]] = val

    amount = 0
    for i in tqdm(range(len(text)),
                    desc='Creating language model of text unigrams'):
        uni = text[i]
        if uni in unigrams.keys():
            unigrams[uni] += 1
            amount += 1

    # normalize
    for i in unigrams.items():
        val = i[1] / amount
        unigrams[i[0]] = val


    return bigrams, unigrams


def get_fill_dictionary(text, bigrams, unigrams):
    amount = 0
    for i in range(len(text) - 1):
        bg = text[i] + text[i + 1]
        if bg in bigrams.keys():
            bigrams[bg] += 1
            amount += 1
    amount_uni = 0
    for i in range(len(text)):
        uni = text[i]
        if bg in unigrams.keys():
            unigrams[bg] += 1
            amount_uni += 1
    return bigrams, amount, unigrams, amount_uni


def get_body_text(url):
    page = urllib.request.urlopen(url).read()
    soup = BeautifulSoup(page)
    txt = soup.find('body').getText()
    return txt


def create_model(txt):
    txt = txt.split()
    txt = ' '.join(txt).lower()
    os.chdir(FILE_LOCATION)
    unique_big, unique_uni = get_unique_dict()
    bigrams, unigrams = fill_dictionary(txt, unique_big, unique_uni)
    return bigrams, unigrams


def get_model(file):
    model = open(file).read().split('\n')

    bigrams = {}
    for i in model:
        key = i[0:2]
        value = i[3:len(i)]
        if len(value) >= 3:
            bigrams[key] = float(value)
    return bigrams


def get_model_uni(file):
    model = open(file).read().split('\n')
    unigrams = {}
    for i in model:
        if len(i) > 0:
            key = i[0]
            value = i[2:len(i)]
            if len(value) >= 3:
                unigrams[key] = float(value)
    return unigrams

def difference(txt_model, lan_model):
    txt_values = np.array(list(txt_model.values()))
    lan_values = np.array(list(lan_model.values()))
    dif_values = (txt_values - lan_values)**2
    difference_euclides = math.sqrt(np.sum(dif_values))
    return difference_euclides

# unigrams

def main(url):
    txt = get_body_text(url)
    model_big, model_uni = create_model(txt)
    results_big = {}
    results_uni = {}
    for mod in tqdm(MODELS.items(),
                    desc="Checking difference for all languages bigrams"):
        results_big[mod[0]] = difference(model_big, get_model(mod[1]))
    for mod in tqdm(MODELS_UNI.items(),
                    desc="Checking difference for all languages unigrams"):
        results_uni[mod[0]] = difference(model_uni, get_model_uni(mod[1]))
    return results_big, results_uni
