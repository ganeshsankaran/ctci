// given numbers from 1 to 32000 (with or without duplicates), print all duplicates

#include <bitset>
#include <iostream>
#include <unordered_set>

#define N 32000

using namespace std;

unordered_set<int> solution(int* nums, int size) {
    // set ith bit if i is found
    // O(n)
    bitset<N> found;
    unordered_set<int> duplicates;

    for(int i = 0; i < size; i++) {
        if(found[nums[i]]) duplicates.insert(nums[i]);
        else found.set(nums[i]);
    }

    return duplicates;
}

int main() {
    int nums[] = {1, 2, 5, 3, 2, 2, 8, 8, 5, 7, 9, 0, 1};
    unordered_set<int> duplicates = solution(nums, 13);

    for(int num : duplicates) {
        cout << num << endl;
    }

    return 0;
}
