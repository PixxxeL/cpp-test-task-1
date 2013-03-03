#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "FsItem.h"

using namespace std;

class Parser
{
    public:
        Parser();
        ~Parser();
        void parse(const char * dataFilePath);
        vector<string> split_string(const string &s, char delim);
        
    private:
        void _processLine(const string line);
        void _processItem(const string name, int size, bool isFile);
        vector<string> &_split_string(const string &s, char delim, vector<string> &elems);
};
