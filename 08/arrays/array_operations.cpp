#include "array_operations.hh"

int greatest_v1(int *itemptr, int size)
{
    int biggest = *itemptr;
    ++itemptr;
    for(int i = 1; i < size; ++i){
        if( *(itemptr + i) > biggest){
            biggest = *(itemptr + i);
        }
    }
    return biggest;
}

int greatest_v2(int *itemptr, int *endptr)
{
    int biggest = *itemptr;
    ++itemptr;
    while (itemptr != endptr) {
        if(*itemptr > biggest){
            biggest = *itemptr;
        }
        ++itemptr;
    }
    return biggest;
}

void copy(int *itemptr, int *endptr, int *targetptr)
{
    while (itemptr < endptr) {
        *targetptr = *itemptr;
        ++itemptr;
        ++targetptr;
    }
}

void reverse(int *leftptr, int *rightptr)
{
    --rightptr;
    while (leftptr < rightptr) {
        int temp = *leftptr;
        *leftptr = *rightptr;
        *rightptr = temp;

        --rightptr;
        ++leftptr;
    }
}
