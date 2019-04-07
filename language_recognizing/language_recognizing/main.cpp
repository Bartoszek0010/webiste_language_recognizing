//
//  main.cpp
//  language_recognizing
//
//  Created by Bartosz Jastrzębski on 06/04/2019.
//  Copyright © 2019 Bartosz Jastrzębski. All rights reserved.
//

#include <iostream>

#include "FileReader.hpp"
#include "TxtFileReader.hpp"
#include "LanguageDB.hpp"
#include "ReadHTML.hpp"
using namespace std;

void printMap(map<string, int> map){
    for (auto& x : map){
        cout<<x.first<<" "<<x.second<<endl;
    }
}

int main(int argc, const char * argv[]) {
    LanguageDB languages = LanguageDB();
    ReadHTML html = ReadHTML();
    
    // check recognizing language
//    string lan = languages.checkBigramsCorrect("Witam w moim domu");
//    cout<<lan;
    
    
    // check reading only <body>...</body>
//    html.readBodyText("<!DOCTYPE html><html><body><h1>My First Heading</h1><p>My first paragraph.</p></body></html>");
//    string body = html.getBodyText();
//    cout<<body<<endl;
    
    
    // again reading only body but from the file and recognizing language
//    ifstream file("htmlTestFile.html.rtf");
//    string fullHtml = "", tempText;
//    while(!file.eof()){
//        file>>tempText;
//        fullHtml += tempText;
//        fullHtml += " ";
//    }
//    cout<<fullHtml<<endl;
//    html.readBodyText(fullHtml);
//    string body = html.getBodyText();
//    cout<<body<<endl;
//    string lan = languages.checkBigramsCorrect(body);
//    cout<< lan;
    return 0;
}
