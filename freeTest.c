#include <stdlib.h>
#include "mymalloc.h"

int main()
{
        int *ptr = malloc(sizeof(int));
        if (ptr == NULL)
        {
                printf("Memory allocation failed.\n");
                return 1;
        }

        // Assign a value to the allocated memory
        *ptr = 42;

        // Print the value before freeing
        printf("Before free: *ptr = %d\n", *ptr);

        // Free the allocated memory
        free(ptr);

        // Attempt to access the memory after freeing
        printf("After free: *ptr = %d\n", *ptr);

        return 0;
}
