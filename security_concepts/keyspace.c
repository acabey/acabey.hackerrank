#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char numer_char_rotate(char cInpChar, int iKey)
{
    //Subtract '0' to get normalized numeric index
    if ((cInpChar <= '9') && (cInpChar >= '0')) { return (char) (((cInpChar-'0'+iKey) % 10)+'0'); }
    else {return cInpChar;}
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char *plainLine = NULL;
    char *keyLine = NULL;
    size_t plainSize = 0;
    size_t keySize = 0;
    int key = 0;
    
    if (getline(&plainLine, &plainSize, stdin) == -1) {
        return 1;
    }
    
    if (getline(&keyLine, &keySize, stdin) == -1) {
        return 1;
    }
    
    key = strtol(keyLine, NULL, 10);
    
    for (int i = 0; i < strlen(plainLine); ++i)
    {
        plainLine[i] = numer_char_rotate(plainLine[i], key);
    }
    printf("%s\n", plainLine);
}