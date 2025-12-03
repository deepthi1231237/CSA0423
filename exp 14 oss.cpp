#include <stdio.h>
#include <string.h>

struct file {
    char name[20];
} f[20];

int main() {
    int n, i;
    printf("Enter number of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter file name: ");
        scanf("%s", f[i].name);
    }

    printf("\nFiles in directory:\n");
    for (i = 0; i < n; i++)
        printf("%s\n", f[i].name);

    return 0;
}
