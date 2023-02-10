/*
Create an event driven program, having the following Array Operations
    1. Insertion
    2. Searching (using Linear Search) 
    3. Deletion
All the Operations on the Array should be implemented through Functions i.e. the Main function should serve the only purpose of driving the program.
*/

#include <stdio.h>
#include <stdlib.h>

void insertArray(int* array, int* _sizeOfArray) {
    for (int i = 0; i < *_sizeOfArray; i++) {
        printf("Enter the element at position %d: ", i);
        scanf("%d", array + i);
    }
}

void printArray(int* array, int* _sizeOfArray) {
        for (int i = 0; i < *_sizeOfArray; i++) {
        printf("%d ", *(array + i));
    }
}

int linearSearch(int* array, int* _sizeOfArray, int target) {
    for (int i = 0; i < *_sizeOfArray; i++) {
        if (target == *(array + i)) {
            return i;
        }
    }
    return -1;
}

void insertion(int* array, int* _sizeOfArray) {
    int number = -1, location = 0;

    printf("[INSERTION] Enter the NUMBER that you want to Insert inside the Array along with its INDEX. \n");
    printf("[INSERTION] Element: ");
    scanf("%d", &number);
    printf("[INSERTION] Location: ");
    scanf("%d", &location);


    if (location >= *_sizeOfArray) {
        printf("[INSERTION-ERROR] Cannot insert an element outside the Array\n");
        return;
    }

    *_sizeOfArray = *_sizeOfArray + 1; //Increases the Array Size for the realloc() function by 1

    int* newArray = (int*) realloc (array, *_sizeOfArray * sizeof(int));
    if (newArray == NULL) {
        return;
    }
    array = newArray;

    //Shifting Logic
    for (int i = *_sizeOfArray - 1; i > location; i--) {
        array[i] = array[i - 1];
    }

    //Inserting the element at the desired location
    array[location] = number;
}

void searching(int* array, int* _sizeOfArray) {
    int target = 0;

    if (*_sizeOfArray == 0) {
        printf("[SEARCHING] The entered NUMBER was not found in the Array in any INDEX ");
        return;
    }

    printf("[SEARCHING] Enter a number that you want to SEARCH inside the array. \n");
    printf("[SEARCHING] Enter the Target number: ");
    scanf("%d", &target);

    //Linear Search
    for (int i = 0; i < *_sizeOfArray; i++) {
        if (target == *(array + i)) {
            printf("[SEARCHING] The TARGET Number %d was found in the Array at the INDEX: %d", target, i);
            return;
        }
    }
    printf("[SEARCHING] The entered NUMBER was not found in the Array in any INDEX");
    return;
}

void deleteShift(int* array, int* _sizeOfArray, int index) {
    //Shifting the elements by overwriting over the undesired element
    for (int i = index; i < *_sizeOfArray - 1; i++) {
        array[i] = array[i + 1];
    }
    array[*_sizeOfArray - 1] = 0;
}

void multipleDelete(int* array, int* _sizeOfArray) {
    int intToDelete = 0;
    printf("This Operation Mode Allows you to delete multiple instances of the element from the whole Array\n");
    printf("[MULTIPLE-DELETION] ");
    printArray(array, _sizeOfArray); //Preview the Array for selecting the element to be deleted
    printf("\n");
    printf("[MULTIPLE-DELETION] Enter the NUMBER that you want to COMPLETELY remove from the array: ");
    scanf("%d", &intToDelete);

    int countInstances = 0;
    //Counting the number of instances of the element to be removed
    for (int i = 0; i < *_sizeOfArray; i++) {
        if (array[i] == intToDelete) {
            countInstances++;
        }
    }

    if (countInstances == 0) {
        printf("[MULTIPLE-DELETION] The element is not present inside the Array\n");
        return;
    }

    //Checking if multiple instances of the element in question exists!
    if (countInstances == 1) {
        printf("[MULTPLE-DELETION] There are not enough instances for this opeartion to function");
        return;
    }
    int location = 0;
    for (int i = 0; i < countInstances; i++) {
        location = linearSearch(array, _sizeOfArray, intToDelete);
        deleteShift(array, _sizeOfArray, location);
    }
    *_sizeOfArray = *_sizeOfArray - countInstances;

    if (*_sizeOfArray == 0) {
        // *_sizeOfArray = 1;
        int* newestArray = (int*) malloc(1 * sizeof(int));
        if (newestArray == NULL) {
            printf("Coming FROM Array size = 0, program crashed\n");
            return;
        }
        array = newestArray;
        return;
    }

    int* newerArray = (int*) realloc(array, *_sizeOfArray * sizeof(int));
    if (newerArray == NULL) {
        printf("COMING from multi delete newer array could not be realloced()");
    }
    array = newerArray;
}

void deletion(int* array, int* _sizeOfArray) {
    int del = 0;

    if (*_sizeOfArray == 0) {
        printf("[DELETION-ERROR] No element left inside of the Array to delete! Insert an element and then Try Again.\n");
        return;
    }

    printf("[DELETION] ");
    printArray(array, _sizeOfArray); //Preview the Array for selecting the element to be deleted
    printf("\n");
    printf("[DELETION] Enter the NUMBER that you want to delete from the array: ");
    scanf("%d", &del);

    //Checking if the element to delete is found inside the array or not
    if (linearSearch(array, _sizeOfArray, del) == -1) {
        printf("[DELETION-ERROR] Enter a VALID NUMBER From the Array.\n");
        return;
    }
    int index = linearSearch(array, _sizeOfArray, del);
    if (index < 0) return;

    deleteShift(array, _sizeOfArray, index);
    array[*_sizeOfArray - 1] = 0;

    //Reallocate the Array for removing the last Memory Block from the Array
    *_sizeOfArray = *_sizeOfArray - 1; //Decreases the Array Size for the realloc() function by 1

    if (*_sizeOfArray == 0) {
        // *_sizeOfArray = 1;
        int* newestArray = (int*) malloc(1 * sizeof(int));
        if (newestArray == NULL) {
            printf("Coming FROM Array size = 0, program crashed\n");
            return;
        }
        array = newestArray;
        return;
    }

    int* nArray = (int*) realloc(array, *_sizeOfArray * sizeof(int));
    if (nArray == NULL) {
        printf("ERROR");
        return;
    }
    array = nArray;
}   

int main() {
    //Getting the Size of the Array
    int _sizeOfArray = 0;
    printf("Enter the Size of the Array: ");
    scanf("%d", &_sizeOfArray); 
    printf("\n");

    //Declaring a Dynamically Allocated Array
    int* array = (int*) malloc (_sizeOfArray * sizeof(int));

    //Checking if the returned Memory Address of the Array is Valid
    if (array == NULL) {
        printf("[ERROR] Memory required for creating the Array could not be Allocated \n");
        printf("\n");
        return 1;
    }

    printf("Now you have to Enter the elements of the Array one by one. \n");
    
    //User Input for all the elements of the Array
    insertArray(array, &_sizeOfArray);

    printf("\n");
    printf("\n");
    printf("All the Elements of the Array are: \n");
    
    //Printing the Elements of the Array
    printArray(array, &_sizeOfArray);
    printf("\n");
    printf("\n");

    //Program Loop
    while (1) {

        printf("Now enter the number respective to the operation you desire to perform on the Array\n");
        
        //All the Choices
        printf("1. Insertion \n");
        printf("2. Searching \n");
        printf("3. Deletion \n");
        printf("4. Multiple Deletion \n");
        printf("5. Print the Array \n");
        printf("6. Exit the Program \n");
        printf("\n");
        printf("Choice: ");

        int choice = 0;
        scanf("%d", &choice);
        printf("\n");
        
        if (choice == 1) {
            insertion(array, &_sizeOfArray);
            choice = 0;
            printf("\n");
        }
        else if (choice == 2) {
            searching(array, &_sizeOfArray);
            printf("\n");
            printf("\n");
        } 
        else if (choice == 3) {
            deletion(array, &_sizeOfArray);
            printf("\n");
        }
        else if (choice == 4) {
            multipleDelete(array, &_sizeOfArray);
            printf("\n");
        }
        else if (choice == 5) {
            printf("[PRINT] ");
            printArray(array, &_sizeOfArray);
            printf("\n");
            printf("\n");
        }
        else if (choice == 6) {
            printf("[EXIT] Bye!\n");
            free(array);
            return 0;
        }
        else {
            printf("[INVALID] Enter a valid operation number \n");
            printf("\n");
        }
    }
}
