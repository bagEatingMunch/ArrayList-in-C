#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *values;
    size_t size;
    size_t max_capacity;
} ArrayList;

void arrayListInit(ArrayList *list, size_t initialCapacity){
    list -> values = malloc(sizeof(int) * initialCapacity);
    if (!list -> values){
        printf("Array shit the bed, failed to accomodate memory.");
    } else{
        list -> size = 0;
        list -> max_capacity = initialCapacity;
    }
}

static void arrayListResize(ArrayList *list, size_t newCapacity){
    int *temp = realloc(list -> values, newCapacity * sizeof(int));
    if(!temp){
        printf("Failed to resize");
    } else {
        list -> values = temp;
        list -> max_capacity = newCapacity;
    }
}

void append(ArrayList *list, int value){
    int newCapacity;
    if(list -> size == list ->max_capacity){
        if (list -> size == 0){
            newCapacity = 1;
        } else {
            newCapacity = (list -> max_capacity * 2);
        }
        arrayListResize(list, newCapacity);
    }
    list -> values[list -> size] = value;
    list -> size ++;
}

int getValueAtIndex(ArrayList *list, int index){
    if(index < list -> size && index >= 0){
        return list -> values[index];
    } else {
        printf("Please insert index in range [0,%d]",(list -> size) - 1);
    }
    return 0;
}

void setValueAtIndex(ArrayList *list, int index, int value){
    if(index < list -> size && index >= 0){
        list -> values[index] = value;
    } else {
        printf("Please insert index in range [0,%d]",(list -> size) - 1);
    }
}

int pop(ArrayList *list){
    int value;
    if(list -> size == 0){
        printf("No elements in ArrayList to pop");
    } else {
        value = list -> values[list -> size -1];
        list -> size--;
        return value;
    }
    return 0;
}

int removeIndexValue(ArrayList *list, int index){
    int poop;
    if(index < list -> size && index >= 0){
        poop = list -> values[index];
        for(int i = index; i < list -> size - 1; i++){
            list -> values[i] = list -> values[i+1];
        }
        list -> size--;
        return poop;
    }
    return 0;
}

int main()
{
    srand(22);
    ArrayList test;
    arrayListInit(&test, 10);
    for(int i = 0; i < 20; i++){
        append(&test,i);
    }
    for(int i = 0; i < 20; i++){
        printf("%d ",pop(&test));
    }
    printf("\n");
    for(int i = 0; i < 20; i++){
        append(&test,rand() % 11);
        printf("%d ",getValueAtIndex(&test,i));
    }
    setValueAtIndex(&test,4,21);
    printf("\n%d",getValueAtIndex(&test,4));
}
