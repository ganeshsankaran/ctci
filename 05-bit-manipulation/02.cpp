// print the binary representation of a real number between 0 and 1

#include <iostream>

using namespace std;

string solution(double n) {
    // keep extracting the most significant bit by multiplying by 2
    if(n <= 0.0 || n >= 1.0) return "ERROR";

    string binary = "0.";

    while(n != 0) {
        if(binary.size() > 34) return "ERROR";

        n *= 2;
        if(n >= 1) {
            binary.append("1");
            n--;
        }
        else binary.append("0");
    }

    return binary;
}

int main() {
    cout << solution(0.625) << endl;

    return 0;
}