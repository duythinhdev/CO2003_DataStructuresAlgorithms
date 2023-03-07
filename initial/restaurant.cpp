#include "main.h"

void reg(string* command);
string* find_str(string s,string del);
int size(string* s);

void simulate(string filename, restaurant* r)
{

    string line;
    ifstream myfile(filename);
    if (myfile.is_open())
    {
        while (getline(myfile, line)) {
            //get command
            string* command = find_str(line, " ");
            if(command[0] == "REG"){
                reg(command);
            }
        }
        myfile.close();
    }
}
void reg(string* command){
    cout<<size(command);
    if(size(command) == 4){
        // co id
    }
}
int size(string* command){
    int count = 0;
    for(int i = 0; i < 5;i ++){
        if(!command[i].empty()){
            count++;
        }
    }
    return count;
}
string* find_str(string s, string del) {
    int end = s.find(del);
    string* array = new string[5];
    int index = 0;
    while (end != -1) {
        array[index] = string(s.substr(0, end));
        index++;
        s.erase(s.begin(), s.begin() + end + 1);
        end = s.find(del);
    }

    array[index] =  string(s.substr(0, end));
    return array;
}
