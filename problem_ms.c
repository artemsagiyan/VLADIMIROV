#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void read_arr(int *arr, int len);
void write_arr(int *arr, int len); 

void merge_sort(int *arr, int n);
void merge(int *arr, int l, int m, int r);
void merge_sort_imp(int *arr, int l, int r);


int main() {
    int len = 0;
    int *arr = NULL;

    assert(scanf("%d", &len));
    arr = (int *)calloc(len, sizeof(int));
    assert(arr != NULL);

    read_arr(arr, len);
    merge_sort(arr, len);
    write_arr(arr, len);

    return 0;
}

void merge_sort_imp(int *arr, int l, int r) {
    if (l >= r) return;

    int m = (l + r) / 2;
    printf("m = %d\n", m);

    merge_sort_imp(arr, l, m);
    merge_sort_imp(arr, m + 1, r);
    merge(arr, l, m, r);
}

void merge_sort(int *arr, int n) {
    merge_sort_imp(arr, 0, n - 1);
}

void merge(int *arr, int l, int m, int r) {
    int *arr_copy = NULL;
    arr_copy = (int *)calloc(m, sizeof(int));
    assert(arr_copy != NULL);

    int ind_1 = l, ind_2 = r;
    int ind_point = 0;

    while(ind_1 <= m && ind_2 <= r) {
        if(arr[ind_1] <= arr[ind_2]) {
            arr_copy[ind_point] = arr[ind_1];
            ind_1++;
        }
        else {
            arr_copy[ind_point] = arr[ind_2];
            ind_2++;
        }
        ind_point++;
    }  

    for(int i = l; i <= m; ++i) {
        arr[i] = arr_copy[i];
    }
    for(int i = m + 1; i <= r; ++i) {
        arr[i] = arr_copy[i];
    }

    write_arr(arr, 5);

    free(arr_copy);
}

void read_arr(int *arr, int len) {
    for (int i = 0; i < len; ++i) 
        assert(scanf("%d", arr + i));
}

void write_arr(int *arr, int len) {
    for (int i = 0; i < len; ++i) 
        printf("%d ", arr[i]);
    printf("\n");
}
