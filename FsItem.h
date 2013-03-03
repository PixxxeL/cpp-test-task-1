#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const string FS_DIR = "FS_DIR";
const string FS_FILE = "FS_FILE";

/**
 * Класс - представитель компоненты файловой системы (директория или файл)
 * Работает только с ASCII-названиями (в задании ничего небыло про иное)
 */
class FsItem
{
    public:
        FsItem();
        ~FsItem();
        void setName(const string theName);
        string getName();
        friend ostream &operator<<(ostream &stream, FsItem o);
        friend ostream &operator<<(ostream &stream, FsItem * o);
        /*void setParent(const FsItem * theParent);
        FsItem * getParent();
        void addChild(const FsItem * theChild);
        void addChildren(const vector<FsItem *> theChildren);
        int getID();
        string getPath();
        void setType(const string theType);
        string getType();
        void setDepth(int theDepth);
        int getDepth();
        void setSize(int theSize);
        int getSize();*/
    
    protected:
        // сквозной сиквенс
        int id;
        // уровень вложенности компоненты от корня (от 0)
        int depth;
        // размер файла (если файл)
        int size;
        // тип (директория или файл)
        string type;
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
