#include <stdio.h>
void output_arr(int arr[], int n) {
  for (int i = 0; i < n; ++i) { printf("%d ", arr[i]); }
  printf("\n");
}
/* 快速排序法 */
void quick_sort(int arr[], int first_index, int last_index) {
  // 宣告索引變數
  int pivotIndex, temp, index_a, index_b;

  if (first_index < last_index) {
    // 以第一個元素作為基準
    pivotIndex = first_index;
    index_a = first_index;
    index_b = last_index;

    // 以遞增方式排序
    while (index_a < index_b) {
      while (arr[index_a] <= arr[pivotIndex] && index_a < last_index) {
        index_a++;
      }
      while (arr[index_b] > arr[pivotIndex]) {
        index_b--;
      }

      if (index_a < index_b) {
        // 交換元素
        temp = arr[index_a];
        arr[index_a] = arr[index_b];
        arr[index_b] = temp;
      }
    }

    // 交換基準元素與 index_b 元素
    temp = arr[pivotIndex];
    arr[pivotIndex] = arr[index_b];
    arr[index_b] = temp;

    // 遞迴呼叫快速排序法函數
    quick_sort(arr, first_index, index_b - 1);
    quick_sort(arr, index_b + 1, last_index);
  }
}
int main() {
  int arr3[] = {3,2,1,7,6,5,9,8,7};
  printf("Quick Sort:\n");
  printf(" Before: \n  ");
  output_arr(arr3, 9);
  quick_sort(arr3, 0, 8);
  printf(" After: \n  ");
  output_arr(arr3, 9);

  return 0;
}


