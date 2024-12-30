#include <iostream>
using namespace std;
const int MAX = 100;

template <class T>

/*
    * Class to implement stack using an array
    * T is the type of the elements in the stack
    * MAX is the maximum number of elements in the stack
    * top is the index of the top element
    * item is the array to store the elements
    * push function to add an element to the stack
    * pop function to remove the top element from the stack
    * getTop function to get the top element of the stack
    * print function to print the elements of the stack
    * isEmpty function to check if the stack is empty
    * pop function with call by reference
    * getTop function to get the top element
    * 
    * 
    * The stack class is a template class that can be used with any data type
*/
class stack {
    int top; // index of the top element
    T item[MAX]; // array to store the elements
public:
    stack():top(-1) {} // constructor
    void push(T x){ // call by value
        if (top >= MAX - 1) { // stack is full
            cout << "Stack is full" << endl; // print error message
            return; // exit the function
        }
        top++; // increment top
        item[top] = x; // store x in the array
    }

    bool isEmpty() { // check if the stack is empty
        return top < 0; // return true if top is less than 0
    }

    void pop() { // remove the top element
        if (isEmpty()) { // check if the stack is empty
            cout << "Stack is empty" << endl; // print error message
            return; // exit the function
        }
        top--; // decrement top
    }

    void pop(T &x) { // call by reference
        if (isEmpty()) { // check if the stack is empty
            cout << "Stack is empty" << endl; // print error message
            return; // exit the function
        }
        x = item[top]; // store the top element in x
        top--; // decrement top
    }

    T getTop() { // get the top element
        if (isEmpty()) { // check if the stack is empty
            cout << "Stack is empty" << endl; // print error message
            return -1; // return -1
        }
        return item[top]; // return the top element
    }

    void print() { // print the elements of the stack
        if (isEmpty()) { // check if the stack is empty
            cout << "Stack is empty" << endl; // print error message
            return;
        }
        for (int i = top ; i >= 0; i--) { // iterate from top to 0
            cout << item[i] << " "; // print the element
        }
        cout << endl; // print a new line
    }
};

int main() {
    stack<int> s; // create a stack of integers
    s.push(1); // push 1 to the stack
    s.push(2); // push 2 to the stack
    s.push(3); // push 3 to the stack
    s.push(4); // push 4 to the stack
    s.print(); // print the elements of the stack
    int x; // declare a variable x
    s.pop(x); // pop the top element
    cout << "Popped element: " << x << endl; // print the popped element
    s.print(); // print the elements of the stack
    cout << "Top element: " << s.getTop() << endl; // print the top element
    return 0; // return 0
}