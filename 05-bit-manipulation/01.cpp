// write a method to insert M into N such that M starts at bit j and ends at bit i

#include <bitset>
#include <iostream>

using namespace std;

bitset<sizeof(int) * 8> solution(int N, int M, int i, int j) {
    if(i > j || i < 0 || j > sizeof(int) * 8) return bitset<32>(0);

    // create a mask like 11..00...11
    int mask = (~0 << (j + 1)) + (1 << i) - 1;
    return bitset<sizeof(int) * 8>((N & mask) | (M << i));
}

int main() {
    cout << solution(0b10000000000, 0b10011, 2, 6) << endl;

    return 0;
}