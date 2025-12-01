#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char write_buf[] = "This is OS file system call test.\n";
    char read_buf[100];

    fd = open("testfile.txt", O_CREAT | O_RDWR, 0644);

    write(fd, write_buf, sizeof(write_buf));

    lseek(fd, 0, SEEK_SET);
    read(fd, read_buf, sizeof(read_buf));

    printf("Data read from file:\n%s", read_buf);

    close(fd);
    return 0;
}