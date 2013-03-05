#include <cstdlib>
#include <iostream>
#include "FsItemManager.h"
#include "Parser.h"

using namespace std;

int main(int argc, char *argv[])
{
    const char * dataFilePath = "..\\..\\data\\data-1.txt";
    if(argc >= 2)
    {
        dataFilePath = argv[1];
    }
    // ������ ���������� ������
    FsItemManager manager = FsItemManager();
    // ������ ������
    Parser parser = Parser();
    parser.setManager(&manager);
    parser.parse(dataFilePath);
    // ��������
    manager.print();
    system("pause");
    return EXIT_SUCCESS;
}
