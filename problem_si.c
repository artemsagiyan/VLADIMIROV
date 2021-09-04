#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void inssort(int *arr, int len);

int moveright(int *arr, int key, int last);

int main() {

    
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

}