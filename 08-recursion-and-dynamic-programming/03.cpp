// Given a sorted array A with distinct elements, find i such that A[i] = i in

#include <iostream>

using namespace std;

int solution1(int* A, int n) {
    // scan
    // O(n)
    for(int i = 0; i < n; i++) {
        if(A[i] == i) return i;
    }

    return -1;
}

int solution2(int* A, int begin, int end) {
    // do a binary search
    // O(log n)
    if(end < begin) return -1;
    
    int mid = (begin + end) / 2;
    
    if(A[mid] == mid) return mid;
    else if(A[mid] < mid)
        return solution2(A, mid + 1, end); // left won't work
    else return solution2(A, begin, mid - 1); // right won't work
}

int solution3(int* A, int begin, int end) {
    // works if there are duplicates
    // recurse on both sides but eliminate neighboring indices that can't work
    if(end < begin) return -1;

    int mid = (begin + end) / 2;

    if(A[mid] == mid) return mid;
    
    // search left
    int left = solution3(A, begin, min(mid - 1, A[mid])); // index <= A[mid] if it is on left
    if(left != -1) return left;

    // search right
    int right = solution3(A, mid + 1, max(end, A[mid]));
    return right;

}

int main() {
    int A[] = {-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13};
    cout << solution1(A, 11) << ',' << solution2(A, 0, 11) << endl;

    int B[] = {-10, -5, 2, 2, 2, 3, 4, 5, 9, 12, 13};
    cout << solution3(B, 0, 11) << endl;

    return 0;
}