#include "Parser.h"

Parser::Parser()
{
    manager = 0;
}

Parser::~Parser()
{
    //
}

void Parser::setManager(const FsItemManager * theManager)
{
    manager = (FsItemManager *)theManager;
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
    static vector<string> paths;
    int iSize = items.size(); 
    string path = "/";
    for (int i = 0; i <= count; ++i) {
        path += items[i];
        if (iSize != count || (iSize == count && itemType == FS_DIR)) {
            path += "/";
        }
    }
    for (int j = 0; j < paths.size(); ++j) {
        if (path == paths[j]) return;
    }
    paths.push_back(path);
    cout << path << endl;
    // build path, add if not exists else return
    FsItem * item = new FsItem();
    item->setName(items[count]);
    item->setPath(path);
    item->setType(itemType);
    item->setDepth(count);
    item->setSize(size);
    // add parent children
    //cout << item << endl;
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
