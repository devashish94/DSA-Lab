#include <iostream>
using namespace std;

int main() {
    string s; cin >> s;
    char c; cin >> c;
    int count = 0;
    for (char i : s) {
        if (i == c) count++;
    }
    cout << count << " \n";
}