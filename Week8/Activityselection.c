#include <stdio.h>


void activitySelection(int start[], int finish[], int n) {
    int i, j;

    printf("\nSelected Activities are:\n");

    
    i = 0;
    printf("Activity %d (Start: %d, Finish: %d)\n", i + 1, start[i], finish[i]);

    
    for (j = 1; j < n; j++) {
        
        if (start[j] >= finish[i]) {
            printf("Activity %d (Start: %d, Finish: %d)\n", j + 1, start[j], finish[j]);
            i = j;  
        }
    }
}

int main() {
    int n;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    int start[n], finish[n];

    printf("Enter start times:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &start[i]);

    printf("Enter finish times:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &finish[i]);

    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (finish[j] > finish[j + 1]) {
                int temp = finish[j];
                finish[j] = finish[j + 1];
                finish[j + 1] = temp;

                temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;
            }
        }
    }

    
    activitySelection(start, finish, n);

    return 0;
}
