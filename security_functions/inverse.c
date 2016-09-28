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
    
    
    //Find each f-1
    /*
    For each index value (indices should be increased by 1), find the corresponding value from f-1 list
    I have a list of the outputs where the input is their index + 1
    i = 1; f(1) > 2; find the i that corresponds to 2
    For each value in the list of f-1, get its x input (index + 1) and find the index that corresponds to that as an output
    */
    for (int i = 0; i < n; ++i)
    {
        for (int q = 0; q < n; ++q)
        {
            if (piFArray[q] == i+1) {printf("%i\n", q+1);}
        }
    }
    
    return 0;
}
