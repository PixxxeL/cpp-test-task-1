#ifndef _PARSER_H
#define _PARSER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "FsItem.h"
#include "FsItemManager.h"

using namespace std;

class Parser
{
    public:
        Parser();
        ~Parser();
        void setManager(FsItemManager * theManager);
        void parse(const char * dataFilePath);
        static vector<string> split_string(const string &s, char delim);
        
    private:
        FsItemManager * manager;
        void _processLine(const string line);
        void _processItem(const vector<string> &items, int count, int size, int type);
        static vector<string> &_split_string(const string &s, char delim, vector<string> &elems);
};

#endif
