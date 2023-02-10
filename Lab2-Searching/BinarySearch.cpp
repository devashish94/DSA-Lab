#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printArray(vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void inputArray(vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "enter the element at index " << i << ": ";
        cin >> arr[i];
    }
}

int binarySearch(vector<int>& arr, int n, int search) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == search) {
            return mid;
        }
        else if (arr[mid] < search) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    cout << "Enter the size of the Array: ";
    int n; cin >> n;
    vector<int> arr(n, 0);
    cout << "Enter each element one by one -> \n";
    inputArray(arr, n);

    //Sorting the Array and then printing it to the console
    std::sort(arr.begin(), arr.end());
    cout << "The Array you enterd after sorting is: ";
    printArray(arr, n);

    cout << "Enter the element that you want to search in the Array: ";
    int search; cin >> search;

    auto result = binarySearch(arr, n, search);
    if (result == -1) {
        cout << "The element that you want to search does not exist inside the Array.\n";
        return 0;
    }
    cout << "The element was found at index: " << result << "\n";
}