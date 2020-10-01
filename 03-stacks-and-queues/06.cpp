#include <iostream>
#include <queue>

using namespace std;

class Animal {
public:
    string name;
};

class Dog : public Animal {
public:
    Dog() {
        this->name = "";
    }

    Dog(string name) {
        this->name = name;
    }
};

class Cat : public Animal {
public:
    Cat() {
        this->name = "";
    }

    Cat(string name) {
        this->name = name;
    }
};

class NoAnimalsException {};

class AnimalQueue {
public:
    void enqueue(Dog dog) {
        dogs.push(pair<Dog, int>(dog, ++n));
    }

    void enqueue(Cat cat) {
        cats.push(pair<Cat, int>(cat, ++n));
    }

    Animal dequeue() {
        pair<Dog, int> dog;
        pair<Cat, int> cat;

        if(dogs.empty() && cats.empty()) throw new NoAnimalsException();
        
        if(dogs.empty()) {
            cat = cats.front();
            cats.pop();
            return cat.first;
        }

        if(cats.empty()) {
            dog = dogs.front();
            dogs.pop();
            return dog.first;
        }

        dog = dogs.front();
        cat = cats.front();

        if(dog.second < cat.second) {
            dogs.pop();
            return dog.first;
        }
        else {
            cats.pop();
            return cat.first;
        }
    }

    Dog dequeue_dog() {
        pair<Dog, int> dog = dogs.front();

        if(dogs.empty()) throw new NoAnimalsException();

        dogs.pop();
        return dog.first;
    }

    Cat dequeue_cat() {
        pair<Cat, int> cat = cats.front();
        if(cats.empty()) throw new NoAnimalsException();

        cats.pop();
        return cat.first;
    }

private:
    queue<pair<Dog, int>> dogs;
    queue<pair<Cat, int>> cats;
    int n;
};

int main() {
    Dog tucker("tucker");
    Dog journey("journey");
    Cat maui("maui");
    Cat pearl("pearl");

    AnimalQueue q;
    q.enqueue(tucker);
    q.enqueue(journey);
    q.enqueue(maui);
    q.enqueue(pearl);

    cout << q.dequeue().name << endl;
    cout << q.dequeue_cat().name << endl;

    return 0;
}