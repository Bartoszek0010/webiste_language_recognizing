//
//  LanguageDB.hpp
//  language_recognizing
//
//  Created by Bartosz Jastrzębski on 06/04/2019.
//  Copyright © 2019 Bartosz Jastrzębski. All rights reserved.
//

#ifndef LanguageDB_hpp
#define LanguageDB_hpp

#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <regex>

#include "FileReader.hpp"
#include "TxtFileReader.hpp"
#include "TxtFileLetReader.hpp"
//#include <wstring>

using namespace std;
class LanguageDB{
private:
    vector<map<string, int>> languages;
    vector<map<string, int>> languages_let;
    vector<string> languagesNames;
    using reader = unique_ptr<FileReader>;
public:
    LanguageDB();
    void addLanguage(map<string, int> map){
        languages.push_back(map);
    }
    string checkBigramsCorrect(string text);
    string checkBigramsCorrectLet(string text);
    vector<string> text2array(string text);
    int maxElement(vector<int> vec);
};
#endif /* LanguageDB_hpp */
