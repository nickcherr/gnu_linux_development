#include <stdio.h>
#include <stdlib.h>

void help() {
    printf("Usage: range [M] [N] [S]\n");
    printf("Generates an arithmetic progression, works like Python function range().\n");
    printf("Number of passed parameters must be between 1 and 3.\n");
    printf("All parameters must be integers.\n");
    printf("With one parameter N, it prints the sequence [0, 1, ..., N-1]\n");
    printf("With two parameters M and N, it prints the sequence [M, M+1, ..., N-1]\n");
    printf("With three parameters M, N, and S, it prints the sequence [M, M+S, M+2S, ..., N-1]\n");
}

int main(int argc, char *argv[]) {
    int start = 0, end, diff = 1;
    if (argc == 2) {
        end = atoi(argv[1]); 
    } else if (argc == 3) {
        start = atoi(argv[1]);
        end = atoi(argv[2]);
    } else if (argc == 4) {
        start = atoi(argv[1]);
        end = atoi(argv[2]);
        diff = atoi(argv[3]);
    } else {
        help();
        return 1;
    }

    for (int i = start; i < end; i += diff) {
        printf("%d\n", i);
    }

    return 0;
}
