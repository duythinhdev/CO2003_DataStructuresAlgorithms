#include "main.h"

#define ACTION_REG "REG"
#define STR_NULL " "

void reg(string command,restaurant* r);
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
                reg(line, r);
            }
//        }
        myfile.close();
    }
}

void reg(string command, restaurant* r){
    string name;
    int id;
    int age;
    if(countSpace(command," ") == 2) {
        // has id
        id = stoi(command.substr(0, command.find(" ")));
        clearCommandData(&command);
        name = command.substr(0, command.find(" "));
        clearCommandData(&command);
        age = stoi(command.substr(0, command.find(" ")));
        table* last = r->recentTable;
        while(last != r->recentTable->next) {
            r->recentTable = r->recentTable->next;
            if(r->recentTable->ID == id){
                r->recentTable->name = name;
                r->recentTable->age = age;
            }
            else if(r->recentTable->ID != id && r->recentTable->ID >= id && r->recentTable->name == ""){
                r->recentTable->name = name;
                r->recentTable->age = age;
                return;
            }
        }
    }else{
        name = command.substr(0, command.find(" "));
        clearCommandData(&command);
        age = stoi(command.substr(0, command.find(" ")));
        table* last = r->recentTable;
        while(last != r->recentTable->next) {
            r->recentTable = r->recentTable->next;
            if(r->recentTable->name == ""){
                r->recentTable->name = name;
                r->recentTable->age = age;
                return;
            }
        }
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
    command->erase(command->begin(), command->begin() + end + 1);
}