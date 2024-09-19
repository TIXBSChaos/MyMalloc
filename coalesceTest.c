#include <stdlib.h>
#include "mymalloc.h"

typedef struct twoints
{
        int one;
        int two;
} twoints;

int main()
{
        int *ptrArray[5];

        for(int i=0; i<5; i++)
                ptrArray[i] = malloc(sizeof(int));

        int *expectedPosition = ptrArray[1];

        for(int i=1; i<4; i++)
                free(ptrArray[i]);

        twoints *test = malloc(sizeof(twoints));

        printf("Expected Position: %p\nActual position: %p\n", expectedPosition, test);

        if((char*)test == (char*)expectedPosition)
                printf("Coalesce test successful!\n");
        return 0;
}
