#include <stdio.h>

int main() {
    int m1, n1, m2, n2;
    int i, j, k;

    // Input dimensions of first matrix
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &m1, &n1);

    // Input dimensions of second matrix
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &m2, &n2);

    // Check if multiplication is possible
    if (n1 != m2) {
        printf("Matrix multiplication not possible!\n");
        return 0;
    }

    int A[m1][n1], B[m2][n2], C[m1][n2];

    // Input first matrix
    printf("Enter elements of first matrix:\n");
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input second matrix
    printf("Enter elements of second matrix:\n");
    for (i = 0; i < m2; i++) {
        for (j = 0; j < n2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Initialize result matrix and counters
    int multiplications = 0, additions = 0;
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n2; j++) {
            C[i][j] = 0;
            for (k = 0; k < n1; k++) {
                C[i][j] += A[i][k] * B[k][j];
                multiplications++;    // one multiplication
                if (k > 0) additions++; // additions start after first term
            }
        }
    }

    // Print result matrix
    printf("Resultant matrix:\n");
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Print operation counts
    printf("\nTotal Multiplications: %d\n", multiplications);
    printf("Total Additions: %d\n", additions);

    return 0;
}
