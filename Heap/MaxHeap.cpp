#include <iostream>
using namespace std;

class MaxHeap {
  int *Arr;
  int Size;
  int MaxSize;

public:
  MaxHeap(int n): Size(0){
    Arr = new int[n];
    MaxSize = n;
  }

  void InsertData(int data) {
    if (Size == MaxSize) {
      cout << "Heap Overflow !" << endl;
      return;
    } else {
      Arr[Size] = data;
      int index = Size;
      Size++;
      while (index > 0 && Arr[(index - 1) / 2] < Arr[index]) {
        Arr[index] = Arr[index] ^ Arr[(index - 1) / 2];
        Arr[(index - 1) / 2] = Arr[index] ^ Arr[(index - 1) / 2];
        Arr[index] = Arr[index] ^ Arr[(index - 1) / 2];
        index = (index - 1) / 2;
      }
    }
  }

  void heapify(int i = 0) {
    int largeI = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < Size && Arr[left] > Arr[largeI]) {
      largeI = left;
    }
    if (right < Size && Arr[right] > Arr[largeI]) {
      largeI = right;
    }
    if (largeI != i) {
      Arr[i] = Arr[i] ^ Arr[largeI];
      Arr[largeI] = Arr[i] ^ Arr[largeI];
      Arr[i] = Arr[i] ^ Arr[largeI];
      heapify(largeI);
    }
  }

  void DeleteData() {
    if (!Size) {
      cout << "Heap underflow can't delete" << endl;
      return;
    }
    Arr[0] = Arr[--Size];
    if (!Size) {
      return;
    }
    heapify();
  }

  void Display(int i = 0) {
    if (i == Size) {
      return;
    }
    cout << Arr[i] << " ";
    Display(i + 1);
  }

  ~MaxHeap() { delete[] Arr; }
};

int main() {
  MaxHeap H(10);

  H.InsertData(10);
  H.InsertData(415);
  H.InsertData(327);
  H.InsertData(13);
  H.InsertData(41);
  H.InsertData(86);
  H.InsertData(0);
  H.InsertData(0);
  H.InsertData(760);
  H.DeleteData();
  H.DeleteData();
  H.DeleteData();
  H.Display();

  return 0;
}