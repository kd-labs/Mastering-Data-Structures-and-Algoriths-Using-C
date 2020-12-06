# include <stdlib.h>
# include <stdio.h>

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

int Binary_Search_Iterative(struct Array arr, int key) {
    int l = 0, mid, h = arr.length-1;

    while(l <= h) {
        mid = (l + h)/2;

        if(key == arr.p[mid])
            return mid;
        else if(key < arr.p[mid]) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int Binary_Search_Recursive(struct Array arr, int l, int h, int key) {

    int mid = (l + h)/2;
    
    if(l <= h) {
        if (key == arr.p[mid]) {
            return mid;
        }
        else if (key < arr.p[mid]) {
            return Binary_Search_Recursive(arr, l, mid - 1, key);
        }
        else {
            return Binary_Search_Recursive(arr, mid + 1, h, key);
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    struct Array arr = {{2,3,4,6,7}, 20, 5};

    printf("\nThe key is found at index : %d", Binary_Search_Iterative(arr, 6));
    printf("\nThe key is found at index : %d", Binary_Search_Recursive(arr, 0, arr.length-1, 10));

    return 0;
}