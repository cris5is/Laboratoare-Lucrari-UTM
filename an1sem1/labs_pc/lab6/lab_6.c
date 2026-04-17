#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);
    int count[26] = {0};
    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) count[(tolower(str[i])) - 'a']++;
    }
    for (int i = 0; i < 26; i++)
        if (count[i] != 0) printf("%c - %d\n", (char) ('a' + i), count[i]);

    return 0;
}