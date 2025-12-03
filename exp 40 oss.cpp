#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

void print_file_permissions(mode_t mode) {
    printf("File Permissions: ");

    // File type
    if (S_ISREG(mode))
        printf("-");
    else if (S_ISDIR(mode))
        printf("d");
#ifdef S_ISLNK       // Only compile this part if S_ISLNK exists
    else if (S_ISLNK(mode))
        printf("l");
#endif
    else
        printf("?");

    // Owner (user) permissions
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");

    // Group permissions
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");

    // Others permissions
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");

    printf("\n");
}

int main() {
    char filename[100];
    struct stat fileStat;

    printf("Enter the filename: ");
    scanf("%s", filename);

    // Get file information
    if (stat(filename, &fileStat) < 0) {
        perror("Error retrieving file information");
        exit(1);
    }

    // Display file permissions
    print_file_permissions(fileStat.st_mode);

    printf("\n--- File Permission Breakdown ---\n");
    printf("Owner (User): ");
    printf((fileStat.st_mode & S_IRUSR) ? "Read " : "");
    printf((fileStat.st_mode & S_IWUSR) ? "Write " : "");
    printf((fileStat.st_mode & S_IXUSR) ? "Execute " : "");
    printf("\n");

    printf("Group: ");
    printf((fileStat.st_mode & S_IRGRP) ? "Read " : "");
    printf((fileStat.st_mode & S_IWGRP) ? "Write " : "");
    printf((fileStat.st_mode & S_IXGRP) ? "Execute " : "");
    printf("\n");

    printf("Others: ");
    printf((fileStat.st_mode & S_IROTH) ? "Read " : "");
    printf((fileStat.st_mode & S_IWOTH) ? "Write " : "");
    printf((fileStat.st_mode & S_IXOTH) ? "Execute " : "");
    printf("\n");

    return 0;
}