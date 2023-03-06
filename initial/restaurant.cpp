#include "main.h"

void reg(int i, string basicString, int i1);

void simulate(string filename, restaurant* r)
{

    string line;
    ifstream myfile(filename);
    if (myfile.is_open())
    {
        while (getline(myfile, line)) {
            cout << line.substr(0, 4);
            string command = line.substr(0, 4);
            if(command == "REG"){
//                string name = "asd";
//                reg(1, name, 1);
            }
            cout << line << '\n';
        }
        myfile.close();
    }
}
