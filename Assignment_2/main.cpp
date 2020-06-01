#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>

#define START_CMD    0
#define STOP_CMD     1
#define RESTART_CMD  2
#define STATUS_CMD   3
#define EXIT_CMD     4
#define BLANK        5
#define ERROR        -1

void trim(char *, char *);

char *strlower(char *);

char *inputString(FILE *, size_t);

using namespace std;

char *command[] = {"start", "stop", "restart", "status", "exit"};

int main() {
    char *input;
    char ch;
    bool valid;
    cout << "> ";
    while (true) {
        input = inputString(stdin, 100);
        trim(input, input);
        input = strlower(input);
        int instruction = -1;
        for (int i = 0; i < 5; i++) {
            if (strcmp(input, command[i]) == 0)instruction = i;
        }
        if (strcmp(input, "\0") == 0)instruction = 5;
        switch (instruction) {
            case START_CMD:
                cout << "command start recognized\n";
                break;
            case STOP_CMD:
                cout << "command stop recognized\n";
                break;
            case RESTART_CMD:
                cout << "command restart recognized\n";
                break;
            case STATUS_CMD:
                cout << "command status recognized\n";
                break;
            case EXIT_CMD:
                free(input);
                input = NULL;
                return 0;
            case BLANK:
                break;
            case ERROR:
                cout << "Invalid command\n";
        }
        cout << "> ";
    }
}

void trim(char *in, char *out) {
    int i, j;
    i = 0;
    j = strlen(in) - 1;
    while (isspace(in[i]) && i <= j)
        ++i;

    while (isspace(in[j]) && i <= j)
        --j;
    strncpy(out, in + i, j - i + 1);
    out[j - i + 1] = '\0';
}

char *strlower(char *str) {
    char *orign = str;
    for (; *str != '\0'; str++)
        *str = tolower(*str);
    return orign;
}


//This function is found in Stackoverflow, the webside is: https://stackoverflow.com/questions/16870485/how-can-i-read-an-input-string-of-unknown-length
char *inputString(FILE *fp, size_t size) {
//The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = (char *) realloc(NULL, sizeof(char) * size);//size is start size
    if (!str)return str;
    while (EOF != (ch = fgetc(fp)) && ch != '\n') {
        str[len++] = ch;
        if (len == size) {
            str = (char *) realloc(str, sizeof(char) * (size += 16));
            if (!str)return str;
        }
    }
    str[len++] = '\0';
    return (char *) realloc(str, sizeof(char) * len);
}