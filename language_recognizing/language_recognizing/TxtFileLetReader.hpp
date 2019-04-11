//
//  TxtFileLetReader.hpp
//  language_recognizing
//
//  Created by Bartosz Jastrzębski on 09/04/2019.
//  Copyright © 2019 Bartosz Jastrzębski. All rights reserved.
//

#ifndef TxtFileLetReader_hpp
#define TxtFileLetReader_hpp

#include <stdio.h>

#include "FileReader.hpp"
using namespace std;
class TxtFileLetReader : public FileReader {
private:
public:
    map<string, int> readText();
};
#endif /* TxtFileLetReader_hpp */
