#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 5000

int main() {
    char str1[BUFFER_SIZE], str2[BUFFER_SIZE], out1[BUFFER_SIZE], out2[BUFFER_SIZE];
    int i, j, len1, len2;

    fgets(str1, BUFFER_SIZE, stdin);
    len1 = strlen(str1);
    fgets(str2, BUFFER_SIZE, stdin);
    len2 = strlen(str2);
    if (str1[len1-1] == '\n') {
        str1[len1-1] = '\0';
        len1--;
    }
    if (str2[len2-1] == '\n') {
        str2[len2-1] = '\0';
        len2--;
    }


    for (i = 0; i < len1; i++) {
        if (strchr(str2, str1[i]) == NULL && strchr(out1, str1[i]) == NULL) {
            strncat(out1, &str1[i], 1);
        }
    }

    for (i = 0; i < len2; i++) {
        if (strchr(str1, str2[i]) == NULL && strchr(out2, str2[i]) == NULL) {
            strncat(out2, &str2[i], 1);
        }
    }

    printf("%s\n%s", out1, out2);
    return 0;
}