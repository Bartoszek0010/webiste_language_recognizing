//
//  ReadHTML.hpp
//  language_recognizing
//
//  Created by Bartosz Jastrzębski on 07/04/2019.
//  Copyright © 2019 Bartosz Jastrzębski. All rights reserved.
//

#ifndef ReadHTML_hpp
#define ReadHTML_hpp

#include <stdio.h>
#include <string>
using namespace std;
class ReadHTML {
private:
    string bodyText = "";
public:
    ReadHTML();
    void readBodyText(string htmlText);
    int findBody(string text);
    int findEndBody(string text);
    string getBodyText(){ return bodyText; }
};
#endif /* ReadHTML_hpp */
