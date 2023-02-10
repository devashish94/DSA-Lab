/*Write a Program to demonstrate Linear Search Algorithm in an Array. Tell the number of comparisons made at the end, and also Worst, Average and Best Time Complexity*/

#include <stdio.h>

void time_complexity(int _comparisons_made, int _size_of_array) {
    if (_comparisons_made == 1) {
        printf("Best Time Complexity\n");
    }
    else if (_comparisons_made == _size_of_array) {
        printf("Worst Time Complexity\n");
    }
    else if (_comparisons_made > 1 && _comparisons_made < _size_of_array) {
        printf("Average Time Complexity\n");
    }
}

int main() {
    printf("Enter the size of the array: ");
    int _size_of_array, _comparisons_made = 0, _index = 0;
    scanf("%d", &_size_of_array);
    
    //Declaring the Array
    int arr[_size_of_array];

    //Entering the elements of the Array
    for (int i = 0; i < _size_of_array; i++) {
        scanf("%d", &arr[i]);
    }

    int target_to_find;
    printf("Enter the number that you want to search inside the Array: ");
    scanf("%d", &target_to_find);

    //Performing Linear Search
    int _foundCheck = 0;
    for (int i = 0; i < _size_of_array; i++) {
        _comparisons_made++;
        if (arr[i] == target_to_find) {
            _index = i;
            _foundCheck = 1;
            printf("The Element %d was found in at the index %d of the Array. Total %d comparisons were made.\n", target_to_find, _index, _comparisons_made);
            break;
        }
    }

    if (_foundCheck == 1) {
        time_complexity(_comparisons_made, _size_of_array);
        return 0;
    }

    printf("Element was not found inside the Array. Total %d comparisons were made. \n", _comparisons_made);
    time_complexity(_comparisons_made, _size_of_array);

    return 0;
}