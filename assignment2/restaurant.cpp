#include "main.h"

#define ACTION_REG "REG"
#define ACTION_CLE "CLE"
#define ACTION_PRINT_AVL ""
#define STR_NULL " "

void reg(string command);
void clearCommandData(string *line);

void simulate(string filename)
{
    string line;
    ifstream myfile(filename);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            int end = line.find(STR_NULL);
            string commandName = string(line.substr(0, end));
            clearCommandData(&line);
            if (commandName == ACTION_REG) {
                reg(line);
            }
        }
        myfile.close();
    }
	return;
}


void reg(string command) {
    string name;
    name = command.substr(0, command.find(" "));
    clearCommandData(&command);
    cout << name << endl;
}


void clearCommandData(string *command) {
    int end = command->find(" ");
    command->erase(command->begin(), command->begin() + end + 1);
}