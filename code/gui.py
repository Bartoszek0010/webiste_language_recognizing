import tkinter as tk
import os
import recognize_language
import create_language_model
SIZE = "500x400"
HEIGHT = 400
WIDTH = 500
results = {}
show = False
def getLanguage():
    url = website.get()
    results_big, results_uni = recognize_language.main(url)

    if var.get() == 1:
        min_err = min(list(results_big.values()))
        lang = ""
        for key, val in results_big.items():
            if val == min_err:
                lang = key
                break
        text_var.set(lang)

        other_str = "Other languages and euclidean distance (language model - this text): \n"
        for key, val in results_big.items():
            other_str += key + ': '
            other_str += str(val) + '\n'
        other_lang_text.set(other_str)
    if var.get() == 2:
        min_err = min(list(results_uni.values()))
        lang = ""
        for key, val in results_uni.items():
            if val == min_err:
                lang = key
                break
        text_var.set(lang)

        other_str = "Other languages and euclidean distance (language model - this text): \n"
        for key, val in results_uni.items():
            other_str += key + ': '
            other_str += str(val) + '\n'
        other_lang_text.set(other_str)



def learnModels():
    url = website.get()
    txt = recognize_language.get_body_text(url)

    txt = txt.split()
    txt = ' '.join(txt).lower()
    correct_language = text_var.get()
    big_unique, uni_unique = recognize_language.get_unique_dict()
    r_big, amount_big, r_uni, amount_uni = recognize_language.get_fill_dictionary(txt, big_unique, uni_unique)
    lan_model_big = recognize_language.get_model(correct_language + '_model.txt')
    lan_model_uni = recognize_language.get_model_uni(correct_language + '_model_uni.txt')

    lan_amount_big = int(open(correct_language + '_amount.txt').read())
    lan_amount_uni = int(open(correct_language + '_amount_uni.txt').read())

    create_language_model.learn_model_big(lan_model_big, lan_amount_big, r_big, amount_big, correct_language)
    create_language_model.learn_model_uni(lan_model_uni, lan_amount_uni, r_uni, amount_uni, correct_language)


# window settings
window = tk.Tk()
window.title("Recognizing language of website")
window.geometry(SIZE)

# define all objects
text_var = tk.StringVar(window)
other_lang_text = tk.StringVar(window)
var = tk.IntVar()
language = tk.Label(window, width = WIDTH, height = 1, textvariable = text_var)
intro = tk.Text(window,width = WIDTH, height = 2)
website = tk.Entry(window, width = 40)
radio_bigrams = tk.Radiobutton(window, text='Bigrams', variable = var, value = 1,
                                command='sel')
radio_unigrams = tk.Radiobutton(window, text='Unigrams', variable = var, value = 2,
                                command='sel')
other_lan = tk.Label(window, width = WIDTH, height = 6, textvariable = other_lang_text)
learning_text = tk.Text(window, width = WIDTH, height = 2)
confirm_learning = tk.Button(window, text = "Correct", width = 20, command = learnModels)
# introduction textbox settings

intro.insert(tk.END, 'To recognize language of website please enter a webite`s adress below.')
intro.insert(tk.END, '\n')
intro.insert(tk.END, 'Website`s adress:', ('p'))
intro.tag_add('p','1.0','1.0')
intro.tag_config('p', justify='center')
intro.config(state='disabled', bg = "gray")
intro.pack()

# entry website

website.pack()

# submit button settings

confirm = tk.Button(window, text = "submit", width = 20, command = getLanguage, bg = "gray")
confirm.pack()

# radio button (bigrams or unigrams)

radio_bigrams.pack()
radio_bigrams.select()
radio_unigrams.pack()
# information about language settings


language.config(state='disabled', bg = "black")
language.pack()


# information about prababilities of other languages

other_lan.config(state = 'disabled', bg = "black")
other_lan.pack()

# Learning models
len_t = 'Please let me know if language of website is the same as this one which program predicted for you'

learning_text.insert(tk.END, len_t)
learning_text.config(state = 'disabled', bg = "gray")
learning_text.pack()

# Learning submit

confirm_learning.pack()
tk.mainloop()
