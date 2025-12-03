#include <stdio.h>

struct directory {
    char dname[20];
    char files[20][20];
    int fcount;
} dir[10];

int main() {
    int nd, i, j;
    printf("Enter number of directories: ");
    scanf("%d", &nd);

    for (i = 0; i < nd; i++) {
        printf("Enter directory name: ");
        scanf("%s", dir[i].dname);

        printf("Enter number of files: ");
        scanf("%d", &dir[i].fcount);

        for (j = 0; j < dir[i].fcount; j++) {
            printf("Enter file %d: ", j+1);
            scanf("%s", dir[i].files[j]);
        }
    }

    printf("\n--- Directory Structure ---\n");
    for (i = 0; i < nd; i++) {
        printf("%s:\n", dir[i].dname);
        for (j = 0; j < dir[i].fcount; j++)
            printf("   %s\n", dir[i].files[j]);
    }

    return 0;
}
