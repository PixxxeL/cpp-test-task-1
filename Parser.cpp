#include "Parser.h"

Parser::Parser()
{
    manager = NULL;
}

Parser::~Parser()
{
    manager = NULL;
    delete manager;
}

void Parser::setManager(FsItemManager * theManager)
{
    manager = theManager;
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
    int itemType = FS_DIR;
    int fileSize = 0;
    if(partsSize < 1)
    {
        return;
    }
    // определяем тип последнего элемента
    else if(partsSize == 2)
    {
        itemType = FS_FILE;
        istringstream ss(parts[1]);
        ss >> fileSize;
    }
    vector<string> items = Parser::split_string(parts[0], '\\');
    for (int i = 0; i < items.size(); ++i)
    {
        Parser::_processItem(items, i, fileSize, itemType);
    }
}

void Parser::_processItem(const vector<string> &items, int count, int size, int itemType)
{
    int iSize = items.size();
    string path = "/";
    int segType = FS_DIR;
    
    for (int i = 0; i <= count; ++i) {
        path += items[i];
        if (i == count && iSize - 1 == count && itemType == FS_FILE) {
            segType = FS_FILE;
        }
        else {
            path += "/";
        }
    }
    if (!manager->addPath(path)) {
        return;
    }
    
    if (segType != FS_FILE) {
        size = 0;
    }
    
    FsItem * item = new FsItem();
    item->setName(items[count]);
    item->setPath(path);
    item->setType(segType);
    item->setDepth(count + 1);
    item->setSize(size);
    
    manager->addFsItem(item);
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
