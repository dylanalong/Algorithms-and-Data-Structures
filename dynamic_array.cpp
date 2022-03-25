#include<iostream>

template <class T>
class DynamicArray {
    private:
        T* arr;                       //main array
        unsigned int next_index;        //index next element will be added
        unsigned int curr_size;
        void upsize();
    public:
        DynamicArray();
        ~DynamicArray();
        T& operator[](int index);
        void push(T value);
        int size();
};

template <class T>
DynamicArray<T>::DynamicArray() {
    int init_size = 4;
    arr = new T[init_size];
    curr_size = init_size;
    next_index = 0;
}

template <class T>
DynamicArray<T>::~DynamicArray() {
    delete[] arr;
}

//ADD: resize if index is beyond upper range limit
//we might just throw from here, not catch, maybe not even try
template <class T>
T& DynamicArray<T>::operator[](int index) {
    try {
        if (index >= next_index || index < 0) {
            throw "index out of range";
        }
    }
    catch (const char* msg) {
        std::cerr << msg << std::endl;
    }
        
    return *(arr + index);
}

template <class T>
void DynamicArray<T>::push(T value) {
    if (next_index > curr_size-1) {
        upsize();
    }

    arr[next_index] = value;
    this->next_index += 1;
}

template <class T>
int DynamicArray<T>::size() {
    return curr_size;
}

template <class T>
void DynamicArray<T>::upsize() {
    curr_size *= 2;

    T* prev_arr = arr;
    arr = new T[curr_size];
    
    for (int i = 0; i < next_index; i++) {
        arr[i] = prev_arr[i];
    }

    delete[] prev_arr;
}

int main(int argc, char** argv) {
    DynamicArray<int> darr;
    for (int i = 0; i < 5; i++) {
        darr.push(i+1);
    }
    
    darr[4] = 25;
    darr[3] = darr[4]*2;

    DynamicArray<char> carr;

    for (char c = 'a'; c < 'z'; c++) {
        carr.push(c);
    }

    carr[20] = 'z';

    return 0;
}