//
//  TxtFileLetReader.cpp
//  language_recognizing
//
//  Created by Bartosz Jastrzębski on 09/04/2019.
//  Copyright © 2019 Bartosz Jastrzębski. All rights reserved.
//

#include "TxtFileLetReader.hpp"


map<string, int> TxtFileLetReader:: readText(){
    ifstream dictionary(fileName);
    //    cout<<fileName;
    if(!dictionary){
        throw "This file does not exist.";
    }
    while(!dictionary.eof()){
        string stringToSave;
        string intToSave;
        dictionary>>stringToSave;
        dictionary>>intToSave;
        languageMap[stringToSave] = atoi(intToSave.c_str());
    }
    dictionary.close();
    return languageMap;
}
