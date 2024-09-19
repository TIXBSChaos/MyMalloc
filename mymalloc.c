#include "mymalloc.h"

#define MEMLENGTH 4096

static double memory[MEMLENGTH];

typedef struct chunk
{
        int size;
        int free;
}chunk;

void* mymalloc(unsigned int size, char *file, int line)
{
        if(size == 0)
        {
                printf("Error: Can not allocate 0 bytes!\n In:%s\tOn line:%d\n",file,line);
                return NULL;
        }

        if(size > MEMLENGTH*8)
        {
                printf("Error: Attempting to allocate more space than allowed!\n In:%s\tOn line:%d\n",file,line);
                return NULL;
        }

        size = (size+7) & ~7;

        char* endHeap = (char *)(&memory[MEMLENGTH-1]);
        chunk* currChunk = (chunk*)memory;

        if(currChunk->size == 0) /*Need to initiallize mem*/
        {
                currChunk->size = sizeof(memory);
                currChunk->free = 1;
        }

        while(currChunk < endHeap)
        {
                if(currChunk->free == 1 && currChunk->size >= (size+sizeof(chunk)))
                {
                        int spaceLeftOver = currChunk->size - (sizeof(chunk)+size);
                        currChunk->size = sizeof(chunk)+size;
                        currChunk->free = 0;
                        void* res = (void*)currChunk + sizeof(chunk);
                        currChunk = (chunk*)(( currChunk) + size + sizeof(chunk));
                        if(spaceLeftOver > 7)
                        {
                                currChunk->size = spaceLeftOver;
                                currChunk->free = 1;
                        }
                        return res;
                }
                currChunk = currChunk->size + currChunk;
        }

        printf("Error: Not enough space or something went wrong!\n In:%s\tOn line:%d\n",file,line);
        return NULL;
}

void myfree(void *ptr, char *file, int line){

        if(ptr == NULL){
                printf("Error: The given pointer is null!\n In:%s\tOn line:%d\n",file,line);
                exit(1);
        }

        if(((char*)ptr)<((char*)memory) || ((char*)ptr)>(((char*)memory)+sizeof(memory)))
        {
                printf("Error: The given pointer is not in the heap!\n In:%s\tOn line:%d\n",file,line);
                exit(1);
        }

        chunk* startHeap = (chunk*)memory;
        chunk* prevChunk = NULL;
        chunk* givenChunk = ptr-sizeof(chunk);
        chunk* endHeap = (chunk*)(&memory[MEMLENGTH-1]);
        int foundChunk = 0; //false by default

        while(startHeap < endHeap)
        {
                //freeing the given chunk if found
                if(startHeap == givenChunk)
                {
                       // printf("\n\nFOUND CHUNK %x\n\n\n",givenChunk);
                        if(givenChunk->free == 1)
                        {
                                printf("Error: The given pointer is already free!\n In:%s\tOn line:%d\n",file,line);
                                exit(1);
                        }
                        givenChunk->free = 1;
                        foundChunk = 1;
                }

                //combining free chunks
                if(prevChunk != NULL)
                {
                        if(prevChunk->free == 0)
                                prevChunk = startHeap;
                }
                else
                        prevChunk = startHeap;

                if(startHeap->free == 0)
                        prevChunk = startHeap;
                else
                        if(prevChunk != startHeap && prevChunk->free == 1)
                                prevChunk->size = prevChunk->size + startHeap->size - sizeof(chunk);

                startHeap = (chunk*)(( (char*)startHeap + startHeap->size + sizeof(chunk)));
        }
        if(foundChunk == 0)
        {
                printf("Error: The given pointer is not at the start of a payload!\n In:%s\tOn line:%d\n",file,line);
                exit(1);
        }
}
