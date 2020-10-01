// write a method to find a location of a string in a sorted array of strings with interspersed empty strings
// assume the string is not the empty string

#include <iostream>

using namespace std;

int solution(string* strings, int left, int right, string str) {
    // modified binary search
    // O(log n) average, O(n) worst if many empty strings are landed upon
    if(right < left) return -1;

    int mid = (left + right) / 2;
    if(strings[mid] == "") { // move to nearest string
        int l = mid - 1, r = mid + 1;
        while(true) {
            if(l < left || r > right) return -1; // out of bounds
            else if(l >= left && strings[l] != "") {
                mid = l;
                break;
            }
            else if(r <= right && strings[r] != "") {
                mid = r;
                break;
            }
            l++;
            r--;
        }
    }

    if(strings[mid] == str) return mid;
    else if(strings[mid] < str) return solution(strings, mid, right, str);
    else return solution(strings, left, mid, str);
}

int main() {
    string strings[] = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    cout << solution(strings, 0, 12, "ball") << endl;

    return 0;
}