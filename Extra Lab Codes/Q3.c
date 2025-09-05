#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to detect cycle in linked list and find the starting node of the cycle
struct Node* detectCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // move 1 step
        fast = fast->next->next;     // move 2 steps

        if (slow == fast) {          // Cycle detected
            // Find the starting node of the cycle
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // Starting node of the cycle
        }
    }
    return NULL; // No cycle
}

// Helper function to create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int main() {
    // Example: create a list
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    // Introduce cycle: 4 -> 2
    head->next->next->next->next = head->next;

    struct Node* cycleNode = detectCycle(head);

    if (cycleNode)
        printf("Cycle detected in linked list. Cycle starts at node with data: %d\n", cycleNode->data);
    else
        printf("No cycle in linked list\n");

    return 0;
}
