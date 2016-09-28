#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <alloca.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char *line = NULL;
    size_t size = 0;
    int n;
    
    if ((getline(&line, &size, stdin) == -1) || !(n = strtol(line, NULL, 10))) {
        return 1;
    }
    
    size_t sTermSize = sizeof n * n;
    int * piFArray = alloca(sTermSize);
    
    //Fill array
    if (getline(&line, &size, stdin) == -1) {
        return 1;
    }
    
    char *endToken = line;
    for (int i = 0; i < n; ++i)
    {
        piFArray[i] = strtol(endToken, &endToken, 10);
    }
    
    
    int isBijection = 1;
    for (int i = 0; i < n; ++i)
    {   
        for (int q = n-1; q > i; --q)
        {
           if (piFArray[i] == piFArray[q]) {isBijection = 0;} 
        }
    }
    
    if (isBijection) {printf("YES\n");}
    else {printf("NO\n");}
    
    return 0;
}
