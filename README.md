# HEXDUMP IMPLEMENTATION IN C

## MOTIVATION
This project is a way for me to learn C programming by working on actual projects. This is the first of such projects. The idea is to start from 'simpler' projects and moving to more complex ones while gaining strong knowledge in systems level thinking and programming.

## ABOUT PROJECT
This project is an implementation of a hexdump in C. A hexdump is a tool used for the representation of the individual bytes in a file in their hexadecimal format. This project reads 16 bytes at a time, prints an offset for the number of bytes read before starting the line, the hexadecimal representation of each byte followed by their ASCII equivalent. Unprintable bytes, however, are all represented by a period.
For files that don't have the total number of bytes being a multiple of 16, padding is included to replace the 'missing' bytes. This way the entire dump displays similar to a grid and it gives a much more fluid reading experience. The padding is demonstrated in the sample output.

## BUILD AND RUN
```
gcc -Wall -Wextra -Werror -std=c11 -o hexdump hexdump.c
./hexdump <filename>
```

## SAMPLE OUTPUT
```
00000000  54 68 69 73 20 69 73 20 61 20 73 6c 69 67 68 74 |This is a slight|
00000010  6c 79 20 6c 6f 6e 67 65 72 20 74 65 73 74 20 73 |ly longer test s|
00000020  74 72 69 6e 67 2e 0a                            |tring..|
```

## CURRENT LIMITATIONS
1. The dump can only read one file at a time.
2. The dump cannot read data entered on the command line.
3. The offset has 8 hexadecimal digits: it can read up to 4GB of data then start to misbehave.

