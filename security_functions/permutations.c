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
    
    
    //Find each f(f(x))
    /*
    For each index value (indices should be increased by 1), find the value of f(index)
    I have a list of the outputs where the input is their index + 1
    For each value in the list of f(x), get its y output list[index] and find the f(y)
    There should be far more error checking here, but it's abstract so whatever
    */
    for (int i = 0; i < n; ++i)
    {
        printf("%i\n", piFArray[piFArray[i]-1]);
    }
    
    return 0;
}
