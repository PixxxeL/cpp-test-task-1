#include "read_file_to_vector.h"

vector<string> read_file_to_vector()
{
    vector<string> vDataLines;
    ifstream fs(DATA_FILE_PATH.c_str());
    if (!fs)
    {
        cout << "Error opening " << DATA_FILE_PATH << " file!" << endl;
        return vDataLines;
    }
    
    cout << "Begin reading file..." << endl;
    // этот вариант, если в файле точно все строки заполнены
    string buff;
    while (getline(fs, buff))
    {
        cout << buff << endl;
        vDataLines.push_back(buff);
    }
    /*// этот вариант, если в файле будут незаполненные строки
    char buff[500];
    while(!fs.eof()) {
		fs.getline(buff, 500);
        cout << buff << endl;
		vDataLines.push_back(string(buff));
	}*/
    fs.close();
    return vDataLines;
}
