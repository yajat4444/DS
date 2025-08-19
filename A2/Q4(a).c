#include <stdio.h>
#include <string.h>
int main() {
    char s1[100], s2[100];
    scanf("%s", s1);
    scanf("%s", s2);
    strcat(s1, s2);
    printf("%s", s1);
    return 0;
}
