//
//  LanguageDB.cpp
//  language_recognizing
//
//  Created by Bartosz Jastrzębski on 06/04/2019.
//  Copyright © 2019 Bartosz Jastrzębski. All rights reserved.
//

#include "LanguageDB.hpp"
#include <iostream>
LanguageDB::LanguageDB(){
    //english
    reader txtReaderEnglish = make_unique<TxtFileReader>();
    txtReaderEnglish->setFileName("english2cpp.txt");
    languages.push_back(txtReaderEnglish->readText());
    languagesNames.push_back("english");
    //polish
    reader txtReaderPolish = make_unique<TxtFileReader>();
    txtReaderPolish->setFileName("polish2cpp.txt");
    languages.push_back(txtReaderPolish->readText());
    languagesNames.push_back("polish");
    cout<<languages[1].size()<<endl;
    //spanish
    reader txtReaderSpanish = make_unique<TxtFileReader>();
    txtReaderSpanish->setFileName("spanish2cpp.txt");
    languages.push_back(txtReaderSpanish->readText());
    languagesNames.push_back("spanish");
    //italian
    reader txtReaderItalian = make_unique<TxtFileReader>();
    txtReaderItalian->setFileName("italian2cpp.txt");
    languages.push_back(txtReaderItalian->readText());
    languagesNames.push_back("italian");
    
    //english letters
    reader txtReaderEnglishLet = make_unique<TxtFileLetReader>();
    txtReaderEnglishLet->setFileName("english2cpp_let.txt");
    languages_let.push_back(txtReaderEnglishLet->readText());
    //polish letters
    reader txtReaderPolishLet = make_unique<TxtFileLetReader>();
    txtReaderPolishLet->setFileName("polish2cpp_let.txt");
    languages_let.push_back(txtReaderPolishLet->readText());
    cout<<languages_let[1].size()<<endl;
    //spanish letters
    reader txtReaderSpanishLet = make_unique<TxtFileLetReader>();
    txtReaderSpanishLet->setFileName("spanish2cpp_let.txt");
    languages_let.push_back(txtReaderSpanishLet->readText());
    //italian letters
    reader txtReaderItalianLet = make_unique<TxtFileLetReader>();
    txtReaderItalianLet->setFileName("italian2cpp_let.txt");
    languages_let.push_back(txtReaderItalianLet->readText());
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
// this method find a tempText(2 words) in map and add to sum number of this key's in dictionary
string LanguageDB::checkBigramsCorrect(wstring text){
=======
=======
>>>>>>> parent of c21a5fd... add checking language by letters (not words) nad checking only if key exists in language model
=======
>>>>>>> parent of c21a5fd... add checking language by letters (not words) nad checking only if key exists in language model
=======
>>>>>>> parent of c21a5fd... add checking language by letters (not words) nad checking only if key exists in language model

string LanguageDB::checkBigramsCorrect(string text){
>>>>>>> parent of c21a5fd... add checking language by letters (not words) nad checking only if key exists in language model
    vector<int> sums;
    vector<wstring> textVec = text2array(text);
    for(int j=0; j<languages.size();j++){
        sums.push_back(0);
        for(int i=0; i<textVec.size() - 1; i++){
            wstring tempText = textVec.at(i) + L" " + textVec.at(i + 1);
//            cout<<tempText<< " "<<languages.at(j)[tempText]<<endl;
            sums.at(j) += languages.at(j)[tempText];
        }
    }
    
    int correctLanguage = maxElement(sums);
    if(sums.at(correctLanguage) == 0){
        throw "Can't recognize this language";
    }
    return languagesNames.at(correctLanguage);
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
// this method find a tempText(2 letters) in map and add to sum number of this key's in dictionary
string LanguageDB::checkBigramsCorrectLet(wstring text){
=======
=======
>>>>>>> parent of c21a5fd... add checking language by letters (not words) nad checking only if key exists in language model
=======
>>>>>>> parent of c21a5fd... add checking language by letters (not words) nad checking only if key exists in language model
=======
>>>>>>> parent of c21a5fd... add checking language by letters (not words) nad checking only if key exists in language model

string LanguageDB::checkBigramsCorrectLet(string text){
>>>>>>> parent of c21a5fd... add checking language by letters (not words) nad checking only if key exists in language model
    vector<int> sums;
    cout<<languages_let.size()<<endl;
    for(int j=0; j<languages_let.size();j++){
        sums.push_back(0);
        for(int i=0; i<text.length() - 1; i++){
            wstring tempText;
            tempText += text[i];
            tempText += text[i + 1];
            wcout<<tempText<<endl;
            sums.at(j) += languages_let.at(j)[tempText];
        }
    }
    int correctLanguage = maxElement(sums);
    if(sums.at(correctLanguage) == 0){
        throw "Can't recognize this language";
    }
    return languagesNames.at(correctLanguage);
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
// this method find a tempText in map and only add 1 (exists in dictionary)
string LanguageDB::checkBigramsCorrectLet2(wstring text){
    vector<int> sums;
    for(int j=0; j<languages_let.size();j++){
        sums.push_back(0);
        for(int i=0; i<text.length() - 1; i++){
            wstring tempText;
            tempText += text[i];
            tempText += text[i + 1];
            if(languages_let.at(j).find(tempText) != languages_let.at(j).end()){
                sums.at(j) += 1;
            }
        }
        cout<<sums.at(j)<<endl;
    }
    
    int correctLanguage = maxElement(sums);
    if(sums.at(correctLanguage) == 0){
        throw "Can't recognize this language";
    }
    return languagesNames.at(correctLanguage);
}
=======
>>>>>>> parent of c21a5fd... add checking language by letters (not words) nad checking only if key exists in language model
=======
>>>>>>> parent of c21a5fd... add checking language by letters (not words) nad checking only if key exists in language model
=======
>>>>>>> parent of c21a5fd... add checking language by letters (not words) nad checking only if key exists in language model
=======
>>>>>>> parent of c21a5fd... add checking language by letters (not words) nad checking only if key exists in language model

int LanguageDB::maxElement(vector<int> vec){
    int maxIndex = 0;
    for(int i = 0; i < vec.size(); i++){
        if(vec.at(i) > vec.at(maxIndex)){
            maxIndex = i;
        }
    }
    return maxIndex;
}

vector<wstring> LanguageDB::text2array(wstring text){
    wstring textToVec = L"";
    vector<wstring> textVector;
    for(int i=0; i<text.length(); i++){
        if(text[i] != ',' && text[i] != '.' && text[i] != '!' && text[i] != ';' && text[i] != '?' && text[i] != '\\'){
            if(text[i] == ' '){
                textVector.push_back(textToVec);
                textToVec = L"";
            } else{
                textToVec += text[i];
            }
        }
    }
    textVector.push_back(textToVec);
    return textVector;
}
