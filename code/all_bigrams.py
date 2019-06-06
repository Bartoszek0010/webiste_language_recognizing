unique_list = list('qwertyuiopasdfghjklzxcvbnm,. ?!ęóąśżźćńłàèéìíòùñú')
bigrams = {}
unique_list.sort()
str_to_save = ''
for i in unique_list:
    for j in unique_list:
        str_to_save += i + j +'\n'
        print(i + j)
file = open("bigrams_dictionary.txt", "w")
file.write(str_to_save)
