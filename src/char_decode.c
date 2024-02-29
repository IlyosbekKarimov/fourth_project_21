#include <stdio.h>

void encode();
void decode();

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("n/a");
        return 0;
    }
    if (argv[1][0] == '0') {
        encode();
    } else if (argv[1][0] == '1') {
        decode();
    } else {
        printf("n/a");
    }
    return 0;
}

void encode() {
    while (1) {
        char c = getchar();
        char new_line = getchar();
        if (new_line != ' ' && new_line != '\n') {
            printf("n/a");
            return;
        }
        if (new_line == '\n') {
            printf("%X\n", c);
            break;
        } else {
            printf("%X ", c);
        }
    }
}

void decode() {
    int c;
    char space;
    while (scanf("%X%c", &c, &space) != EOF) {
        if (space != ' ' && space != '\n') {
            printf("n/a");
            return;
        }
        if (c > 127 || c < 0) {
            printf("n/a");
            return;
        }

        if (space == '\n') {
            printf("%c\n", c);
            break;
        } else {
            printf("%c ", c);
        }
    }
}