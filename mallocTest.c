#include <stdlib.h>
#include "mymalloc.h"

typedef struct OneTwoEightByteArray
{
        int array[32];
} OTEBA;

int main()
{
        OTEBA *array1 = malloc(sizeof(OTEBA));
        for(int i=0; i<32; i++)
        {
                array1->array[i] = 1;
        }

        OTEBA *array2 = malloc(sizeof(OTEBA));
        for(int i=0; i<32; i++)
        {
                array2->array[i] = 2;
        }

        OTEBA *array3 = malloc(sizeof(OTEBA));
        for(int i=0; i<32; i++)
        {
                array3->array[i] = 3;
        }

        for(int i=0; i<33; i++)
        {
                if(i == 32)
                {
                        printf("Passed Malloc test!\n");
                }
                else if((array1->array[i] != 1) && (array2->array[i] != 2) && (array3->array[i] != 3))
                {
                        printf("Failed Malloc test on iteration: %d\n", i);
                }
        }
        return 0;
}
