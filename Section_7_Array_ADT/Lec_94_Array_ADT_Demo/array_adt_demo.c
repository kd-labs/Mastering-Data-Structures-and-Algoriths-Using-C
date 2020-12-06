# include <stdio.h>
# include <stdlib.h>

struct Array {
    int * p;
    int size;
    int length;
};

void display(struct Array arr) {
    printf("\nElements are : \n");
    for(int i = 0; i < arr.length; i++) {
        printf("%d\t", arr.p[i]);
    }
}


int main(int argc, char const *argv[])
{
    struct Array arr;
    int n;

    printf("Entr the size of the array\n");
    scanf("%d", &arr.size);

    arr.p = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("Enter the no of element to insert in array\n");
    scanf("%d", &n);

    printf("Enter the numbers\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr.p[i]);
    }
    arr.length = n;

    display(arr);

    return 0;
}
