#include <stdio.h>
#include <string.h>
int main() {
    char s[100], r[100];
    int i, j = 0;
    gets(s);
    for(i = 0; s[i]; i++) {
        if(!(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||
             s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'))
            r[j++] = s[i];
    }
    r[j] = '\0';
    puts(r);
    return 0;
}
