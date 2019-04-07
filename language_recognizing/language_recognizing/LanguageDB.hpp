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
//#include <wstring>

using namespace std;
class LanguageDB{
private:
    vector<map<string, int>> languages;
public:
    LanguageDB();
    void addLanguage(map<string, int> map){
        languages.push_back(map);
    }
    int checkBigramsCorrect(int index, string text);
    vector<string> text2array(string text);
};
#endif /* LanguageDB_hpp */
