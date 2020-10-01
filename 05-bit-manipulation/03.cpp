// you can flip one bit from a 0 to a 1. Write code to find the length of the longest sequence of 1s you can create

#include <bitset>
#include <iostream>

using namespace std;

int solution(int n) {
    // keep track of previous and current lengths of 1s
    // O(b)
    if(!~n) return sizeof(int) * 8;

    bitset<sizeof(int) * 8> binary(n);
    int prev = 0, curr = 0, longest = 1;

    for(int i = 0; i < 32; i++) {
        if(binary[i]) curr++;
        else {
            if(binary[i + 1]) prev = curr; // next bit is 1 so can use
            else prev = 0; // next bit is 0 so can't use
            curr = 0;
        }
        longest = max(longest, prev + 1 + curr);
    }

    return longest;
}

int main() {
    cout << solution(0b11011101111) << endl;
    
    return 0;
}