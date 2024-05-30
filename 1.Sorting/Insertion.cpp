#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << "Before Sorting ";
  for (int val : arr)
    cout << val << " ";
  cout << endl;
  cout << "After Sorting ";
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j > 0 and arr[j - 1] > arr[j]) {
      swap(arr[j - 1], arr[j]);
      j--;
    }
  }
  for (int val : arr)
    cout << val << " ";
}