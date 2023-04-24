#include <stdio.h>

int main (int argc, char *argv[]) { 
    
    int fd_src = open(argv[1], O_RDONLY);
    int fd_resp = open(argv[2], O_WRONLY);



    return 0;
}
