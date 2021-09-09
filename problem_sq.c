#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void read_arr(int *arr, int len);
void write_arr(int *arr, int len);

void q_sort(int *arr, unsigned len);
unsigned partition (int *arr, unsigned low, unsigned high);
void qsort_impl(int *arr, unsigned low, unsigned high);

void swap(int *v_1, int *v_2); 

int main() {
    int *arr = NULL;
    int len = 0;

    assert(scanf("%d", &len));
    arr = (int *)calloc(len, sizeof(int));

    read_arr(arr, len);

    q_sort(arr, len);   

    write_arr(arr, len);

    return 0;

}

void qsort_impl(int *arr, unsigned low, unsigned high) {
  if (low >= high) return;
  unsigned pi = partition(arr, low, high);
  if (pi > low) qsort_impl(arr, low, pi - 1);
  qsort_impl(arr, pi + 1, high);
}

void q_sort(int *arr, unsigned len) {
  qsort_impl(arr, 0u, len - 1);
}

void swap(int *v_1, int *v_2) {
    int tmp = *v_1;
    *v_1    = *v_2;
    *v_2 = tmp;  
} 

unsigned partition (int *arr, unsigned low, unsigned high) {
    unsigned ind_l = low, ind_r = high;
    
    while(ind_l < ind_r) {
        if(arr[ind_l] < arr[ind_r]) ind_r--;
        else {
            swap(arr + ind_l, arr + ind_r);
            ind_l++;
            while(ind_l < ind_r) {
                if(arr[ind_r] > arr[ind_l]) ind_l++;
                else {
                    swap(arr + ind_r, arr + ind_l);
                    ind_r--;
                    break;
                }
            }
        } 
    } 
    return ind_l;
}

void read_arr(int *arr, int len) {
    for(int i = 0; i < len; ++i) {
        assert(scanf("%d", arr + i));
    }    
}

void write_arr(int *arr, int len) {
    for(int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");    
}
