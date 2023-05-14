#include "main.h"

#define ACTION_REG "REG"
#define ACTION_CLE "CLE"
#define ACTION_PRINT_HT "PrintHT"
#define MAX_TREE_HT 50
#define STR_NULL " "

void reg(string command);
void cle(string command);
void printHT();
void clearCommandData(string *line);
int buildArrayWithFrequency(string name, int (&newArray)[100]);
void HuffmanCodes(char item[], int freq[], int size, string* binary);
int binaryToDecimal(long long binary);
void handleSea(string name,int id);
void handleMountain(string name,int id);

struct MinHNode {
    int freq;
    char item;
    struct MinHNode *left, *right;
};
struct MinH {
    int size;
    int capacity;
    struct MinHNode **array;
};
struct DataItem {
    string data;
    int key;
};

DataItem* hashTable[MAXSIZE / 2];
int hashCode(int key) {
    return key % (MAXSIZE / 2);
}
void insert(int key,string data, int hashIndex){
//    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
    DataItem item;
    item.data = data;
    item.key = key;
//    int hashIndex = hashCode(key);
//    if (hashIndex > MAXSIZE /2) {
//        return;
//    }
    while(hashIndex < MAXSIZE /2 && hashTable[hashIndex] != NULL && hashTable[hashIndex]->key != -1){
        ++hashIndex;
        hashIndex %= MAXSIZE;
    }

    hashTable[hashIndex] = &item;
}
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
            if (commandName == ACTION_CLE) {
                cle(line);
            }
            if (commandName == ACTION_PRINT_HT) {
                printHT();
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
    int newArray[100] = {0};
    int size = buildArrayWithFrequency(name,newArray);

    int j = 0;
    char arr[size];
    int arrFreq[size];
    for(int i = 0 ; i < 100;i++){
        if(newArray[i] > 0){
            arr[j] = char(i + 'A');
            arrFreq[j] = newArray[i];
            j++;
        }
    }
    string binary = "";
    HuffmanCodes(arr,arrFreq,size,&binary);
    string newBinary = "";
    int count = 16;
    for(int i = binary.size(); i > 0 ;i--){
        if(count == 0){
            break;
        }else {
            newBinary = binary[i] + newBinary;
        }
        count--;
    }
    long long binaryDecimal = stoll(newBinary);
    int result = binaryToDecimal(binaryDecimal);
    int id = result % MAXSIZE + 1;
    if(result % 2 == 0){
        cout<<id<<"-"<<result<<"-"<<2<<endl;
        handleMountain(name,result);
    }else {
        cout<<id<<"-"<<result<<"-"<<1<<endl;
        handleSea(name,result);
    }

}
void handleSea(string name,int result){
    int hashTableIndex = hashCode(result);
    insert(result,name,hashTableIndex);
}
void handleMountain(string name,int result){

}
void cle(string command){
//    int num;
//    num = stoi(command.substr(0, command.find(" ")));
//    if(num < 1){
//        for(int i = 0; i < MAXSIZE / 2;i++){
//            hashTable[i] = nullptr;
//        }
//        return;
//    }
}
void printHT(){
    for(int i = 0; i < MAXSIZE / 2;i++){
        if (hashTable[i] != NULL) {
            cout<< i << "-" << hashTable[i]->key << endl;
        }
    }
}
struct MinHNode *newNode(char item, int freq) {
    struct MinHNode *temp = (struct MinHNode *)malloc(sizeof(struct MinHNode));

    temp->left = temp->right = NULL;
    temp->item = item;
    temp->freq = freq;

    return temp;
}

struct MinH *createMinH(int capacity) {
    struct MinH *minHeap = (struct MinH *)malloc(sizeof(struct MinH));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHNode **)malloc(minHeap->capacity * sizeof(struct MinHNode *));
    return minHeap;
}
//void printArray(int arr[], int n) {
//    int i;
//    for (i = 0; i < n; ++i)
//        cout << arr[i];
//    cout << "\n";
//}
void swapMinHNode(struct MinHNode **a, struct MinHNode **b) {
    struct MinHNode *t = *a;
    *a = *b;
    *b = t;
}
void minHeapify(struct MinH *minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHNode(&minHeap->array[smallest],
                     &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int checkSizeOne(struct MinH *minHeap) {
    return (minHeap->size == 1);
}

struct MinHNode *extractMin(struct MinH *minHeap) {
    struct MinHNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

// Insertion
void insertMinHeap(struct MinH *minHeap, struct MinHNode *minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinH *minHeap) {
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

int isLeaf(struct MinHNode *root) {
    return !(root->left) && !(root->right);
}

struct MinH *createAndBuildMinHeap(char item[], int freq[], int size) {
    struct MinH *minHeap = createMinH(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(item[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

struct MinHNode *buildHfTree(char item[], int freq[], int size) {
    struct MinHNode *left, *right, *top;
    struct MinH *minHeap = createAndBuildMinHeap(item, freq, size);

    while (!checkSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}
void printHCodes(struct MinHNode *root, int arr[], int top,string* binary) {
    if (root->left) {
        arr[top] = 0;
        printHCodes(root->left, arr, top + 1, binary);
    }

    if (root->right) {
        arr[top] = 1;
        printHCodes(root->right, arr, top + 1,binary);
    }
    if (isLeaf(root)) {
        int i;
        for (i = 0; i < top; ++i)
           *binary += std::to_string(arr[i]);
    }
}

void HuffmanCodes(char item[], int freq[], int size,string *binary) {
    struct MinHNode *root = buildHfTree(item, freq, size);

    int arr[MAX_TREE_HT], top = 0;
    printHCodes(root, arr, top, binary);
}


int buildArrayWithFrequency(string name, int (&newArray)[100]){
    int size = 0;
    const char* names = name.c_str();
    int length = strlen(names);
    for(int i = 0; i < length;i++){
        if (newArray[name[i] - 'A'] == 0){
            size += 1;
        }
        newArray[name[i] - 'A']++;
    }
    return size;
}

int binaryToDecimal(long long n)
{
    long long num = n;
    int dec_value = 0;

    int base = 1;

    long long temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    return dec_value;
}
void clearCommandData(string *command) {
    int end = command->find(" ");
    command->erase(command->begin(), command->begin() + end + 1);
}