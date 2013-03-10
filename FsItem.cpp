#include "FsItem.h"

int FsItem::id_counter = 0;

ostream &operator<<(ostream &stream, FsItem o)
{
    int mode = o.getPrintMode();
    if (mode == PRINT_PARENT_CHILDREN_PATH) {
        o.printInfo(stream);
    }
    else if (mode == PRINT_FOR_TREE) {
        o.printTree(stream);
    }
    return stream;
}

ostream &operator<<(ostream &stream, FsItem * o)
{
    int mode = o->getPrintMode();
    if (mode == PRINT_PARENT_CHILDREN_PATH) {
        o->printInfo(stream);
    }
    else if (mode == PRINT_FOR_TREE) {
        o->printTree(stream);
    }
    return stream;
}

FsItem::FsItem()
{
    id = FsItem::id_counter++;
    parent = NULL;
    printMode = PRINT_FOR_TREE;
}

FsItem::~FsItem()
{
    parent = NULL;
    delete parent;
    children.clear();
}


int FsItem::getPrintMode()
{
    return printMode;
}


int FsItem::getId()
{
    return id;
}


void FsItem::setName(const string theName)
{
    name = theName;
}
string FsItem::getName()
{
    return name;
}


void FsItem::setPath(const string thePath)
{
    path = thePath;
}
string FsItem::getPath()
{
    return path;
}


void FsItem::setType(int theType)
{
    type = theType == FS_FILE ? FS_FILE : FS_DIR;
}
int FsItem::getType()
{
    return type;
}


void FsItem::setDepth(int theDepth)
{
    depth = theDepth;
}
int FsItem::getDepth()
{
    return depth;
}


void FsItem::setSize(int theSize)
{
    size = theSize;
}
int FsItem::getSize()
{
    return size;
}


void FsItem::setParent(FsItem * theParent)
{
    parent = theParent;
}
FsItem * FsItem::getParent()
{
    return parent;
}

void FsItem::addChild(FsItem * theChild)
{
    for (int i = 0; i < children.size(); ++i) {
        if (theChild == children[i]) return;
    }
    children.push_back(theChild);
}
vector<FsItem *> FsItem::getChildren()
{
    return children;
}

void FsItem::printInfo(ostream &stream)
{
    stream << "[ FsItem #" << id << ": " << path << " ]";
    if (parent) {
        stream << endl << "  parent:   " << parent->getPath();
    }
    if (children.size()) {
        stream << endl << "  children: " << endl;
        for (int i = 0; i < children.size(); ++i) {
            stream << "            " << children[i]->getPath() << endl;
        }
    }
}

void FsItem::printTree(ostream &stream)
{
    cout << setw(depth) << ' ' << name;
    sort(children.begin(), children.end(), _sortItems); // only for this! remove for other
    if (children.size()) {
        for (int i = 0; i < children.size(); ++i) {
            stream << endl << children[i];
        }
    }
}

bool _sortItems(FsItem * a, FsItem * b)
{
    int aType = a->getType(),
        bType = b->getType(),
        aSize = a->getSize(),
        bSize = b->getSize();
    string aName = a->getName(),
        bName = b->getName();
    // сначала директории
    if (aType != bType) {
        return aType < bType;
    }
    // директории по имени
    if (aType == FS_DIR && bType == FS_DIR) {
        return aName < bName;
    }
    // файлы сначала по размеру
    if (aType == FS_FILE && bType == FS_FILE && aSize != bSize) {
        return aSize < bSize;
    }
    return aName < bName;
}
