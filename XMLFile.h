#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class XMLFile
{

const string FILE_NAME;

public:

    XMLFile(string fileName) : FILE_NAME(fileName) {}

    string getFileName()
    {
        return FILE_NAME;
    }

    bool isFileEmpty()
    {
        bool isEmpty = true;
        fstream xmlFile;
        xmlFile.open(getFileName().c_str(), ios::app);

        if (xmlFile.good() == true)
        {
            xmlFile.seekg(0, ios::end);
            if (xmlFile.tellg() != 0)
                isEmpty = false;
        }

        xmlFile.close();
        return isEmpty;
    }
};

#endif
