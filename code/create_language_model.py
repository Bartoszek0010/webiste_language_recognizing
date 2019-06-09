import os
import numpy as np
import re
import urllib.request
from bs4 import BeautifulSoup
from tqdm import tqdm

# bigrams
def save_model(language, language_name):
    language = language.split()
    language = ' '.join(language)

    language_correct = language
    language_correct = language_correct.lower()
    os.chdir(FILE_LOCATION)

    bigrams, amount = fill_dictionary(language_correct, get_unique_dict())
    unigrams, unigrams_amount = fill_dictionary_unigrams(language_correct, get_unique_dict_unigram())

    # save bigrams amount
    file_name_amount = language_name + '_amount.txt'
    lan_amount = open(file_name_amount, 'w')
    lan_amount.write(str(amount))

    # save unigrams amount
    file_name_amount_uni = language_name + '_amount_uni.txt'
    lan_amount_uni = open(file_name_amount_uni, 'w')
    lan_amount_uni.write(str(unigrams_amount))

    #save bigrams model
    file_name = language_name + '_model.txt'
    language_lan_model = open(file_name, 'w')
    str_to_save = ''
    for i in bigrams.items():
        str_to_save += i[0] + ' ' + str(i[1]) + '\n'

    language_lan_model.write(str_to_save)

    #save unigrams model
    file_name_uni = language_name + '_model_uni.txt'
    language_lan_model_uni = open(file_name_uni, 'w')
    str_to_save = ''
    for i in unigrams.items():
        str_to_save += i[0] + ' ' + str(i[1]) + '\n'

    language_lan_model_uni.write(str_to_save)

def get_unique_dict():
    unique_list = open('bigrams_dictionary.txt').read()
    unique_list = unique_list.split('\n')
    bigrams = {}
    for i in unique_list:
        bigrams[i] = 0
    return bigrams


def fill_dictionary(text, bigrams):
    amount = 0
    for i in tqdm(range(len(text) - 1),
                desc="Text to model (bigrams)"):
        bg = text[i] + text[i + 1]
        if bg in bigrams.keys():
            bigrams[bg] += 1
            amount += 1
    # normalize
    for i in bigrams.items():
        val = i[1] / amount
        bigrams[i[0]] = val

    return bigrams, amount


def learn_model_big(lan_model, lan_amount, text_model, text_amount, language_name):
    # unnormalize
    for i in tqdm(lan_model.items(),
                desc='Learning language model part 1'):
        val = i[1] * lan_amount
        lan_model[i[0]] = val

    sum_amount = lan_amount + text_amount
    new_model = lan_model

    # create and normalize new model
    for i in tqdm(new_model.items(),
                desc="Learning new model part 2"):
        val = (i[1] + text_model[i[0]]) / sum_amount
        new_model[i[0]] = val
    # save to file new model and amount
    file_name_amount = language_name + '_amount.txt'
    lan_amount = open(file_name_amount, 'w')
    lan_amount.write(str(sum_amount))

    file_name = language_name + '_model.txt'
    language_lan_model = open(file_name, 'w')
    str_to_save = ''
    for i in tqdm(new_model.items(),
                desc="Saving new model"):
        str_to_save += i[0] + ' ' + str(i[1]) + '\n'

    language_lan_model.write(str_to_save)


def learn_model_uni(lan_model, lan_amount, text_model, text_amount, language_name):
    # unnormalize
    for i in tqdm(lan_model.items(),
                desc='Learning language model part 1'):
        val = i[1] * lan_amount
        lan_model[i[0]] = val

    sum_amount = lan_amount + text_amount
    new_model = lan_model

    # create and normalize new model
    for i in tqdm(new_model.items(),
                desc="Learning new model part 2"):
        val = (i[1] + text_model[i[0]]) / sum_amount
        new_model[i[0]] = val

    # save to file new model and amount
    file_name_amount = language_name + '_amount_uni.txt'
    lan_amount = open(file_name_amount, 'w')
    lan_amount.write(str(sum_amount))

    file_name = language_name + '_model_uni.txt'
    language_lan_model = open(file_name, 'w')
    str_to_save = ''
    for i in tqdm(new_model.items(),
                desc="Saving new model"):
        str_to_save += i[0] + ' ' + str(i[1]) + '\n'

    language_lan_model.write(str_to_save)



# unigrams
def get_unique_dict_unigram():
    unique_list = open('unigrams_dictionary.txt').read()
    unique_list = unique_list.split('\n')
    unigrams = {}
    for i in unique_list:
        unigrams[i] = 0
    return unigrams


def fill_dictionary_unigrams(text, unigrams):
    amount = 0
    for i in tqdm(range(len(text)),
                desc="Text to model (unigrams)"):
        bg = text[i]
        if bg in unigrams.keys():
            unigrams[bg] += 1
            amount += 1
    # normalize
    for i in unigrams.items():
        val = i[1] / amount
        unigrams[i[0]] = val

    return unigrams, amount





def main():
    FILE_LOCATION = os.getcwd()
    os.chdir('../languages')
    english = open('english.txt').read()
    polish = open('polish.txt').read()
    spanish = open('spanish.txt').read()
    italian = open('italian.txt').read()
    # german = open('german.txt').read()

    save_model(english, 'english')
    save_model(polish, 'polish')
    save_model(spanish, 'spanish')
    save_model(italian, 'italian')
# save_model(german, 'german')


# FILE_LOCATION = os.getcwd()
# os.chdir('../languages')
# english = open('english.txt').read()
# polish = open('polish.txt').read()
# spanish = open('spanish.txt').read()
# italian = open('italian.txt').read()
# # german = open('german.txt').read()
#
# save_model(english, 'english')
# save_model(polish, 'polish')
# save_model(spanish, 'spanish')
# save_model(italian, 'italian')
# # save_model(german, 'german')
