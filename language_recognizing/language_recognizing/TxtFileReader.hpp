//
//  TxtFileReader.hpp
//  language_recognizing
//
//  Created by Bartosz Jastrzębski on 06/04/2019.
//  Copyright © 2019 Bartosz Jastrzębski. All rights reserved.
//

#ifndef TxtFileReader_hpp
#define TxtFileReader_hpp

#include <stdio.h>
#include "FileReader.hpp"
class TxtFileReader : public FileReader {
public:
    std::map<std::string, int> readText();
};
#endif /* TxtFileReader_hpp */
