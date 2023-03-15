#include "main.h"

#define ACTION_REG "REG"
#define ACTION_REGM "REGM"
#define ACTION_CLE "CLE"
#define ACTION_PS "PS"
#define STR_NULL " "

class Node {
public:
    string data;
    Node *next;

    Node(string data) {
        this->data = data;
        next = nullptr;
    }
};

class Queue {
private:
    Node *front;
    Node *rear;
public:
    Queue() {
        front = rear = nullptr;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Add an element to the back of the queue
    void enqueue(string data) {
        Node *newNode = new Node(data);
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
        Node *temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    // Get the front element of the queue
    string peek() {
        if (isEmpty()) {
//            cout << "Queue is empty!" << endl;
//            return -1;
        }
        return front->data;
    }

    // Print the queue
    void print() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node *temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void reg(string command, restaurant *r, Queue *pQueue);

table *regm(string command, restaurant *r);

void cle(string command, restaurant *r, table *t, table *singleLastTable);

int countSpace(string s, string del);

void clearCommandData(string *line);

void ps(string command, restaurant *r);

void simulate(string filename, restaurant *r) {
    Queue queue;
    string line;
    table *mergeTable;
    table *singleLastTable;
    ifstream myfile(filename);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            int end = line.find(STR_NULL);
            string commandName = string(line.substr(0, end));
            clearCommandData(&line);
            //line.erase(line.begin(), line.begin() + end + 1);
            if (commandName == ACTION_REG) {
                reg(line, r, &queue);
            }
            if (commandName == ACTION_REGM) {
                mergeTable = regm(line, r);
                singleLastTable = r->recentTable;
            }
            if (commandName == ACTION_CLE) {
                cle(line, r, mergeTable, singleLastTable);
            }
            if(commandName == ACTION_PS){
                ps(line, r);
            }

        }
        myfile.close();
    }
}

void reg(string command, restaurant *r, Queue *q) {
    string name;
    int id;
    int age;
    table *currentTable;
    string cloneCommand = command;
    if (countSpace(command, " ") == 2) {
        // has id
        id = stoi(command.substr(0, command.find(" ")));
        clearCommandData(&command);
        name = command.substr(0, command.find(" "));
        clearCommandData(&command);
        age = stoi(command.substr(0, command.find(" ")));
        table *last = r->recentTable;
        while (last != r->recentTable->next) {
            r->recentTable = r->recentTable->next;
            if (r->recentTable->name == "" && r->recentTable->ID == id) {
                r->recentTable->name = name;
                r->recentTable->age = age;
                return;
            }
            if (r->recentTable->ID == id) {
                currentTable = r->recentTable;
                break;
            }
        }
        int count = 1;
        while (currentTable != r->recentTable->next) {
            r->recentTable = r->recentTable->next;
            if (r->recentTable->name == "") {
                r->recentTable->name = name;
                r->recentTable->age = age;
                return;
            }
            count++;
            if (count == MAXSIZE) {
                q->enqueue(cloneCommand);
            }
        }
    } else {
        int count = 0;
        name = command.substr(0, command.find(" "));
        clearCommandData(&command);
        age = stoi(command.substr(0, command.find(" ")));
        table *last = r->recentTable;
        while (last != r->recentTable->next) {
            count++;
            r->recentTable = r->recentTable->next;
            if (r->recentTable->name == "") {
                r->recentTable->name = name;
                r->recentTable->age = age;
                return;
            }
        }
        if (count == MAXSIZE) {
            q->enqueue(cloneCommand);
        }
        // don't has id
    }
}

table *regm(string command, restaurant *r) {
    string name;
    int age;
    int num;
    name = command.substr(0, command.find(" "));
    clearCommandData(&command);
    age = stoi(command.substr(0, command.find(" ")));
    clearCommandData(&command);
    num = stoi(command.substr(0, command.find(" ")));
    int count = 0;
    int countPrev = 0;
    int countLoop = 0;
    table *last = r->recentTable;
    table *last2 = r->recentTable;
    table *mergeHeadTable = nullptr;
    table *mergeLastTable = nullptr;
    table *singleHeadTable = nullptr;
    table *singleLastTable = nullptr;
    if (last->name == "") {
        // moi vo ban trong dau thi dem luon
        count = 1;
        // moi vo ban trong dau thi dem prev
        countPrev = 1;
    }
    while (last != r->recentTable->next && countLoop < 2) {
        r->recentTable = r->recentTable->next;
        if(r->recentTable == last){
            // qua qua lan 2 den thang 3
            countLoop++;
        }
        countPrev++;
        if(countPrev >= num){
            // tim thang so 4
            last2 = last2->next;
            mergeHeadTable = last2;
        }
        // count ban trong
        if(r->recentTable->name != ""){
            count = 0;
        }else {
            count++;
        }
        if (count == num) {
            // tim toi 7
            mergeLastTable  = r->recentTable;
            break;
        }
    }
    if(count == num) {
        while(mergeHeadTable != r->recentTable->next) {
            r->recentTable = r->recentTable->next;
        }
        singleLastTable = r->recentTable;
        // 7 qua 4
        singleHeadTable = mergeLastTable->next;
        mergeLastTable->next = mergeHeadTable;
        // 3 qua 1
        singleLastTable->next = singleHeadTable;
        while(mergeLastTable != mergeHeadTable){
            mergeHeadTable->name = name;
            mergeHeadTable->age = age;
            mergeHeadTable = mergeHeadTable->next;
        }
        mergeLastTable->name = name;
        mergeLastTable->age = age;
        // tra ve ban chua gop
        r->recentTable = singleLastTable;
        return mergeLastTable;
    }
    return nullptr;
}

void cle(string command, restaurant *r,table *mergeTable, table *singleLastTable) {
    int id;
    id = stoi(command.substr(0, command.find(" ")));
    table* temp = r->recentTable->next;
    while(r->recentTable != temp){
        temp = temp->next;
        if (temp->ID == id) {
            temp->name = "";
            temp->age = 0;
            return;
        }
    }

    table *last = mergeTable;
    bool isExist = false;
    while (last != mergeTable->next) {
        mergeTable = mergeTable->next;
        if(mergeTable->ID == id){
            isExist = true;
            break;
        }
    }
    mergeTable = mergeTable->next;
    if(isExist){
        while(last != mergeTable->next){
            mergeTable->name = "";
            mergeTable->age = 0;
            mergeTable = mergeTable->next;
        }
        mergeTable->name = "";
        mergeTable->age = 0;
        // merge
        table *mergeHeadTable = last->next;
        table *mergeLastTable = last;
        table *singleHeadTable = singleLastTable->next;
        singleLastTable->next = mergeHeadTable;
        mergeLastTable->next = singleHeadTable;
        r->recentTable = mergeLastTable;
    }
}
void ps(string command, restaurant *r){
    int id;
    id = stoi(command.substr(0, command.find(" ")));
    table* last = r->recentTable;
    restaurant* currentRestaurant = new restaurant();
    while(last != r->recentTable->next){
    }

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
