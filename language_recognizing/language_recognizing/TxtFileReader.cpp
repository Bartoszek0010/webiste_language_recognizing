//
//  TxtFileReader.cpp
//  language_recognizing
//
//  Created by Bartosz Jastrzębski on 06/04/2019.
//  Copyright © 2019 Bartosz Jastrzębski. All rights reserved.
//

#include "TxtFileReader.hpp"
#include <iostream>
using namespace std;

std::map<std::string, int> TxtFileReader::readText(){
    ifstream dictionary(fileName);
    cout<<fileName;
    if(!dictionary){
        throw "This file does not exist.";
    }
    while(!dictionary.eof()){
        string stringToSave, tempString;
        int intToSave;
        dictionary>>tempString;
        stringToSave = tempString + " ";
        dictionary>>tempString;
        stringToSave += tempString;
        dictionary>>tempString;
        intToSave = atoi(tempString.c_str());
        languageMap[stringToSave] = intToSave;
    }
    dictionary.close();
    return languageMap;
}
