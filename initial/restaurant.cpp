#include "main.h"

#define ACTION_REG "REG"
#define STR_NULL " "

void reg(string command);
int countSpace(string s, string del);
void clearCommandData(string* line);
void simulate(string filename, restaurant* r)
{

    string line;
    ifstream myfile(filename);
    if (myfile.is_open())
    {
//        while (getline(myfile, line)) {
            getline(myfile, line);
            int end = line.find(STR_NULL);
            string commandName = string(line.substr(0, end));
            clearCommandData(&line);
            //line.erase(line.begin(), line.begin() + end + 1);
            if(commandName == ACTION_REG){
                reg(line);
            }
//        }
        myfile.close();
    }
}

void reg(string command){
    string name;
    string id;
    string age;
    if(countSpace(command," ") == 2) {
        // has id
        id = command.substr(0, command.find(" "));
        clearCommandData(&command);
        name = command.substr(0, command.find(" "));
        clearCommandData(&command);
        age = command.substr(0, command.find(" "));
    }else{
        name = command.substr(0, command.find(" "));
        clearCommandData(&command);
        age = command.substr(0, command.find(" "));
         // don't has id
    }
}
int countSpace(string command, string del){
    int end = command.find(del);
    int count = 0;
    while (end != -1) {
        count++;
        command.erase(command.begin(), command.begin() + end + 1);
        end = command.find(del);
    }

    return count;
}
void clearCommandData(string* command){
    int end = command->find(" ");
    command->erase(command->begin(), command->begin() + end + 1);\
}