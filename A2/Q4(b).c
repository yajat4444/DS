#include <stdio.h>
#include <string.h>
int main() {
    char s[100];
    int i, n;
    scanf("%s", s);
    n = strlen(s);
    for(i = n-1; i >= 0; i--)
        printf("%c", s[i]);
    return 0;
}
