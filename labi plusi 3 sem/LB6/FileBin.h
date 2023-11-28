#ifndef LB6_FILEBIN_H
#define LB6_FILEBIN_H

#include "File.h"
#include <iostream>
#include <fstream>
#include "MyContainer.h"
#include "Example.h"

using namespace std;

class FileBin : public File{

public:

    void WriteToBinFile(List<Person> &person){

        string Path = "File.bin";

        fstream out(Path,  ios::binary  | ios::app );

        if (out.is_open())
        {
            for (int i = 0; i < person.size(); i++)
            {
                out.write((char*)&person[i], sizeof(person[i]));
            }
        }
        else
            out.close();
    }

    void ShowBinFile(){

        Person x;
        string Path = "File.bin";

        ifstream fin;

        fin.open(Path , ios::binary | ios::out);

        List<Person> person;

        if (fin.is_open())
        {
            while ( fin.read((char*)&x, sizeof(x))){
                person.push(x);
            }
        }
        else
            fin.close();

        for (int i = 0; i < person.size(); ++i) {
            person[i].PrintPerson();
        }
    }
};

#endif //LB6_FILEBIN_H
