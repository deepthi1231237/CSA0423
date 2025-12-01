#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int fd;
    struct stat fileStat;
    struct dirent *de;
    DIR *dr;
    char buffer[100];

    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);
    write(fd, "OS Lab System Call Test", 23);

    printf("\nFile Descriptor: %d\n", fd);

    // lseek + read
    lseek(fd, 0, SEEK_SET);
    read(fd, buffer, 23);
    printf("File Content: %s\n", buffer);

    // stat
    stat("sample.txt", &fileStat);
    printf("File Size: %ld bytes\n", fileStat.st_size);

    // Directory listing
    dr = opendir(".");
    printf("\nFiles in Current Directory:\n");
    while ((de = readdir(dr)) != NULL)
        printf("%s\n", de->d_name);

    close(fd);
    closedir(dr);
    return 0;
}