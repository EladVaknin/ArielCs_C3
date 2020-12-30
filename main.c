#include <stdio.h>
#include "isort.h"

int main() 
    {
        int arr [4] = {0,4,5,2};
        shift_element (arr, 4);
        for(int i=0; i<4; i++)
        {
            printf("%d", arr[i]);
        }
    }