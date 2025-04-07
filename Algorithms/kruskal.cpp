#include<fstream>
#include<climits>
#include<iostream>
using namespace std;

struct Edge {
  int s, e, w;
};

bool operator < (const Edge& x, const Edge& y) {
    return x.w < y.w;
}

ostream& operator << (ostream& print, const Edge& E) {
  print << E.s << " " << E.e << " " << E.w;
  return print;
}

template <class T>
class Heap {
  T *A;
  int s, last;
  public:
  Heap(int n = 15){
    s = n;
    last = -1;
    A = new T[n];
  }

  ~Heap() {
    delete[] A;
  }

  void swap(int i, int j){
    T temp = A[i];
    A[i] = A[j];
    A[j] = temp;
  }

  void heapifyUp(int i){
    while(i > 0){
      int j = (i - 1) / 2;
      if(A[j] < A[i])
        return;
      swap(i, j);
      i = j;
    }
  }

  void heapifyDown(int i){
    int left, right, smallest;
    while(true){
      left = 2 * i + 1;
      right = 2 * i + 2;
      smallest = i;

      if(left <= last && A[left] < A[smallest])
        smallest = left;
      if(right <= last && A[right] < A[smallest])
        smallest = right;

      if(smallest == i)
        return;

      swap(i, smallest);
      i = smallest;
    }
  }

  void push(T key){
    if(last >= s - 1) return;
    A[++last] = key;
    heapifyUp(last);
  }
  
  bool empty(){
    return last == -1;
  }
  
  T top(){
    if(last == -1) return T();
    return A[0];
  }
  
  void pop(){
    if(last != -1){
      A[0] = A[last--];
      heapifyDown(0);
    }
  }
};

class Graph {
  int **A, v;
  public:
  fstream file;
  Graph(string filename){
     file.open(filename, ios::in);
     file >> v;
     A = new int*[v];
     for(int i = 0; i < v; i++){
        A[i] = new int[v];
        for(int j = 0; j < v; j++){
           file >> A[i][j];
        }
     }
  } 
  
  ~Graph(){    
    for(int i = 0; i < v; i++)
      delete[] A[i];
    delete[] A;
    file.close();
  }
  
  void kruskal(){
    int idx = 0 , edge_s = v - 1;
    Edge *mst = new Edge[edge_s];
    Heap<Edge> heap;
    for(int i = 0; i < v; i++){
        for(int j = i + 1; j < v; j++) 
            if(A[i][j])
                heap.push({i, j, A[i][j]}); 
    }
    int *set = new int[v];
    for(int i = 0; i < v; i++)
      set[i] = i;
    Edge E; 
    int minset, maxset; 
    while(!heap.empty()){
        E = heap.top();
        heap.pop();
        if(set[E.s] != set[E.e]){
            mst[idx++] = E;
            if(set[E.s] > set[E.e]){
              minset = set[E.e];
              maxset = set[E.s];
            }
            else {
              minset = set[E.s];
              maxset = set[E.e];          
            }
            for(int i = 0; i < v; i++) {
                if(set[i] == maxset) {
                    set[i] = minset;
                }
            }
        }
    }  
    for(int i = 0; i < edge_s; i++){
      cout << mst[i] << "\n";
    }   
    delete[] set;
    delete[] mst;
  }
};

int main(){
  Graph conn("matrix.txt");
  conn.kruskal();
  return 0;
}