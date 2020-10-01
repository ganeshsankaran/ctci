// arrange an array into peaks and valleys

#include <iostream>

using namespace std;

void solution1(int* arr, int size) {
    // sort and swap pairs
    // O(n log n)
    sort(arr, arr + size);
    
    for(int i = 1; i < size; i += 2) {
        swap(arr[i], arr[i - 1]);
    }
}

void solution2(int* arr, int size) {
    // put peaks in the right places by comparing with neigbors
    // O(n)
    for(int i = 1; i < size; i += 2) {
        int* peak = max_element(arr + i - 1, arr + i + 2); // max of neighbors

        if(arr[i] != *peak) { // not a peak
            swap(arr[i], *peak); // make i a peak
        }
    }
}

int main() {
    int arr1[] = {15, 11, 8, 4, 0, 1, 7, 9, 14};
    solution1(arr1, 9);
    
    for(int i = 0; i < 9; i++) {
        cout << arr1[i] << ' ';
    }
    cout << endl;

    int arr2[] = {15, 11, 8, 4, 0, 1, 7, 9, 14};
    solution2(arr2, 9);
    
    for(int i = 0; i < 9; i++) {
        cout << arr2[i] << ' ';
    }
    cout << endl;

    return 0;
}