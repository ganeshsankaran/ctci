// write code to find an element in a rotated sorted array

# include <iostream>

using namespace std;

int solution(int* arr, int left, int right, int val) {
    // modified binary search
    // O(log n) average, O(n) worst case (only if many duplicates)
    if(right < left) return -1;

    int mid = (left + right) / 2;
    if(arr[mid] == val) return mid;
    
    if(arr[left] < arr[mid]) { // left is normal
        if(arr[left] < val && val < arr[mid]) 
            return solution(arr, left, mid - 1, val); // search left
        else return solution(arr, mid + 1, right, val); // search right
    }
    else if(arr[mid] < arr[right]) { // right is normal
        if(arr[mid] < val && val < arr[right]) 
            return solution(arr, mid + 1, right, val); // search right
        else return solution(arr, left, mid - 1, val); // search left
    }
    else { // arr[left]
        int index = -1;

        if(arr[left] == arr[mid]) // all left is duplicates
            index = solution(arr, mid + 1, right, val); // search right

        if(index == -1 && arr[mid] == arr[right]) // not found on left and all right is duplicates
            index = solution(arr, left, mid - 1, val);
        
        return index;
    }
}

int main() {
    int arr[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    cout << solution(arr, 0, 11, 5) << endl;

    return 0;
}