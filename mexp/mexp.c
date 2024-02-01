#include <stdio.h>
#include <stdlib.h>
//use malloc
//input is file in arg- matrix
//
void multmatrix(int **a, int **b, int **result, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");

    int size;
    fscanf(file, "%d", &size);

    // malloc = allocate memory
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }

    int exponent;
    fscanf(file, "%d", &exponent);
    fclose(file);

    int **result = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        result[i] = (int *)malloc(size * sizeof(int));
    }

    if (exponent == 0) {
        // Identity matrix
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == j) {
                    result[i][j] = 1;
                } else {
                    result[i][j] = 0;
                }
            }
        }
    } else {
        int **temp = (int **)malloc(size * sizeof(int *));
        for (int i = 0; i < size; i++) {
            temp[i] = (int *)malloc(size * sizeof(int));
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                temp[i][j] = matrix[i][j];
            }
        }

        for (int k = 0; k < exponent-1; k++) {//
            multmatrix(temp, matrix, result, size);
            //change temp to product each time and keep multiplying w itself
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    temp[i][j] = result[i][j];
                }
            }
        }

        for (int i = 0; i < size; i++) {
            free(temp[i]);
        }
        free(temp);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d", result[i][j]);
            if (j < size - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    // free all memory
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
        free(result[i]);
    }
    free(matrix);
    free(result);

    return 0;
}
