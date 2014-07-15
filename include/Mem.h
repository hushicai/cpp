#ifndef MEM_H
#define MEM_H 

typedef unsigned char byte;

class Mem {
    byte* mem;
    int size;
    void ensureMinSize(int minSize);
public:
    Mem();
    Mem(int sz);
    ~Mem();
    int mSize();
    byte* pointer();
    byte* pointer(int minSize);
};

#endif
