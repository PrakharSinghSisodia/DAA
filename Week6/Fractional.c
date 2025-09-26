#include <stdio.h>
#include <stdlib.h>
struct Item {
    int value;
    int weight;
};
int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;

    double r1 = (double)item1->value / item1->weight;
    double r2 = (double)item2->value / item2->weight;

    
    if (r1 < r2) return 1;
    else if (r1 > r2) return -1;
    else return 0;
}

double fractionalKnapsack(int capacity, struct Item items[], int n) {
    
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0;

    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            
            totalValue += (double)items[i].value * capacity / items[i].weight;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;
    printf("Eneter number of items; ");
    scanf("%d", &n);

    struct Item items[n];
    printf("Enter value and weight of each item;\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &items[i].value);
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &items[i].weight);
    }
    printf("Eneter knapsack capacity; ");
    scanf("%d", &capacity);
    double maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);
    return 0;
}
