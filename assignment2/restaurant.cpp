#include "main.h"

#define ACTION_REG "REG"
#define ACTION_CLE "CLE"
#define ACTION_PRINT_AVL ""
#define MAX_TREE_HT 50
#define STR_NULL " "
#define CAPACITY 50000

void reg(string command);
void clearCommandData(string *line);
int buildArrayWithFrequency(string name, int (&newArray)[100]);
void HuffmanCodes(char item[], int freq[], int size, string* binary);
int binaryToDecimal(long long binary);
void handleSea(string name,int id);
void handleMountain(string name,int id);

struct MinHNode {
    unsigned freq;
    char item;
    struct MinHNode *left, *right;
};

struct MinH {
    unsigned size;
    unsigned capacity;
    struct MinHNode **array;
};
unsigned long hash_function(char *str)
{
    unsigned long i = 0;

    for (int j = 0; str[j]; j++)
        i += str[j];

    return i % CAPACITY;
}
// Defines the HashTable item.
typedef struct Ht_item
{
    char *key;
    char *value;
} Ht_item;

// Defines the LinkedList.
typedef struct LinkedList
{
    Ht_item *item;
    LinkedList *next;
} LinkedList;

// Defines the HashTable.
typedef struct HashTable
{
    // Contains an array of pointers to items.
    Ht_item **items;
    LinkedList **overflow_buckets;
    int size;
    int count;
} HashTable;

LinkedList *allocate_list()
{
    // Allocates memory for a LinkedList pointer.
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    return list;
}

LinkedList *linkedlist_insert(LinkedList *list, Ht_item *item)
{
    // Inserts the item onto the LinkedList.
    if (!list)
    {
        LinkedList *head = allocate_list();
        head->item = item;
        head->next = NULL;
        list = head;
        return list;
    }
    else if (list->next == NULL)
    {
        LinkedList *node = allocate_list();
        node->item = item;
        node->next = NULL;
        list->next = node;
        return list;
    }

    LinkedList *temp = list;

    while (temp->next->next)
    {
        temp = temp->next;
    }

    LinkedList *node = allocate_list();
    node->item = item;
    node->next = NULL;
    temp->next = node;
    return list;
}
Ht_item *create_item(char *key, char *value)
{
    // Creates a pointer to a new HashTable item.
    Ht_item *item = (Ht_item *)malloc(sizeof(Ht_item));
    item->key = (char *)malloc(strlen(key) + 1);
    item->value = (char *)malloc(strlen(value) + 1);
    strcpy(item->key, key);
    strcpy(item->value, value);
    return item;
}
void free_item(Ht_item *item)
{
    free(item->key);
    free(item->value);
    free(item);
}
void handle_collision(HashTable *table, unsigned long index, Ht_item *item)
{
    LinkedList *head = table->overflow_buckets[index];

    if (head == NULL)
    {
        head = allocate_list();
        head->item = item;
        table->overflow_buckets[index] = head;
        return;
    }
    else
    {
        // Insert to the list.
        table->overflow_buckets[index] = linkedlist_insert(head, item);
        return;
    }
}
void ht_insert(HashTable *table, char *key, char *value)
{
    Ht_item *item = create_item(key, value);

    int index = hash_function(key);

    Ht_item *current_item = table->items[index];

    if (current_item == NULL)
    {
        if (table->count == table->size)
        {
            printf("Insert Error: Hash Table is full\n");
            free_item(item);
            return;
        }
        table->items[index] = item;
        table->count++;
    }
    else
    {
        if (strcmp(current_item->key, key) == 0)
        {
            strcpy(table->items[index]->value, value);
            return;
        }
        else
        {
            handle_collision(table, index, item);
            return;
        }
    }
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
        handleMountain(name,id);
    }else {
        handleSea(name,id);
    }
    cout << result << endl;
}
void handleSea(string name,int id){

}
void handleMountain(string name,int id){

}
struct MinHNode *newNode(char item, unsigned freq) {
    struct MinHNode *temp = (struct MinHNode *)malloc(sizeof(struct MinHNode));

    temp->left = temp->right = NULL;
    temp->item = item;
    temp->freq = freq;

    return temp;
}

struct MinH *createMinH(unsigned capacity) {
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
    for(int i = 0; i < name.size();i++){
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