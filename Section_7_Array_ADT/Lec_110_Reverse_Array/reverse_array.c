# include <stdio.h>
# include <stdlib.h>

struct Array {
    int p[20];
    int size;
    int length;
};

void reverse_1(struct Array * arr) {
    int size = arr -> length;
    int* tmp = (int*)malloc(sizeof(int) * arr->length);

    for(int i = arr->length-1, j = 0; i >= 0; i--, j++) {
        tmp[j] = arr->p[i];
    }

    for(int i = 0; i < arr->length; i++) {
        arr->p[i] = tmp[i];
    }
}

void reverse_2(struct Array* arr) {
    int j = arr->length-1;
    int tmp;

    for(int i = 0; i <= (arr->length-1)/2; i++) {
        tmp = arr->p[i];
        arr->p[i] = arr->p[j];
        arr->p[j] = tmp;
        j--;
    }
}

void display(struct Array arr) {
    printf("\nElements are : \n");
    for(int i = 0; i < arr.length; i++) {
        printf("%d\t", arr.p[i]);
    }
}

int main(int argc, char const *argv[])
{
    struct Array arr = {{2,3,4,6,7}, 20, 5};
    display(arr);
    reverse_2(&arr);
    display(arr);

    return 0;
}