# include <stdio.h>
# include <stdlib.h>

struct Array {
    int p[20];
    int size;
    int length;
};

void display(struct Array arr) {
    printf("\nElements are : \n");
    for(int i = 0; i < arr.length; i++) {
        printf("%d\t", arr.p[i]);
    }
}

void insert(struct Array * arr, int index, int x) {
    if(index > 0 && index < index <= arr->length) {
        for(int i = arr->length; i > index; i--) {
            arr->p[i] = arr->p[i-1];
        }
        arr->p[index] = x;
        arr->length++;
    }
}

void append(struct Array * arr, int x) {
   if(arr->length < arr->size) {
       arr->p[arr->length++] = x;
   }
}

int main(int argc, char const *argv[])
{
    struct Array arr = {{4,3,2,6,7}, 20, 5};

    append(&arr, 10);
    display(arr);
    insert(&arr, 3, 5);
    display(arr);

    return 0;
}
