//
//  LanguageDB.cpp
//  language_recognizing
//
//  Created by Bartosz Jastrzębski on 06/04/2019.
//  Copyright © 2019 Bartosz Jastrzębski. All rights reserved.
//

#include "LanguageDB.hpp"

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
    
}

string LanguageDB::checkBigramsCorrect(string text){
    vector<int> sums;
    vector<string> textVec = text2array(text);
    for(int j=0; j<languages.size();j++){
        sums.push_back(0);
        for(int i=0; i<textVec.size() - 1; i++){
            string tempText = textVec.at(i) + " " + textVec.at(i + 1);
            sums.at(j) += languages.at(j)[tempText];
        }
    }
    int correctLanguage = maxElement(sums);
    if(sums.at(correctLanguage) == 0){
        throw "Can't recognize this language";
    }
    return languagesNames.at(correctLanguage);
}

int LanguageDB::maxElement(vector<int> vec){
    int maxIndex = 0;
    for(int i = 0; i< vec.size(); i++){
        if(vec.at(i) > vec.at(maxIndex)){
            maxIndex = i;
        }
    }
    return maxIndex;
}

vector<string> LanguageDB::text2array(string text){
    string textToVec = "";
    vector<string> textVector;
    for(int i=0; i<text.length(); i++){
        if(text[i] != ',' && text[i] != '.' && text[i] != '!' && text[i] != ';' && text[i] != '?' && text[i] != '\\'){
            if(text[i] == ' '){
                textVector.push_back(textToVec);
                textToVec = "";
            } else{
                textToVec += text[i];
            }
        }
    }
    textVector.push_back(textToVec);
    return textVector;
}
