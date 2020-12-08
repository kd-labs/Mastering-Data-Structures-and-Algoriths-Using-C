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

struct Array* union_unsorted(struct Array arrA, struct Array arrB) {
    struct Array* arrC = (struct Array*)malloc(sizeof(struct Array));
    int k=0;
    for(int i=0;i<arrA.length;i++,k++) {
        arrC->p[k] = arrA.p[i];
    }
    arrC->length = k;

    for(int i=0;i<arrB.length;i++) {
        int k = 0;
        for(;k<arrC->length;k++){
            if(arrB.p[i] == arrC->p[k])
                break;
        }
        if(arrB.p[i] == arrC->p[k]){
            continue;
        }
        arrC->p[arrC->length] = arrB.p[i];
        arrC->length++;
    }
    return arrC;

}

struct Array* union_sorted(struct Array arrA, struct Array arrB) {
    struct Array* arrC = (struct Array*)malloc(sizeof(struct Array));
    int i=0,j=0,k=0;
    while(i < arrA.length && j < arrB.length) {
        if(arrA.p[i] < arrB.p[j]){
            arrC->p[k++] = arrA.p[i++];
        } else if(arrA.p[i] > arrB.p[j]) {
            arrC->p[k++] = arrB.p[j++];
        } else if(arrA.p[i] == arrB.p[j]){
            arrC->p[k++] = arrA.p[i++];
            j++;
        }
    }
    for(;i<arrA.length;i++){
        arrC->p[k++] = arrA.p[i];
    }
    for(;j<arrB.length;j++) {
        arrC->p[k++] = arrB.p[j];
    }
    arrC->length=k, arrC->size=k;

    return arrC;
}

int main(int argc, char const *argv[])
{
    struct Array arrA = {{3, 5, 10, 4, 6}, 20, 5};
    struct Array arrB = {{12, 4, 7, 2, 5}, 20, 5};
    struct Array* arrC = union_unsorted(arrA, arrB);
    display(*arrC);

    struct Array sorted_arrA = {{3, 4, 5, 6, 10, 12, 14, 18}, 20, 8};
    struct Array sorted_arrB = {{4, 7, 9, 12, 15, 18}, 20, 6};
    struct Array* arrD = union_sorted(sorted_arrA, sorted_arrB);
    display(*arrD);

    return 0;
}
