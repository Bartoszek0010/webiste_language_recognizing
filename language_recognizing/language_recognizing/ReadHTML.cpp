//
//  ReadHTML.cpp
//  language_recognizing
//
//  Created by Bartosz Jastrzębski on 07/04/2019.
//  Copyright © 2019 Bartosz Jastrzębski. All rights reserved.
//

#include "ReadHTML.hpp"
#include <iostream>
ReadHTML::ReadHTML(){
    
}

void ReadHTML::readBodyText(string htmlText){
    int startText = findBody(htmlText), stopText = findEndBody(htmlText);
    bool inBirds = false;
    for(int i = startText; i<stopText; i++){
        // check if we are in <>
        if(htmlText[i] == '<') inBirds = true;
        if(htmlText[i] == '>' && inBirds) {
            inBirds = false;
            bodyText += " ";
            continue;
        }
        // if we are out of them -> read text
        if(!inBirds) bodyText += htmlText[i];
    }
}

int ReadHTML::findBody(string text){
    string body = "<body>";
    size_t found = text.find(body);
    if (found!=string::npos)
        return int(found) + 6;
    return -1;
}

int ReadHTML::findEndBody(string text){
    string endBody = "</body>";
    size_t found = text.find(endBody);
    if (found!=string::npos)
        return int(found);
    return -1;
}

void ReadHTML::readAndSave(){
    string command = "curl " + website + " --output " + fileName;
    system(command.c_str());
}


string ReadHTML::readHtmlFromFile(){
    ifstream file(fileName);
    string fullText = "", tempText;
    if(!file){
        throw "This file does not exist";
    }
    while(!file.eof()){
        file>>tempText;
        fullText += tempText + " ";
    }
    return fullText;
}
