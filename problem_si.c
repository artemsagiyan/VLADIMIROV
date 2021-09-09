#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void inssort(int *arr, int len);

int moveright(int *arr, int key, int last);

void get_num_arr(int *arr, int num);

void print_num_arr(int *arr, int num);

int main(int argc, char **argv) {

    int *arr = NULL;
    int len  = 0;

    scanf("%d", &len);

    arr = (int *)calloc(len, sizeof(int));

    get_num_arr(arr, len);

    inssort(arr, len);

    print_num_arr(arr, len);

    free(arr);
}

void get_num_arr(int *arr, int num) {
  
    for (int i = 0; i < num; ++i) {
      scanf("%d", &arr[i]);
    }
}

void print_num_arr(int *arr, int num) {
  
    for (int i = 0; i < num; ++i) {
      printf("%d ", arr[i]);
    }  

    printf("\n");
}

void inssort(int *arr, int len) {
    int i;

    for (i = 0; i < len; ++i) {
      int key, pos;
      key = arr[i];
      pos = moveright(arr, key, i);
      arr[pos] = key;
    }
}

int moveright(int *arr, int key, int last) {
    int ind = last;

    while(key < arr[ind - 1] && ind > 0) {
        arr[ind] = arr[ind - 1];
        ind--;        
    }
    return ind; 
}
