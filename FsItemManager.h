#ifndef _FS_ITEM_MANAGER_H
#define _FS_ITEM_MANAGER_H

#include <iostream>
#include <vector>
#include "FsItem.h"

using namespace std;

class FsItemManager
{
    public:
        FsItemManager();
        ~FsItemManager();
        void print();
        bool addPath(const string path);
        void addFsItem(FsItem * item);
        void setRoot();
        FsItem * getRoot();
    protected:
        vector<string> paths;
        vector<FsItem *> items;
};

#endif
