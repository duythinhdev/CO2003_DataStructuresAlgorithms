#include "main.h"
#define ACTION_REG "REG"

void simulate(string filename)
{
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



int countSpace(string command, string del) {
    int end = command.find(del);
    int count = 0;
    while (end != -1) {
        count++;
        command.erase(command.begin(), command.begin() + end + 1);
        end = command.find(del);
    }

    return count;
}

void clearCommandData(string *command) {
    int end = command->find(" ");
    command->erase(command->begin(), command->begin() + end + 1);
}