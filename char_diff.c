#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFSIZE 5000

int main() {
    char str1[BUFSIZE], str2[BUFSIZE], out1[BUFSIZE], out2[BUFSIZE];
    int i, j, len1, len2;

    fgets(str1, BUFSIZE, stdin);
    len1 = strlen(str1);
    fgets(str2, BUFSIZE, stdin);
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