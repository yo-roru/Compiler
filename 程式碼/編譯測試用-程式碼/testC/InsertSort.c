#include <stdio.h>
void output_arr(int arr[], int n) {
  for (int i = 0; i < n; ++i) { printf("%d ", arr[i]); }
  printf("\n");
}
/* 插入排序法 */
void insertion_sort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
      int temp = arr[j];
      arr[j] = arr[j - 1];
      arr[j - 1] = temp;
      j--;
    }
  }
}
int main() {
  int arr[] = {3,2,1,7,6,5,9,8,7};
  printf("Insert Sort:\n");
  printf(" Before: \n  ");
  output_arr(arr, 9);
  insertion_sort(arr, 9);
  printf(" After: \n  ");
  output_arr(arr, 9);

  return 0;
}


