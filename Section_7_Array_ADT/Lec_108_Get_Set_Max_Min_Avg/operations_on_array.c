# include <stdio.h>
# include <stdlib.h>

struct Array {
    int p[20];
    int size;
    int length;
};

int get(struct Array arr, int index) {
   if(index >=0 && index < arr.length) {
       return arr.p[index];
   } 
   return -1;
}

void set(struct Array* arr, int index, int value) {
    if(index >= 0 && index < arr->length) {
        arr ->p[index] = value;
    }
}

int max_array(struct Array arr) {
    int max = arr.p[0];
    for(int i = 1; i < arr.length; i++) {
        if(arr.p[i] > max)
            max = arr.p[i];
    }
    return max;
}

int min_array(struct Array arr) {
    int min = arr.p[0];
    for(int i = 1; i < arr.length; i++) {
        if(arr.p[i] < min)
            min = arr.p[i];
    }
    return min;
}

int sum_iterative(struct Array arr) {
    int total = 0;
    for(int i = 0; i < arr.length; i++) {
        total += arr.p[i];
    }
    return total;
}

int sum_recursive(struct Array arr, int n) {
    if(n < 0) {
        return 0;
    } else {
        return sum_recursive(arr, n-1) + arr.p[n];
    }
}

float avg(struct Array arr) {
    int total = sum_iterative(arr);
    return (float)(total/arr.length);
}

int main(int argc, char const *argv[])
{
    struct Array arr = {{2,3,4,6,7}, 20, 5};

    printf("get value %d", get(arr, 2));
    set(&arr, 2, 15);
    printf("Max value in array %d", max_array(arr));
    printf("Min value in array %d", min_array(arr));
    printf("Sum of values in array %d", sum_recursive(arr, arr.length-1));
    printf("Average of values in array %d", avg(arr));

    return 0;
}