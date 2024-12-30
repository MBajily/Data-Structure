#include <iostream>
using namespace std;

template <class T>
class stack {
    struct node {
        T item;
        node *next;
    };
    node *top;

public:
    stack():top(NULL) {}
    
    void push(T newItem){
        node *newItemPtr = new node;
        if (newItemPtr == NULL) {
            cout << "Stack push cannot allocate memory" << endl;
            return;
        }
        newItemPtr->item = newItem;
        newItemPtr->next = top;
        top = newItemPtr;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack pop on empty stack" << endl;
            return;
        }
        node *temp = top;
        top = top->next;
        temp = temp->next = NULL;
        delete temp;
    }

    void pop(T &stackTop) {
        if (isEmpty()) {
            cout << "Stack pop on empty stack" << endl;
            return;
        }
        stackTop = top->item;
        node *temp = top;
        top = top->next;
        temp = temp->next = NULL;
        delete temp;
    }

    T getTop() {
        if (isEmpty()) {
            cout << "Stack getTop on empty stack" << endl;
            return T();
        }
        return top->item;
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        node *current = top;
        while (current != NULL) {
            cout << current->item << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.print();
    int x;
    s.pop(x);
    cout << "Popped: " << x << endl;
    s.print();
    cout << "Top: " << s.getTop() << endl;
    return 0;
}