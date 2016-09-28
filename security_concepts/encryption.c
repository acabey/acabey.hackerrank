#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int factorial(int n) 
{
    int f = 1;
    for(int i = 1; i <= n; i++)
    {
      f *= i;
    }
    return f;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char *line = NULL;
    size_t size = 0;
    
    if (getline(&line, &size, stdin) == -1) {
        return 1;
    }
    
    int n = strtol(line, NULL, 10);
    printf("%i\n", factorial(n));

    return 0;
}

