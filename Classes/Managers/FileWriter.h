//
// Created by bulba on 18.11.2021.
//

#ifndef KURSACH_OOP_FILEWRITER_H
#define KURSACH_OOP_FILEWRITER_H

#include "Singleton.h"
using namespace std;
class FileWriter: Singleton<FileWriter> {
public:bool WriteWorkersInFile(vector<Worker> workers) {
    for(auto worker : workers)
        {

        }
    }
};


#endif //KURSACH_OOP_FILEWRITER_H
