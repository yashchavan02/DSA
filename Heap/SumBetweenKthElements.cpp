#include <iostream>
#include <queue>
using namespace std;

// kth smallest

int main() {
  int arr[] = {1, 4, 7, 9, 3, 2, 0};
  int size = sizeof(arr) / sizeof(arr[0]);
  int i, k1 = 2, k2 = 6, sumP1 = 0, sumP2 = 0;

  priority_queue<int> p1;
  priority_queue<int> p2;

  for (i = 0; i < k1; i++) {
    p1.push(arr[i]);
  }
  for (i = 0; i < k2 - 1; i++) {
    p2.push(arr[i]);
  }
  for (i = k1; i < size; i++) {
    if (p1.top() > arr[i]) {
      p1.pop();
      p1.push(arr[i]);
    }
  }
  for (i = k2 - 1; i < size; i++) {
    if (p2.top() > arr[i]) {
      p2.pop();
      p2.push(arr[i]);
    }
  }
  while (!p1.empty()) {
    sumP1 += p1.top();
    p1.pop();
  }
  while (!p2.empty()) {
    sumP2 += p2.top();
    p2.pop();
  }
  int ans = sumP2 - sumP1;
  cout << ans << endl;
  return 0;
}