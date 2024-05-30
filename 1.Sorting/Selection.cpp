
// select minimum and swap the values

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
  cout << "\n";
  cout << "After Sorting ";
  for (int i = 0; i <n - 1; i++) {
    int mini = i;
    for (int j = i; j < n; j++) {
      if (arr[j] < arr[mini])
        mini = j;
    }
    swap(arr[mini], arr[i]);
  }
  for (int val : arr)
    cout << val << " ";
}