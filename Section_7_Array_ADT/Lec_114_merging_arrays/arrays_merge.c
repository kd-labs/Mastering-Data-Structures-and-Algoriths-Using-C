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

struct Array* merge_array(struct Array* arr1, struct Array* arr2) {
    int i,j,k;
    i=j=k=0;

    struct Array* arr3 = (struct Array*)(malloc(sizeof(struct Array)));

    while(i < arr1->length && j < arr2->length) {
        if(arr1->p[i] < arr2->p[j])
            arr3->p[k++] = arr1->p[i++];
        else
            arr3->p[k++] = arr2->p[j++];
    }
    for(;i < arr1->length;i++)
        arr3->p[k++] = arr1->p[i];

    for(;j < arr2->length;j++)
        arr3->p[k++] = arr2->p[j];
    
    arr3->length = arr1->length + arr2->length;
    arr3->size = arr1->length + arr2->length;

    return arr3;
}


int main(int argc, char const *argv[])
{
    struct Array arr1 = {{2, 6, 10, 15, 25, 30, 55}, 20, 7};
    struct Array arr2 = {{4, 8, 13, 16, 20 ,22, 28, 33}, 20, 8};
    struct Array* merged_arr = merge_array(&arr1, &arr2);

    display(*merged_arr);

    return 0;
}