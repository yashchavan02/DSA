#include <iostream>
#include <queue>
using namespace std;

int main() {
  int arr[] = {1, 4, 6, 3, 9, 7};
  int size = sizeof(arr) / sizeof(arr[0]);
  priority_queue<int> p;
  for (int i = 0; i < size; i++) {
    p.push(arr[i]);
  }
  int tickets = 7;
  int TPrice = 0;
  while (tickets-- && !p.empty()) {
    int value = p.top();
    TPrice += value;
    p.pop();
    p.push(value - 1);
  }
  cout << TPrice << endl;
  return 0;
}