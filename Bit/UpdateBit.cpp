#include<iostream>
using namespace std;

int UpdateBit(int n, int i, int v) {
    int temp = n & ~(1 << i); 
    return temp | (v << i); 
}

int main() {
    cout << UpdateBit(5, 1, 1); 
    return 0;
}
