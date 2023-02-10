#include <iostream>
using namespace std;

int main() {
    cout << "Enter the size of the 2D Array: ";
    int a, b, k; cin >> a >> b;
    int arr[a][b];
    cout << "Now enter each and every element of the Array\n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << "Enter the element at (" << i << ", " << j << "): ";
            cin >> k;
            *(*arr + (i * b) + j) = k;
        }
    }
    cout << "The Array you entered is: \n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << *(*arr + (i * b) + j) << " ";
        }
        cout << "\n";
    }
}