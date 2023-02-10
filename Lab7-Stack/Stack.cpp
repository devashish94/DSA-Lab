#include <iostream>

int isEmpty(int top) {
    if (top == -1) {
        std::cout << "[EMPTY-CHECK] The stack is empty\n";
        return 1;
    }
    return 0;
}

int isFull(int top, int size) {
    if (top == size - 1) {
        std::cout << "The stack is full\n";
        return 1;
    }
    return 0;
}

void pushIntoStack(int* arr, int* top, int x, int size) {
    if (isFull(*top, size) == 1) {
        return;
    }
    (*top)++;
    arr[*top] = x;
}

void popTheTop(int* arr, int* top) {
    if (isEmpty(*top) == 1) {
        return;
    }
    (*top)--;
}

void printTop(int* arr, int top) {
    if (isEmpty(top) == 1) {
        return;
    }
    std::cout << "[PRINT-TOP] The element at the top is " << arr[top] << ".\n";
}

int main() {
    int size, top = -1;
    std::cout << "Enter the size of the array: "; std::cin >> size;
    int arr[size];

    while (1) {
        std::cout << "\n";
        std::cout << "You can perform the following operations on stack:\n";
        std::cout << "Press the digit according to the operation you want.\n";
        std::cout << "1. Push into the stack\n";
        std::cout << "2. Pop the top element\n";
        std::cout << "3. Check if stack is empty\n";
        std::cout << "4. Check if stack is full\n";
        std::cout << "5. Print the value of the element at the top\n";
        std::cout << "6. Exit the program\n\n";
        std::cout << "Enter your choice of operation: ";
        int choice = -1; std::cin >> choice;
        switch(choice) {
            case 1: {
                if (isFull(top, size) == 1) {
                    std::cout << "\n";
                    break;
                }
                std::cout << "[PUSH] Enter the element that you want to insert inside the stack: ";
                int x; std::cin >> x;
                pushIntoStack(arr, &top, x, size);
                std::cout << "\n";
                break;
            }
            case 2: {
                popTheTop(arr, &top);
                std::cout << "\n";
                break;
            }
            case 3: {
                if (isEmpty(top) == 0) {
                    std::cout << "[EMPTY-CHECK] The stack is not empty. Press 5 to view the element\n";
                }
                break;
            }
            case 4: {
                if (isFull(top, size) == 0) {
                    std::cout << "[FULL-CHECK] The stack is NOT full.\n";
                }
                break;
            }
            case 5: {
                printTop(arr, top);
                break;
            }
            case 6: {
                std::cout << "Bye!\n";
                return 0;
            }
        }
    }
}
