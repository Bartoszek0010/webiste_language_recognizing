import os
import numpy as np
import re
import urllib.request
from bs4 import BeautifulSoup

def save_model(language, language_name):
    language = language.split()
    language = ' '.join(language)

    language_correct = language
    language_correct = language_correct.lower()
    os.chdir(FILE_LOCATION)

    bigrams = fill_dictionary(language_correct, get_unique_dict())

    file_name = language_name + '_model.txt'
    language_lan_model = open(file_name, 'w')
    str_to_save = ''
    for i in bigrams.items():
        str_to_save += i[0] + ' ' + str(i[1]) + '\n'

    language_lan_model.write(str_to_save)
    print(sum(list(bigrams.values())))

def get_unique_dict():
    unique_list = open('bigrams_dictionary.txt').read()
    unique_list = unique_list.split('\n')
    bigrams = {}
    for i in unique_list:
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

FILE_LOCATION = os.getcwd()
os.chdir('../languages')
english = open('english.txt').read()
polish = open('polish.txt').read()
spanish = open('spanish.txt').read()
italian = open('italian.txt').read()
# german = open('german.txt').read()

# save_model(english, 'english')
# save_model(polish, 'polish')
save_model(spanish, 'spanish')
save_model(italian, 'italian')
# save_model(german, 'german')
