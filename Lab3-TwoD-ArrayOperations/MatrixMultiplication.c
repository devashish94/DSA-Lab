/* Write a program to show Matrix Multiplication */

#include <stdio.h>

int main() {
    int a[3][3] = {{12, 8, 4}, {3, 17, 14},{9, 8, 10}};
    int b[3][3] = {{5, 19, 3}, {6, 15, 9}, {7, 8, 16}};
    int c[3][3];
    int sum = 0;

    for (int k = 0; k < 3; k++) {
        for (int j = 0; j < 3; j++) {
            sum = 0;
            for (int i = 0; i < 3; i++) {
                sum += a[k][i] * b[i][j];
            }
            c[k][j] = sum;
        }
    }

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            printf("%d\t", c[j][i]);
        }
        printf("\n");
        printf("\n");
    }
    
    return 0;
}