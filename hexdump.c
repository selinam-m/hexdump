#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

void hexdump(FILE *fp, long max_bytes);

int main (int argc, char *argv[]) {
    int c;
    long max_bytes = LONG_MAX;
    
    while ((c = getopt(argc, argv, "n:")) != -1) {
        switch (c)
        {
            case 'n':
                
                max_bytes = strtol(optarg, NULL, 10);
                break;
            default:
                fprintf(stderr, "Error: flag not recognised\n");
                exit(1);
        }
        
        
    }
    if (optind < argc) {
        FILE *fp = fopen(argv[optind], "rb");
        if (fp == NULL) {
            fprintf(stderr, "%s: cannot open '%s': %s\n", argv[0], argv[optind], strerror(errno));
            return 1;
        }

        hexdump(fp, max_bytes);

        fclose(fp);

    }
    else if (argc == optind) {
        
        hexdump(stdin, max_bytes);
    }
    else {
        fprintf(stderr, "Usage: %s [file]\n ", argv[optind]);
        return 1;
    }

    return 0;

}

void hexdump (FILE *fp, long max_bytes) {
    unsigned char buffer[16];
    size_t bytes_read;
    size_t offset = 0;
    long bytes_remaining = max_bytes;

    while (bytes_remaining > 0) {
        long chunk = (bytes_remaining < 16) ? bytes_remaining : 16;
        bytes_read = fread(buffer, 1, chunk, fp);
        if (bytes_read == 0) break;
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
        bytes_remaining -= bytes_read;
        
    }
    //checking for error while reading into buffer.
    if (ferror(fp)) {
        perror("Error reading file");
    }

}



        