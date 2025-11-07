#include <stdio.h>

int main() {
    int r, c;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    int mat[10][10];
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int newRow, newCol, value;
    printf("Enter position (row and column) to insert: ");
    scanf("%d %d", &newRow, &newCol);
    printf("Enter value to insert: ");
    scanf("%d", &value);

    // Check if position is valid
    if (newRow < 0 || newRow >= r || newCol < 0 || newCol >= c) {
        printf("Invalid position!\n");
        return 0;
    }

    // Insert the element (replace existing)
    mat[newRow][newCol] = value;

    printf("\nMatrix after insertion:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}