#include <stdio.h>

int findOptimal(int pages[], int frames[], int n, int index, int m) {
    int pos = -1, farthest = index, i, j;
    for(i = 0; i < m; i++) {
        int found = 0;
        for(j = index; j < n; j++) {
            if(frames[i] == pages[j]) {
                if(j > farthest) {
                    farthest = j;
                    pos = i;
                }
                found = 1;
                break;
            }
        }
        if(found == 0)  // Page not referenced again
            return i;
    }
    if(pos == -1)
        return 0;
    return pos;
}

int main() {
    int frames[10], pages[30];
    int n, m, pageFaults = 0;
    int flag1, flag2, i, j, pos;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &m);

    for(i = 0; i < m; i++) {
        frames[i] = -1;
    }

    printf("\nPage\tFrames\t\tPage Fault\n");

    for(i = 0; i < n; i++) {
        flag1 = flag2 = 0;

        // Check if page is already in frame
        for(j = 0; j < m; j++) {
            if(frames[j] == pages[i]) {
                flag1 = flag2 = 1;
                break;
            }
        }

        // Page not found -> Page Fault
        if(flag1 == 0) {
            for(j = 0; j < m; j++) {
                if(frames[j] == -1) {
                    frames[j] = pages[i];
                    pageFaults++;
                    flag2 = 1;
                    break;
                }
            }
        }

        // If no empty frame -> replace using Optimal
        if(flag2 == 0 && flag1 == 0) {
            pos = findOptimal(pages, frames, n, i + 1, m);
            frames[pos] = pages[i];
            pageFaults++;
        }

        printf("%d\t", pages[i]);
        for(j = 0; j < m; j++) {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }

        if(flag1 == 0)
            printf("\t\tYes");
        else
            printf("\t\tNo");
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}