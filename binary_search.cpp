#include<iostream>

template <typename T>
int binary_search(T arr[], int low, int high, T element) {
    int mid = (high+low)/2;
    if (low == high) {
        if (arr[low] == element) {
            return low;
        }
        else {
            return -1;
        }
    }
    if (arr[mid] == element) {
        return mid;
    }
    if (arr[mid] > element) {
        return binary_search(arr, low, mid, element);
    }
    return binary_search(arr, mid, high, element);
}

int main(int argc, char** argv) {
    int arr[8] = {1, 4, 12, 29, 33, 34, 58, 98};
    std::cout << binary_search(arr, 0, sizeof(arr)/sizeof(arr[0]), 1) << std::endl;
    return 0;
}