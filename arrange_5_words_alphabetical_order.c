#include <stdio.h>

int strcompare(char* s1, char* s2){
    // ASCII of space is 32 and null is 0
    int i =0;
    for (;;i++){
        if (s1[i]<s2[i]) return -1;
        else if(s1[i]>s2[i]) return 1;
        if (s1[i]=='\0' || s2[i]=='\0') break;
    }
    return 0;
}

void strcopy(char *s1, char *s2){
    int i;
    for (i=0;s2[i]!='\0';i++) s1[i] = s2[i];
    s1[i] = '\0';
}

int main(){

    char strlist[5][20], temp[20];
    // char* strlist[5], *temp;
    int i, j, n=5;
    for (i=0;i<5;i++) gets(strlist[i]);
    for (i=1;i<n;i++){
        for (j=0;j<n-i;j++){
            if (strcompare(strlist[j], strlist[j+1])==1){
                strcopy(temp, strlist[j]);
                strcopy(strlist[j], strlist[j+1]);
                strcopy(strlist[j+1], temp);
            }
        }
    }
    for (i=0;i<5;i++) printf("%s\n", strlist[i]);
}
