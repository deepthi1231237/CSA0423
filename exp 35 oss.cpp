#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, indexBlock, fileBlocks, i, j;
    int blocks[50]; // 0 = free, 1 = allocated

    // Initialize disk blocks
    printf("Enter the total number of disk blocks: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        blocks[i] = 0; // all blocks free initially
    }

    // Choose an index block
    printf("Enter the index block number (0 to %d): ", n - 1);
    scanf("%d", &indexBlock);

    if (blocks[indexBlock] == 1) {
        printf("Index block already allocated. Choose another.\n");
        return 0;
    }

    blocks[indexBlock] = 1; // allocate index block

    printf("Enter the number of blocks required for the file: ");
    scanf("%d", &fileBlocks);

    int allocated[fileBlocks];
    printf("Enter the block numbers for the file: ");
    for (i = 0; i < fileBlocks; i++) {
        scanf("%d", &allocated[i]);
        if (allocated[i] >= n || allocated[i] < 0) {
            printf("Invalid block number.\n");
            return 0;
        }
        if (blocks[allocated[i]] == 1) {
            printf("Block %d is already allocated. Allocation failed.\n", allocated[i]);
            return 0;
        }
    }

    // Allocate blocks
    for (i = 0; i < fileBlocks; i++) {
        blocks[allocated[i]] = 1;
    }

    // Display results
    printf("\nFile Indexed Allocation Table:\n");
    printf("Index Block: %d\n", indexBlock);
    printf("Blocks allocated:\n");

    for (i = 0; i < fileBlocks; i++) {
        printf("  %d -> %d\n", indexBlock, allocated[i]);
    }

    printf("\nAllocation successful!\n");
    return 0;
}