#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[20], n, head, i, j, seek = 0, temp, maxRange;
    int direction;

    printf("Enter the maximum range of the disk: ");
    scanf("%d", &maxRange);

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request sequence: ");
    for(i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the head movement direction (1 for high, 0 for low): ");
    scanf("%d", &direction);

    // Add start and end boundaries
    queue[n++] = 0;
    queue[n++] = maxRange - 1;

    // Sort the request queue
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(queue[j] > queue[j + 1]) {
                temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }

    // Find head position
    int index;
    for(i = 0; i < n; i++) {
        if(queue[i] > head) {
            index = i;
            break;
        }
    }

    printf("\nHead Movement Sequence:\n");
    if(direction == 1) { // Move towards higher values
        for(i = index; i < n; i++) {
            printf("%d -> ", queue[i]);
        }
        for(i = 0; i < index; i++) {
            printf("%d -> ", queue[i]);
        }
        // Total head movement calculation
        seek = (maxRange - 1 - head) + (maxRange - 1) + queue[index - 1];
    } 
    else { // Move towards lower values
        for(i = index - 1; i >= 0; i--) {
            printf("%d -> ", queue[i]);
        }
        for(i = n - 1; i >= index; i--) {
            printf("%d -> ", queue[i]);
        }
        // Total head movement calculation
        seek = head + (maxRange - 1) + (maxRange - 1 - queue[index]);
    }

    printf("\n\nTotal Head Movement = %d\n", seek);
    printf("Average Seek Time = %.2f\n", (float)seek / (n - 2)); // excluding added 0 and max

    return 0;
}