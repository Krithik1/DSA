using namespace std;
#include <vector>

void merge(vector<int> &arr, int start, int mid, int end) {
  int i = start;
  int j = mid+1;
  vector<int> newArr;
  while (i <= mid && j <= end) {
    if (arr[i] <= arr[j]) {
      newArr.push_back(arr[i]);
      i++;
    } else {
      newArr.push_back(arr[j]);
      j++;
    }
  }
  while (i <= mid) {
    newArr.push_back(arr[i]);
    i++;
  }
  while (j <= end) {
    newArr.push_back(arr[j]);
    j++;
  }
  for (int k = start; k <= end; k++) {
    arr[k] = newArr[k-start];
  }
}

void mergeSort(vector<int> &arr, int start, int end) {
  if (start < end) {
    int mid = (start+end)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
  }
}

void mergeSort(vector<int> &arr) {
  mergeSort(arr, 0, arr.size()-1);
}