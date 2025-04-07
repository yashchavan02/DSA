#include <iostream>
#include <float.h>
using namespace std;

int main() {
    float minVal = FLT_MAX, maxVal = FLT_MIN;
    float vec[] = {100, 35, 765, 87, 7, 8, 0};
    int n = sizeof(vec) / sizeof(vec[0]);
    float ans[n];

    for (int i = 0; i < n; i++) {
        minVal = min(minVal, vec[i]);
        maxVal = max(maxVal, vec[i]);
    }

    for (int i = 0; i < n; i++) {
        ans[i] = (vec[i] - minVal) / (maxVal - minVal);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " | ";
    }
    cout << endl;

    return 0;
}
