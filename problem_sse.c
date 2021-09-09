#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void read_arr(int *arr, int len);

void write_arr(int *arr, int len);

void inssort(int *arr, int len, int key);

int point_min_elem(int *arr, int len, int key);

void swap(int *v_1, int *v_2);

int main() {

    int *arr = NULL;
    int len = 0;
    int key = 0;

    assert(scanf("%d", &len));
    
    arr = (int *)calloc(len, sizeof(int));
    read_arr(arr, len);
    assert(scanf("%d", &key));
   
    inssort(arr, len, key); 
    write_arr(arr, len);

    free(arr);
    
    return 0;
}

void read_arr(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        scanf("%d", &arr[i]);
    }
}


void write_arr(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
}

void inssort(int *arr, int len, int key) {
    int ind = key;
    int min = 0;

    for (int i = ind; i < len; ++i) {
        min = point_min_elem(arr, len, i);
        swap(arr + i, arr + min);
    }
}

void swap(int *v_1, int *v_2) {
    int tmp = *v_1;
    *v_1 = *v_2;
    *v_2 = tmp;
}

int point_min_elem(int *arr, int len, int key) {
    int min = key; 
    
    for (int i = key + 1; i < len; ++i) {
        if (arr[i] < arr[min])
            min = i;
    }
    return min;
}
