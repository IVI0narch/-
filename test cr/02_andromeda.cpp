#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {
    vector<int>arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    int max;
    max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int s = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == max) {
            s += 1;
        }
    }
    cout << s;
}
