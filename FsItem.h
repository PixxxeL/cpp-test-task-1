#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const string FS_DIR = "FS_DIR";
const string FS_FILE = "FS_FILE";

/**
 * ����� - ������������� ���������� �������� ������� (���������� ��� ����)
 * �������� ������ � ASCII-���������� (� ������� ������ ������ ��� ����)
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
        // �������� �������
        int id;
        // ������� ����������� ���������� �� ����� (�� 0)
        int depth;
        // ������ ����� (���� ����)
        int size;
        // ��� (���������� ��� ����)
        string type;
        // ��� ���������� ��� �����
        string name;
        // ������ ���� �� ����� (���� ���������� - ��������� /)
        string path;
        // ������������ �����
        FsItem * parent;
        // �������� ����������
        vector<FsItem *> children;
        // ������� ���������������
        static int id_counter;
};
