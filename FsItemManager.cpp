#include "FsItemManager.h"

FsItemManager::FsItemManager()
{
    //
}

FsItemManager::~FsItemManager()
{
    paths.clear();
    items.clear();
}

void FsItemManager::print()
{
    cout << "And output tree..." << endl;
    const char * resultFilePath = "data\\result-1.txt";
    ofstream fs(resultFilePath);
    if (!fs) {
        cout << "Error opening " << resultFilePath << " file!" << endl;
    }
    if (items.size()) {
        fs << items[0] << endl;
        //cout << items[0] << endl;
    }
    fs.close();
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

bool FsItemManager::addPath(const string path)
{
    for (int i = 0; i < paths.size(); ++i) {
        if (path == paths[i]) {
            return false;
        }
    }
    paths.push_back(path);
    return true;
}

void FsItemManager::addFsItem(FsItem * item)
{
    items.push_back(item);
}

void FsItemManager::addFsItem(FsItem * item, const string prePath)
{
    FsItem * preItem = NULL;
    for (int i = 0; i < items.size(); ++i) {
        FsItem * candidate = items[i];
        if (prePath == candidate->getPath()) {
            preItem = candidate;
            break;
        }
    }
    if (preItem != NULL) {
        item->setParent(preItem);
        preItem->addChild(item);
        items.push_back(item);
    }
}
