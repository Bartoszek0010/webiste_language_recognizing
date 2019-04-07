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
using namespace std;

void printMap(map<string, int> map){
    for (auto& x : map){
        cout<<x.first<<" "<<x.second<<endl;
    }
}

int main(int argc, const char * argv[]) {
    using reader = unique_ptr<FileReader>;
    //english
    reader txtReaderEnglish = make_unique<TxtFileReader>();
    txtReaderEnglish->setFileName("english2cpp.txt");
    map<string, int> languageMapEnglish = txtReaderEnglish->readText();
    //polish
    reader txtReaderPolish = make_unique<TxtFileReader>();
    txtReaderPolish->setFileName("polish2cpp.txt");
    map<string, int> languageMapPolish = txtReaderPolish->readText();
    //spanish
    reader txtReaderSpanish = make_unique<TxtFileReader>();
    txtReaderSpanish->setFileName("spanish2cpp.txt");
    map<string, int> languageMapSpanish = txtReaderSpanish->readText();
    //italian
    reader txtReaderItalian = make_unique<TxtFileReader>();
    txtReaderItalian->setFileName("italian2cpp.txt");
    map<string, int> languageMapEItalian = txtReaderItalian->readText();
    printMap(languageMapPolish);
    return 0;
}
