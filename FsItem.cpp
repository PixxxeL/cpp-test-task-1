#include "FsItem.h"

int FsItem::id_counter = 0;

ostream &operator<<(ostream &stream, FsItem o)
{
    stream << "[ FsItem: " << o.getName() << " ]" << endl;
    return stream;
}

ostream &operator<<(ostream &stream, FsItem * o)
{
    stream << "[ FsItem: " << o->getName() << " ]" << endl;
    return stream;
}

FsItem::FsItem()
{
    id = FsItem::id_counter++;
    //
}

FsItem::~FsItem()
{
    //
}

void FsItem::setName(const string theName)
{
    name = theName;
}

string FsItem::getName()
{
    return name;
}
