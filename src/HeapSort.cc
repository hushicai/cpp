// 堆排序

#include <iostream>
#include <cmath>

using namespace std;

// 声明
int parent(int); 
int left(int);
int right(int);

void Max_Heapify(int [], int, int);
void Build_Max_Heap(int [], int);
void HeapSort(int [], int);
void print(int [], int);

// 数组从0开始

// 定义
int parent(int i) {
    return static_cast<int>(floor((i - 1) / 2));
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

void Max_Heapify(int A[], int i, int heap_size) {
    int l = left(i);
    int r = right(i);
    int largest;

    if (l < heap_size && A[l] > A[i]) {
        largest = l;
    }
    else {
        largest = i;
    }

    if (r < heap_size && A[r] > A[largest]) {
        largest = r;
    }

    if (largest != i) {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        Max_Heapify(A, largest, heap_size);
    }
}

void Build_Max_Heap(int A[], int heap_size) {
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        Max_Heapify(A, i, heap_size);
    }
}

void print(int A[], int heap_size) {
    for (int i = 0; i < heap_size; i++) {
        cout << A[i] << " ";
    }

    cout << endl;
}

void HeapSort(int A[], int heap_size) {
    Build_Max_Heap(A, heap_size);
    int temp;
    for (int i = heap_size - 1; i >= 0; i--) {
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        // heap_size递减
        Max_Heapify(A, 0, i);
    }

    print(A, heap_size);
}

int main() {
    const int heap_size = 13;
    int A[] = {19, 1, 10, 14, 16, 4, 7, 9, 3, 2, 8, 5, 11};
    HeapSort(A, heap_size);
    return 0;
}
