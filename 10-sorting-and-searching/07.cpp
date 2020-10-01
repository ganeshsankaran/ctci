// given an input file with many non-negative ints, provide an alg to generate an integer not in the file
// assume 1GB of memory is available

#include <bitset>
#include <iostream>

#define N (long)(INT_MAX) + 1 // number of non-negative integers

using namespace std;

int solution(int* file, int size) {
    // set bit i if i is found
    // return a bit that's not set
    // O(n)
    bitset<N>* found = new bitset<N>(); // use the heap for more memory

    for(int i = 0; i < size; i++) {
        found->set(file[i]);
    }

    for(long i = 0; i < found->size(); i++) {
        if(!(*found)[i]) {
            delete found;
            return i;
        }
    }

    delete found;
    return -1;
}

int main() {
    int file[] = {1, 2, 5, 3, 2, 2, 8, 8, 5, 7, 9, 0, 1};
    cout << solution(file, 13) << endl;

    return 0;
}