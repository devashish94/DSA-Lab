/* C program to store temperature of two cities of a week and display it */

#include <stdio.h>

int main() {
    int store[2][7];
    int val = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 7; j++) {
            printf("Enter the Temperatures for the Day %d: ", j + 1);
            scanf("%d", &store[i][j]);
        }
    }    
    
    //Printing the Values
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 7; j++) {
            printf("City %d, Day %d = %d\n", i + 1, j + 1, store[i][j]);
        }
    }
}