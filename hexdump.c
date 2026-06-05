#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>

int main (int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        fprintf(stderr, "%s: cannot open '%s': %s\n", argv[0], argv[1], strerror(errno));
        return 1;
    }

    unsigned char buffer[16];
    size_t bytes_read;
    size_t offset = 0;

    while ((bytes_read = fread(buffer, 1, 16, fp)) > 0) {

        printf("%08zx  ", offset);
        for (size_t i = 0; i < bytes_read; i++) {
            printf("%02x ", buffer[i]);
        }

        for (size_t k = bytes_read; k < 16; k++) {
            printf("   ");
        }

        printf("|");

        for (size_t j = 0; j < bytes_read; j++) {
            unsigned char c = buffer[j];
            if (isprint(c)){
                printf("%c", c);
            }
            else{
                printf(".");
            }
        }

        printf("|");
        printf("\n");

        offset += bytes_read;
    }

    //checking for error while reading into buffer.
    if (ferror(fp)) {
        perror("Error reading file");
        fclose(fp);
        return 1;
    }

    fclose(fp);
    return 0;


}