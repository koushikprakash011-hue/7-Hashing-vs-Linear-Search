/*
 * Q7: Hash Table using Division Method (Separate Chaining)
 * Song IDs: 105, 210, 315, 420, 525, 630, 735, 840
 * Table size = 10  ->  h(key) = key % 10
 */
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node {
    int key;
    struct Node *next;
} Node;

Node *table[TABLE_SIZE];
int collisionCount = 0;

int hashFunc(int key) {
    return key % TABLE_SIZE;
}

void displayTable(void) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("  [%d] -> ", i);
        Node *cur = table[i];
        if (!cur) printf("EMPTY");
        while (cur) {
            printf("%d ", cur->key);
            cur = cur->next;
        }
        printf("\n");
    }
}

void insert(int key) {
    int idx = hashFunc(key);
    Node *node = (Node*) malloc(sizeof(Node));
    node->key = key;
    node->next = NULL;

    if (table[idx] != NULL) {
        collisionCount++;
        printf("Collision! Key %d hashes to index %d (already occupied)\n", key, idx);
    }

    node->next = table[idx];
    table[idx] = node;

    printf("Inserted %d at index %d\n", key, idx);
    printf("Table state after inserting %d:\n", key);
    displayTable();
    printf("--------------------------------------\n");
}

int hashSearch(int key, int *comparisons) {
    int idx = hashFunc(key);
    Node *cur = table[idx];
    *comparisons = 0;
    while (cur) {
        (*comparisons)++;
        if (cur->key == key) return 1;
        cur = cur->next;
    }
    return 0;
}

int linearSearch(int arr[], int n, int key, int *comparisons) {
    *comparisons = 0;
    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (arr[i] == key) return 1;
    }
    return 0;
}

int main(void) {
    int songIDs[] = {105, 210, 315, 420, 525, 630, 735, 840};
    int n = sizeof(songIDs) / sizeof(songIDs[0]);

    for (int i = 0; i < TABLE_SIZE; i++) table[i] = NULL;

    printf("=========== INSERTION PHASE ===========\n");
    for (int i = 0; i < n; i++) {
        insert(songIDs[i]);
    }

    printf("\nTotal collisions during insertion: %d\n", collisionCount);
    double loadFactor = (double) n / TABLE_SIZE;
    printf("Load factor (n/m) = %d / %d = %.2f\n\n", n, TABLE_SIZE, loadFactor);

    printf("=========== SEARCH PHASE ===========\n");
    int searchIDs[] = {735, 420, 105, 999};
    int m = sizeof(searchIDs) / sizeof(searchIDs[0]);

    printf("%-10s %-15s %-20s %-15s %-20s\n",
           "Key", "Hash Found?", "Hash Comparisons", "Linear Found?", "Linear Comparisons");
    for (int i = 0; i < m; i++) {
        int hc, lc;
        int hf = hashSearch(searchIDs[i], &hc);
        int lf = linearSearch(songIDs, n, searchIDs[i], &lc);
        printf("%-10d %-15s %-20d %-15s %-20d\n",
               searchIDs[i], hf ? "Yes" : "No", hc, lf ? "Yes" : "No", lc);
    }

    return 0;
}
