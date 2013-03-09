#include "FsItem.h"

int FsItem::id_counter = 0;

ostream &operator<<(ostream &stream, FsItem o)
{
    stream << "[ FsItem #" << o.getId() << ": " << o.getPath() << " ]" << endl;
    return stream;
}

ostream &operator<<(ostream &stream, FsItem * o)
{
    stream << "[ FsItem #" << o->getId() << ": " << o->getPath() << " ]" << endl;
    /*stream << "  parent:   " << o->getParent() << endl;
    stream << "  children: " << endl;
    vector<FsItem *> ch = o->getChildren();
    for (int i = 0; i < ch.size(); ++i) {
        stream << "            " << ch[i] << endl;
    }*/
    return stream;
}

FsItem::FsItem()
{
    id = FsItem::id_counter++;
    parent = 0;
}

FsItem::~FsItem()
{
    /*delete name;
    delete path;
    delete parent;
    delete children;*/
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
    //sort();
}
vector<FsItem *> FsItem::getChildren()
{
    return children;
}
