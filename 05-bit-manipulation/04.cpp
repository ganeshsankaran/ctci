// find the next larger and smaller number with the same number of 1s

#include <bitset>
#include <iostream>

using namespace std; 

bitset<sizeof(int) * 8> larger(int n) {
    // flip the first 0 to the left of 1s and move all 1s to the right of it rightward
    if(!n) return 0;

    bitset<sizeof(int) * 8> binary(n);
    
    int first_zero;
    bool found_one = false;
    int ones = 0;

    for(int i = 0; i < 32; i++) {
        if(binary[i]) {
            found_one = true;
            ones++;
        }
        else if(!binary[i] && found_one) {
            first_zero = i;
            break;
        }
    }

    binary.set(first_zero); // there is an extra 1 now
    ones--;

    for(int i = 0; i < first_zero; i++) {
        if(ones > 0) {
            binary.set(i);
            ones--;
        }
        else binary.reset(i);
    }

    return binary;
}

bitset<sizeof(int) * 8> smaller(int n) {
    // flip the first 1 to the left of 0s and move 0s to the right of it leftward
    if(!~n) return n;

    bitset<sizeof(int) * 8> binary(n);
    
    int first_one;
    bool found_zero = false;
    int zeros = 0;

    for(int i = 0; i < 32; i++) {
        if(!binary[i]) {
            found_zero = true;
            zeros++;
        }
        else if(binary[i] && found_zero) {
            first_one = i;
            break;
        }
    }

    binary.reset(first_one); // there is an extra 0 now
    zeros--;

    for(int i = 0; i < first_one; i++) {
        if(zeros > 0) {
            binary.reset(i);
            zeros--;
        }
        else binary.set(i);
    }

    return binary;
}

pair<bitset<sizeof(int) * 8>, bitset<sizeof(int) * 8>> solution(int n) {
    return pair<bitset<sizeof(int) * 8>, bitset<sizeof(int) * 8>>(larger(n), smaller(n));
}

int main() {
    cout << solution(0b11011001111100).first << endl;
    cout << solution(0b10011110000011).second << endl;

    return 0;
}