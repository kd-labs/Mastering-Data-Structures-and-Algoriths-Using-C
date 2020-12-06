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

void swap(int * x, int * y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int linear_search(struct Array * arr, int key) {
    for(int i = 0; i < arr->length; i++) {
        if(key == arr->p[i]) {
            // transposition
            // swap(&arr->p[i], &arr->p[i-1]);

            // move to front
            swap(&arr->p[i], &arr->p[0]);
            return i;
        }
    }
    return -1;
}

void append(struct Array * arr, int x) {
   if(arr->length < arr->size) {
       arr->p[arr->length++] = x;
   }
}

int main(int argc, char const *argv[])
{
    struct Array arr = {{4,3,2,6,7}, 20, 5};

    display(arr);

    printf("\nThe key is found at index : %d", linear_search(&arr, 6));

    display(arr);

    return 0;
}
