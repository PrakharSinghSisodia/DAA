#include <stdio.h>

int findMissing(int arr[], int n) {
    int total = n * (n + 1) / 2; // expected sum from 0 to n
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return total - sum; // missing number
}

int main() {
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements from range 0 to %d (with one missing):\n", n, n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int missing = findMissing(arr, n);
    printf("The missing number is: %d\n", missing);

    return 0;
}
