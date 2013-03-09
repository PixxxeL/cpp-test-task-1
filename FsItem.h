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
 * ����� - ������������� ���������� �������� ������� (���������� ��� ����)
 * �������� ������ � ASCII-���������� (� ������� ������ ������ ��� ����)
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
        // �������� �������
        int id;
        // ������� ����������� ���������� �� ����� (�� 0)
        int depth;
        // ������ ����� (���� ����)
        int size;
        // ��� (���������� ��� ����)
        int type;
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

#endif
