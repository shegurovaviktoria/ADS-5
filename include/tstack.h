// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
  private:
    T arr[size];
    int top;
public:
    TStack() : top(-1) {}

    void push(T val) {
        if (top == size - 1) {
            throw std::out_of_range("Stack is full");
        }
        arr[++top] = val;
    }

    T pop() {
        if (top == -1) {
            throw std::out_of_range("Stack is empty");
        }
        return arr[top--];
    }

    T peek() const {
        if (top == -1) {
            throw std::out_of_range("Stack is empty");
        }
        return arr[top];
    }

    bool isEmpty() const {
        return top == -1;
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == ' ' || op == '/') {
        return 2;
    }
    return 0;
};

#endif  // INCLUDE_TSTACK_H_
