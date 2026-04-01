#include <iostream>
#include <stdexcept>
#include <new>
#include <string>

using namespace std;

class StackOverflowException : public runtime_error {
public:
    StackOverflowException() : runtime_error("Помилка: Стек переповнений! Неможливо додати новий елемент.") {}
};

class StackEmptyException : public runtime_error {
public:
    StackEmptyException() : runtime_error("Помилка: Стек порожній! Неможливо отримати елемент.") {}
};

template <typename T>
class Stack {
private:
    T* arr;
    int capacity;
    int topIndex;

public:
    Stack(int size) {
        if (size <= 0) {
            throw invalid_argument("Помилка: Розмір стека має бути більшим за 0!");
        }
        
        try {
            arr = new T[size];
        } 
        catch (const bad_alloc& e) {
            throw runtime_error("Помилка: Не вдалося виділити пам'ять для стека!");
        }
        
        capacity = size;
        topIndex = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(T value) {
        if (topIndex == capacity - 1) {
            throw StackOverflowException();
        }
        arr[++topIndex] = value;
    }

    T pop() {
        if (isEmpty()) {
            throw StackEmptyException();
        }
        return arr[topIndex--];
    }

    T peek() const {
        if (isEmpty()) {
            throw StackEmptyException();
        }
        return arr[topIndex];
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    int size() const {
        return topIndex + 1;
    }
};

int main() {
    setlocale(LC_ALL, "Ukrainian");

    try {
        Stack<int> badStack(-5);
    } 
    catch (const exception& e) {
        cout << "Перехоплено: " << e.what() << endl;
    }

    try {
        Stack<int> myStack(3);
        
        myStack.push(10);
        myStack.push(20);
        myStack.push(30);
        
        myStack.push(40); 
    } 
    catch (const exception& e) {
        cout << "Перехоплено: " << e.what() << endl;
    }

    try {
        Stack<string> strStack(2);
        
        strStack.push("Привіт");
        strStack.pop();
        
        strStack.pop(); 
    } 
    catch (const exception& e) {
        cout << "Перехоплено: " << e.what() << endl;
    }

    return 0;
}
