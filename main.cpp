#include <cstdlib>
#include <iostream>
#include "read_file_to_vector.h"
#include "FsItem.h"
#include "Parser.h"
#include "Writer.h"

using namespace std;

void test();

int main(int argc, char *argv[])
{
    Parser parser = Parser();
    //parser.parse(argv);
    Writer writer = Writer();
    //writer.print();
    test();
    system("pause");
    return EXIT_SUCCESS;
}

// в окончательной версии - выпилить
void test()
{
    FsItem * o = new FsItem();
    o->setName(string("asdasd"));
    cout << o << endl;
    //read_file_to_vector();
}
