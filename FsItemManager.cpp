#include "FsItemManager.h"

FsItemManager::FsItemManager()
{
    //
}

FsItemManager::~FsItemManager()
{
    //
}

void FsItemManager::print()
{
    cout << "Print all items will be here..." << endl;
}

void FsItemManager::setRoot() // create overrided with defined item
{
    FsItem * item = new FsItem();
    item->setName("");
    item->setPath("/");
    item->setType(FS_DIR);
    item->setDepth(0);
    item->setSize(0);
    items.push_back(item);
}

FsItem * FsItemManager::getRoot()
{
    if (items.size() > 0)
    {
        return items[0];
    }
    return 0;
}

void FsItemManager::addPath(const string path)
{
    for (int i = 0; i < paths.size(); ++i) {
        if (path == paths[i]) return;
    }
    paths.push_back(path);
}
