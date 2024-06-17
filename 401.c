#include <stdio.h>
#include <string.h>

int has_rev(char ch)
{
    switch(ch) {
        case 'A':
        case 'E':
        case 'H':
        case 'I':
        case 'J':
        case 'L':
        case 'M':
        case 'O':
        case 'S':
        case 'T':
        case 'U':
        case 'V':
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
        case '1':
        case '2':
        case '3':
        case '5':
        case '8':
            return 1;
        default :
            return 0;
    }
}

char rev(char ch)
{
    switch(ch) {
        case 'A': return 'A';
        case 'E': return '3';
        case 'H': return 'H';
        case 'I': return 'I';
        case 'J': return 'L';
        case 'L': return 'J';
        case 'M': return 'M';
        case 'O': return 'O';
        case 'S': return '2';
        case 'T': return 'T';
        case 'U': return 'U';
        case 'V': return 'V';
        case 'W': return 'W';
        case 'X': return 'X';
        case 'Y': return 'Y';
        case 'Z': return '5';
        case '1': return '1';
        case '2': return 'S';
        case '3': return 'E';
        case '5': return 'Z';
        case '8': return '8';

        default : return 0;
    }
}

int main ()
{
    int i, j, palin, mirror;
    char str[200], str2[200], str3[200];

    while(gets(str)) {

        for(i=0; i<strlen(str); i++) if (str[i]=='0') str[i]='O';

        j=0;
        for(i=strlen(str)-1; i>=0; i--) str2[j++]=str[i];
        str2[j]='\0';
        if (strcmp(str, str2)==0) palin=1;
        else palin=0;

        for(i=0; i<strlen(str); i++) {
            if (has_rev(str[i])==1) str3[i]=rev(str[i]);
            else break;
        }
        str3[i]='\0';
        if (strcmp(str2, str3)==0) mirror=1;
        else mirror=0;

        if (palin==0 && mirror==0) printf("%s -- is not a palindrome.\n\n", str);
        else if (palin==1 && mirror==0) printf("%s -- is a regular palindrome.\n\n", str);
        else if (palin==0 && mirror==1) printf("%s -- is a mirrored string.\n\n", str);
        else if (palin==1 && mirror==1) printf("%s -- is a mirrored palindrome.\n\n", str);
    }

    return 0;
}
