#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open %s\n", argv[1]);
        return 1;
    }

    unsigned char buffer[16];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, 16, fp)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            printf("%02x ", buffer[i]);
        }
        printf("\n");
    }


    fclose(fp);
    return 0;


}