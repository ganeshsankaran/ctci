// implement multiplication without using * or /

#include <iostream>
#include <unordered_map>

using namespace std;

int solution(int length, int width, unordered_map<int, int>& T) {
    // break multiplication into two halves based on shorter side (width)
    // ex. 9 * 6 = 9 * 3 + 9 * 3
    // O(log width)
    if(width == 0) return 0; // 0 * length
    if(width == 1) return length; // 1 * length

    int half_width = width >> 1, half_area;
    if(T.find(half_width) == T.end()) 
        half_area = solution(length, half_width, T);
    else half_area = T[half_width];

    if((half_width << 1) == width) { // even width
        return half_area << 1;
    }
    else { // odd width
        if(T.find(width - half_width) == T.end())
            return half_area + solution(length, width - half_width, T);
        else return half_area + T[width - half_width];
    }
}

int main() {
    unordered_map<int, int> T; // store products based on width
    cout << solution(9, 5, T) << endl; 
    return 0;
}