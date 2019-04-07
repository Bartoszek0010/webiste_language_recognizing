//
//  LanguageDB.cpp
//  language_recognizing
//
//  Created by Bartosz Jastrzębski on 06/04/2019.
//  Copyright © 2019 Bartosz Jastrzębski. All rights reserved.
//

#include "LanguageDB.hpp"

LanguageDB::LanguageDB(){
    
}

int LanguageDB::checkBigramsCorrect(int index, string text){
    int sum = 0;
    vector<string> textVec = text2array(text);
    for(int i=0; i<text.size() - 1; i++){
        string tempText = textVec.at(i) + " " + textVec.at(i + 1);
        sum += languages.at(index)[tempText];
    }
    return sum;
}
vector<string> LanguageDB::text2array(string text){
    string textToVec = "";
    vector<string> textVector;
    for(int i=0; i<text.length(); i++){
        if(text[i] != ',' && text[i] != '.' && text[i] != '!' && text[i] != ';' && text[i] != '?'){
            if(text[i] == ' '){
                textVector.push_back(textToVec);
            } else{
                textToVec += text[i];
            }
        }
    }
    return textVector;
}
