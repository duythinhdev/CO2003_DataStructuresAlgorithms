#include "main.h"

#define ACTION_REG "REG"
#define ACTION_REGM "REGM"
#define ACTION_CLE "CLE"
#define STR_NULL " "

void reg(string command,restaurant* r);
void regm(string command,restaurant* r);
int countSpace(string s, string del);
void clearCommandData(string* line);

void simulate(string filename, restaurant* r)
{

    string line;
    ifstream myfile(filename);
    if (myfile.is_open())
    {
        while (getline(myfile, line)) {
            int end = line.find(STR_NULL);
            string commandName = string(line.substr(0, end));
            clearCommandData(&line);
            //line.erase(line.begin(), line.begin() + end + 1);
            if(commandName == ACTION_REG){
                reg(line, r);
            }
            if(commandName == ACTION_REGM){
                regm(line, r);
            }
        }
        myfile.close();
    }
}

void reg(string command, restaurant* r){
    string name;
    int id;
    int age;
    table* currentTable;
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
            if(r->recentTable->name == "" && r->recentTable->ID == id){
                r->recentTable->name = name;
                r->recentTable->age = age;
                return;
            }
            if(r->recentTable->ID == id){
                currentTable = r->recentTable;
                break;
            }
        }
        while(currentTable != r->recentTable->next){
            r->recentTable = r->recentTable->next;
            if(r->recentTable->name == ""){
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
void regm(string command, restaurant* r){
    string name;
    int age;
    int num;
    name = command.substr(0, command.find(" "));
    clearCommandData(&command);
    age = stoi(command.substr(0, command.find(" ")));
    clearCommandData(&command);
    num = stoi(command.substr(0, command.find(" ")));
    int count = 0;
    table* last = r->recentTable;
    table* prev = nullptr;
    while(last != r->recentTable->next){
        count++;
        if(r->recentTable->name == "" && count == num){

        }
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

// Node class for linked list
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

// Queue class implemented using linked list
class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = rear = nullptr;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Add an element to the back of the queue
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // Remove an element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    // Get the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Print the queue
    void print() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
