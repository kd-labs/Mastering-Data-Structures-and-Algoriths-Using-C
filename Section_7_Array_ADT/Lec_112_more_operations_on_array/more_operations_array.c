# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

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

void insert_sort(struct Array* arr, int value) {
    if(arr->length == arr->size){
        return;
    }
    int i = arr->length-1;
    while(i >= 0 && value < arr->p[i]){
        arr->p[i+1] = arr->p[i];
        i--;
    }
    arr->p[i+1] = value;
    arr->length += 1;
}

bool isSorted(struct Array arr) {
    for(int i = 0; i < arr.length-1; i++) {
        if(arr.p[i] > arr.p[i+1])
            return false;
    }
    return true;
}

void negative_on_one_side(struct Array* arr) {
    int i = 0, j = arr->length-1, tmp;

    while(i < j) {
        while(arr->p[i] < 0) {i++;}
        while(arr->p[j]>=0) {j--;}
        if(i < j) {
            tmp = arr->p[i];
            arr->p[i] = arr->p[j];
            arr->p[j] = tmp;
        }
    }
}

int main(int argc, char const *argv[])
{
    struct Array arr = {{4, 8, 13, 16, 20 ,25, 28, 33}, 20, 8};
    struct Array unsorted = {{4, 8, 13, 16, 20 ,29, 28, 33}, 20, 8};
    struct Array negative = {{-6, 3, -8, 10, 5 , -7, -9, 12, -4, 2}, 20, 10};

    display(arr);
    insert_sort(&arr, 18);
    display(arr);

    display(negative);
    negative_on_one_side(&negative);
    display(negative);

    printf("\nTest : is the array sorted ? : %s", isSorted(unsorted) ? "true" : "false");

    return 0;
}