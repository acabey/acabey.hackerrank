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
    char *line = NULL;
    size_t size = 0;
    
    if (getline(&line, &size, stdin) == -1) {
        return 1;
    }
    
    for (int i = 0; i < strlen(line); ++i)
    {
        line[i] = numer_char_rotate(line[i], 1);
    }
    printf("%s\n", line);
}