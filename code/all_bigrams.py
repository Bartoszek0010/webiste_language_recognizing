unique_list = list('qwertyuiopasdfghjklzxcvbnm,. ?!ęóąśżźćńłàèéìíòùñú')
unique_list.sort()
str_to_save = ''
for i in unique_list:
    for j in unique_list:
        str_to_save += i + j +'\n'
file = open("bigrams_dictionary.txt", "w")
file.write(str_to_save)

unique_list_unigram = list('qwertyuiopasdfghjklzxcvbnmęóąśżźćńłàèéìíòùñú')
unique_list_unigram.sort()
str_to_save = ''
for i in unique_list_unigram:
    str_to_save += i + '\n'
file_unigrams = open("unigrams_dictionary.txt", "w")
file_unigrams.write(str_to_save)
