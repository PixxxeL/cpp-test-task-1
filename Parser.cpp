#include "Parser.h"

Parser::Parser()
{
    //
}

Parser::~Parser()
{
    //
}

void Parser::parse(const char * dataFilePath)
{
    ifstream fs(dataFilePath);
    if (!fs)
    {
        cout << "Error opening " << dataFilePath << " file!" << endl;
    }
    
    cout << "Begin reading file..." << endl;
    // этот вариант, если в файле точно все строки заполнены
    string line;
    while (getline(fs, line))
    {
        //cout << line << endl;
        _processLine(line);
    }
    fs.close();
}

void Parser::_processLine(const string line)
{
    vector<string> parts = Parser::split_string(line, ' ');
    int partsSize = parts.size();
    bool isFile = false;
    int fileSize = 0;
    if(partsSize < 1)
    {
        return;
    }
    // определяем тип последнего элемента
    else if(partsSize == 2)
    {
        isFile = true;
        istringstream ss(parts[1]);
        ss >> fileSize;
    }
    vector<string> items = Parser::split_string(parts[0], '\\');
    vector<string>::iterator itemsIt = items.begin();
    while(itemsIt != items.end())
    {
        // no info about path!
        Parser::_processItem(*itemsIt, fileSize, isFile);
        itemsIt++;
    }
}

void Parser::_processItem(const string name, int size, bool isFile)
{
    //cout << isFile << " " << name << " " << size << endl;
}

vector<string> &Parser::_split_string(const string &s, char delim, vector<string> &parts)
{
    stringstream ss(s);
    string part;
    while(getline(ss, part, delim)) 
    {
        parts.push_back(part);
    }
    return parts;
}


vector<string> Parser::split_string(const string &s, char delim)
{
    vector<string> parts;
    return Parser::_split_string(s, delim, parts);
}
