#include <cstdlib>
#include <iostream>
#include "Parser.h"
#include "Writer.h"

using namespace std;

void test();

int main(int argc, char *argv[])
{
    const char * dataFilePath = "..\\..\\data\\data-1.txt";
    if(argc >= 2)
    {
        dataFilePath = argv[1];
    }
    Parser parser = Parser();
    parser.parse(dataFilePath);
    Writer writer = Writer();
    writer.print();
    test();
    system("pause");
    return EXIT_SUCCESS;
}

// в окончательной версии - выпилить
void test()
{
    /*FsItem * o1 = new FsItem();
    o1->setName(string("folder 1"));
    FsItem * o2 = new FsItem();
    o2->setName(string("folder 2"));
    cout << o1 << o2 << endl;*/
    //read_file_to_vector();
}
