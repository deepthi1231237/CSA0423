#include <stdio.h>

int main() {
    int blockSize[3] = {100, 500, 200};
    int processSize[3] = {120, 230, 90};
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (blockSize[j] >= processSize[i]) {
                printf("Process %d allocated to block %d\n", i, j);
                blockSize[j] -= processSize[i];
                break;
            }
        }
        if (j == 3)
            printf("Process %d not allocated\n", i);
    }
    return 0;
}
