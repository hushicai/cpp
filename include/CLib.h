typedef struct CStashTag {
    int size; // size of each space
    int quantity; // number of storage spaces
    int next; // next empty space
    unsigned char* storage; // bytes
} CStash;

void initialize(CStash* s, int sz);
void cleanup(CStash* s);
int add(CStash* s, const void* element);
void* fetch(CStash* s, int index);
int count(CStash* s);
void inflate(CStash* s, int increase);
