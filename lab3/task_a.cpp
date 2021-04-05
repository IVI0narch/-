#include <iostream>
#include <string>
#include <cstdint>
#include <vector>

using namespace std;

int main() {
    int n;
    float mid, sum;
    cin >> n;

    int* arr = new int[n];

    sum = 0.0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    mid = sum / n;
    sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) {
            sum += arr[i];
        }
    }
    delete[] arr;

    cout << sum;
}
