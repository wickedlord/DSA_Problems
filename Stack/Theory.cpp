#include <iostream>
#include <stack>
using namespace std;

class Stack {
    public:
        int *arr;
        int size;
        int top;

    // constructor
    Stack (int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push (int element) {
        if (size - top > 1) {
            top++;
            arr[top] = element;
        }
        else {
            cout << "Stack overflow." << endl;
        }
    }

    void pop () {
        if (top > -1) {
            top--;
        }
        else {
            cout << "Stack Underflow." << endl;
        }
    }

    int peek () {
        if (top >= 0) {
            return arr[top];
        }
        else {
            cout << "Stack is empty." << endl;
            return -1;
        }
    }

    bool isEmpty () {
        if (top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main () {
    // stack <int> s;
    // s.push(3);
    // s.push(2);
    // s.push(1);

    // s.pop();
    // cout << "Stack has " << s.size() << " elements" << endl;
    // cout << "Topmost element is " << s.top() << endl;

    // if (s.empty()) {
    //     cout << "Stack is empty" << endl;
    // }

    // else {
    //     cout << "Stack is not empty" << endl;
    // }

    Stack st(5);
    st.push(23);
    st.push(42);
    st.push(43);

    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    cout << st.isEmpty() << endl;
}