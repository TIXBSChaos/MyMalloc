#include <stdlib.h>
#include "mymalloc.h"

int main()
{
        int *p = malloc(sizeof(int)*2);
        free(p + 1);
        return 0;
}
