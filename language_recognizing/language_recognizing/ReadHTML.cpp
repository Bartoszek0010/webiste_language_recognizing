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
    //cout<<startText<< " " << stopText<<endl;
    if(startText == -1 || stopText == -1){
        throw "incorrect url, can't get html source";
        return;
    }
    string onlyBody = htmlText.substr(startText, stopText - 1);
    bool inBirds = true, closingBird = false;
    
    while(findParag(onlyBody) != -1){
        int paragStart = findParag(onlyBody), paragStop = findEndParag(onlyBody);
        //cout<<paragStart << "   "<<paragStop << endl;
        for(int i = paragStart; i < paragStop; i++){
            if(onlyBody[i] == '>'){ // condition to wait for the and of <a ... >
                closingBird = true;
            }
            if(closingBird){
                if(onlyBody[i] == '<') inBirds = true; // don't wanna read text inside <......>
                if(onlyBody[i] == '>' && inBirds) {
                    inBirds = false;
                    bodyText += " ";
                    continue;
                }
                if(!inBirds && onlyBody[i] != '>') bodyText += onlyBody[i]; // add to body text when is out of <...> and it's not a '>'
            }
        }
        closingBird = false; // reset a condition of waiting for end of <a...>
        onlyBody = onlyBody.substr(paragStop, onlyBody.length() - 1); // remake a source text, only find <a>..</a> after found <a></a>
    }
}

int ReadHTML::findBody(string text){
    string body = "<body";
    size_t found = text.find(body);
    if (found!=string::npos)
        return int(found) + 5;
    return -1;
}

int ReadHTML::findEndBody(string text){
    string endBody = "</body>";
    size_t found = text.find(endBody);
    if (found!=string::npos)
        return int(found);
    return -1;
}

int ReadHTML::findParag(string text){
    string parag = "<a";
    size_t found = text.find(parag);
    if(found!=string::npos) return int(found) + 2;
    return -1;
}

int ReadHTML::findEndParag(string text){
    string endParag = "</a>";
    size_t found = text.find(endParag);
    if(found!=string::npos) return int(found) + 4;
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
