#include "main.h"

#define ACTION_REG "REG"
#define ACTION_REGM "REGM"
#define ACTION_CLE "CLE"
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

void cle(string command, restaurant *r);

int countSpace(string s, string del);

void clearCommandData(string *line);

void simulate(string filename, restaurant *r) {
    Queue queue;
    string line;
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
                regm(line, r);
            }
            if (commandName == ACTION_CLE) {
                cle(line, r);
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
        name = command.substr(0, command.find(" "));
        clearCommandData(&command);
        age = stoi(command.substr(0, command.find(" ")));
        table *last = r->recentTable;
        while (last != r->recentTable->next) {
            r->recentTable = r->recentTable->next;
            if (r->recentTable->name == "") {
                r->recentTable->name = name;
                r->recentTable->age = age;
                return;
            }
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
    table *prev = nullptr;
    table *temp = nullptr;
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
            prev = last2;
        }
        // count ban trong
        r->recentTable->name != "" ? count = 0 :  count++;
        if (count == num) {
            // tim toi 7
            temp  = r->recentTable;
            break;
        }
    }
    if(count == num){
        while(prev != r->recentTable->next) {
            r->recentTable = r->recentTable->next;
        }

        // 7 qua 4
        table *head = temp->next;
        temp->next = prev;
        // 3 qua 1
        r->recentTable->next = head;
        // tra ve ban chua gop
        return r->recentTable;
    }
    return nullptr;
}

void cle(string command, restaurant *r) {
    int id;
    id = stoi(command.substr(0, command.find(" ")));
    table *last = r->recentTable;
    while (last != r->recentTable->next) {
        if (r->recentTable->ID == id) {
            r->recentTable->name = "";
            r->recentTable->age = 0;
        }
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
