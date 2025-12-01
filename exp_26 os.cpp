#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f1, *f2;
    char ch;

    // Create and Write
    f1 = fopen("file1.txt", "w");
    fprintf(f1, "Operating Systems Lab Practice\n");
    fclose(f1);

    // Read and Display
    f1 = fopen("file1.txt", "r");
    printf("Contents of file1.txt:\n");
    while ((ch = fgetc(f1)) != EOF)
        putchar(ch);
    fclose(f1);

    // Copy file
    f1 = fopen("file1.txt", "r");
    f2 = fopen("copy.txt", "w");
    while ((ch = fgetc(f1)) != EOF)
        fputc(ch, f2);
    fclose(f1);
    fclose(f2);

    // Delete file
    remove("file1.txt");
    printf("\nfile1.txt deleted.\n");

    return 0;
}