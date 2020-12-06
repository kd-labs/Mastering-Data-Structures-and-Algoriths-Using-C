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

int delete(struct Array * arr, int index) {
    int x = 0;
    if(index > 0 && index <= arr->length-1) {
        x = arr->p[index];
        int i = 0;
        for(i = index; i < arr->length-1; i++) {
            arr->p[i] = arr->p[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
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

    delete(&arr, 4);
    display(arr);

    return 0;
}
