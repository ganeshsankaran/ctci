// Tower of Hanoi
// 1 tower: trivial
// 2 towers: src->buffer (1), src->dest (2), buffer->dest (1)
// 3 towers: move 2 towers src->buffer, move top src->dest, move 2 towers buffer->dest

#include <iostream>
#include <stack>

using namespace std;

class Tower {
public:
    Tower() {}
    Tower(int n) {
        for(int i = n; i > 0; i--) {
            this->disks.push(i);
        }
    }

    void move(int n, Tower& dest, Tower& buffer) {
        if(n < 1) return;

        move(n - 1, buffer, dest); // move src->buffer
        dest.disks.push(this->disks.top()); // move src->dest
        this->disks.pop();
        buffer.move(n - 1, dest, *this); // move buffer->dest
    }

    stack<int> disks;
};

ostream& operator<<(ostream& os, Tower tower) {
    string disks = "";

    while(!tower.disks.empty()) {
        disks = to_string(tower.disks.top()) + ' ' + disks;
        tower.disks.pop();
    }

    os << disks;
    return os;
}

int main() {
    Tower t1(10);
    Tower t2;
    Tower t3;

    t1.move(10, t3, t2);

    cout << "1: " << t1 << endl;
    cout << "2: " << t2 << endl;
    cout << "3: " << t3 << endl;

    return 0;
}