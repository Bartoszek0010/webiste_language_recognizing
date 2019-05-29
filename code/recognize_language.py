import os
import numpy as np
import re
import urllib.request
from bs4 import BeautifulSoup
import math

FILE_LOCATION = os.getcwd()
MODELS = {'english' : 'english_model.txt', 'polish' : 'polish_model.txt', 'spanish' : 'spanish_model.txt',
'italian' : 'italian_model.txt'}
def get_unique_dict():
    unique_list = open('bigrams_dictionary.txt').read()
    unique_list = unique_list.split('\n')
    bigrams = {}
    for i in unique_list:
        if len(i) == 2:
            bigrams[i] = 0
    return bigrams

def fill_dictionary(text, bigrams):
    amount = 0
    for i in range(len(text) - 1):
        bg = text[i] + text[i + 1]
        if bg in bigrams.keys():
            bigrams[bg] += 1
            amount += 1
    # normalize
    for i in bigrams.items():
        val = i[1] / amount
        bigrams[i[0]] = val

    return bigrams

def get_body_text(url):
    page = urllib.request.urlopen(url).read()
    soup = BeautifulSoup(page)
    txt = soup.find('body').getText()
    return txt

def create_model(txt):
    txt = txt.split()
    txt = ' '.join(txt).lower()
    os.chdir(FILE_LOCATION)

    bigrams = fill_dictionary(txt, get_unique_dict())
    return bigrams

def get_model(file):
    model = open(file).read().split('\n')

    bigrams = {}
    for i in model:
        key = i[0:2]
        value = i[3:len(i)]
        if len(value) >= 3:
            bigrams[key] = float(value)
    return bigrams

def difference(txt_model, lan_model):
    txt_values = np.array(list(txt_model.values()))
    lan_values = np.array(list(lan_model.values()))
    dif_values = (txt_values - lan_values)**2
    difference_euclides = math.sqrt(np.sum(dif_values))
    return difference_euclides

print("Website: ")
url = input()
txt = get_body_text(url)
model = create_model(txt)
results = {}
for mod in MODELS.items():
    results[mod[0]] = difference(model, get_model(mod[1]))
print(results)
