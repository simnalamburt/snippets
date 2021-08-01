#include <stdio.h>

static void quicksort(long arr[], int start, int end) {
  if (end - start <= 1) { return; }

  long pivot = arr[end - 1];
  int lo = start, hi = end - 1;
  while (lo < hi) {
    if (arr[lo] <= pivot) {
      ++lo;
    } else {
      --hi;
      long t = arr[hi];
      arr[hi] = arr[lo];
      arr[lo] = t;
    }
  }
  long t = arr[lo];
  arr[lo] = pivot;
  arr[end - 1] = t;

  quicksort(arr, start, lo);
  quicksort(arr, lo + 1, end);
}

static void mergesort(long arr[], int start, int end) {
  if (end - start <= 1) { return; }

  int mid = start + (end - start)/2;
  mergesort(arr, start, mid);
  mergesort(arr, mid, end);

  long tmp[end - start];
  int i = 0, a = start, b = mid;
  while (a < mid && b < end) { tmp[i++] = arr[arr[a] < arr[b] ? a++ : b++]; }
  while (a < mid) { tmp[i++] = arr[a++]; };
  while (b < end) { tmp[i++] = arr[b++]; };
  for (int i = 0; i < end - start; ++i) { arr[start + i] = tmp[i]; }
}

int main() {
  long A[18] = {1, 8, 4, 3, 8, 2, 1, 0, 11, 5, 8, 9, 4, 3, 2, 34, 45, 67};
  long B[18] = {1, 8, 4, 3, 8, 2, 1, 0, 11, 5, 8, 9, 4, 3, 2, 34, 45, 67};

  for (int i = 0; i < 18; ++i) { printf("%ld ", A[i]); } printf("\n");
  for (int i = 0; i < 18; ++i) { printf("%ld ", B[i]); } printf("\n");

  quicksort(A, 0, 18);
  mergesort(B, 0, 18);

  for (int i = 0; i < 18; ++i) { printf("%ld ", A[i]); } printf("\n");
  for (int i = 0; i < 18; ++i) { printf("%ld ", B[i]); } printf("\n");
}
