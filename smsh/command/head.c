/* head.c - display the begin content of a file 
          - default 10 lines*/

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>


void oops(char*, char*);
int main(int ac, char* av[]) {
    int in_fd, n_chars;
    char c;
    int default_lines = 5;
    int count = 0;

    if (ac != 2) {
        fprintf(stderr, "usage: %s source\n", *av);
        exit(1);
    }

    /* open files */
    if ((in_fd = open(av[1], O_RDONLY)) == -1) {
        oops("Cannot open ", av[1]);
    }
   
    while ((n_chars = read(in_fd, &c, 1)) > 0) {
        if (c == '\n') {
            count++;
            if (count == 10) {
                break;
            }
        }
        else if (c == EOF) {
            break;
        }
        printf("%c", c);
    }
    printf("\n");

    if (close(in_fd) == -1) {
        oops("Error closing files","");
    }

    return 0;
}

void oops(char* s1, char* s2) {
    fprintf(stderr, "Error: %s", s1);
    perror(s2);
    exit(1);
}