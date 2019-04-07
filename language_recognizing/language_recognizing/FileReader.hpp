//
//  FileReader.hpp
//  language_recognizing
//
//  Created by Bartosz Jastrzębski on 06/04/2019.
//  Copyright © 2019 Bartosz Jastrzębski. All rights reserved.
//

#ifndef FileReader_hpp
#define FileReader_hpp

#include <stdio.h>
#include <map>
#include <string>
#include <fstream>
class FileReader {
protected:
    std::string fileName;
    std::map<std::string, int> languageMap;
public:
    void setFileName(std::string fileName){
        this->fileName = fileName;
    }
    virtual std::map<std::string, int> readText() = 0;
    virtual ~FileReader() = default;
    FileReader() = default;
};
#endif /* FileReader_hpp */
