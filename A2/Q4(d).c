#include <stdio.h>
#include <string.h>
int main() {
    char s[100][100], temp[100];
    int i, j, n;
    printf("Enter how many strings: ");
    scanf("%d", &n);
    printf("Enter %d strings:\n", n);
    for(i = 0; i < n; i++)
        scanf("%s", s[i]);
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(strcmp(s[i], s[j]) > 0) {
                strcpy(temp, s[i]);
                strcpy(s[i], s[j]);
                strcpy(s[j], temp);
            }
        }
    }
    printf("\nStrings in alphabetical order:\n");
    for(i = 0; i < n; i++)
        printf("%s\n", s[i]);
    return 0;
}
