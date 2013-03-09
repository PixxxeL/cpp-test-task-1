#ifndef _FS_ITEM_H
#define _FS_ITEM_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int FS_DIR  = 1;
const int FS_FILE = 2;

/**
 * Класс - представитель компоненты файловой системы (директория или файл)
 * Работает только с ASCII-названиями (в задании ничего небыло про иное)
 */
class FsItem
{
    public:
        FsItem();
        ~FsItem();
        int getId();
        void setName(const string theName);
        string getName();
        void setPath(const string thePath);
        string getPath();
        void setType(int theType);
        int getType();
        void setDepth(int theDepth);
        int getDepth();
        void setSize(int theSize);
        int getSize();
        void setParent(FsItem * theParent);
        FsItem * getParent();
        void addChild(FsItem * theChild);
        vector<FsItem *> getChildren();
        /*void addChildren(vector<FsItem *> theChildren);*/
        friend ostream &operator<<(ostream &stream, FsItem o);
        friend ostream &operator<<(ostream &stream, FsItem * o);
    
    protected:
        // сквозной сиквенс
        int id;
        // уровень вложенности компоненты от корня (от 0)
        int depth;
        // размер файла (если файл)
        int size;
        // тип (директория или файл)
        int type;
        // имя директории или файла
        string name;
        // полный путь от корня (если директория - завершаем /)
        string path;
        // родительская папка
        FsItem * parent;
        // дочерние компоненты
        vector<FsItem *> children;
        // счетчик идентификаторов
        static int id_counter;
};

#endif
