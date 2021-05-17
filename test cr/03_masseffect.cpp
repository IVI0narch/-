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

    vector<int>right;
    for (int i = 1; i <= (n - 1) / 2; i++) {
        right.push_back(arr[(n - 1) / 2 + i]);
    }

    vector<int>left;
    for (int i = 0; i < (n - 1) / 2; i++) {
        left.push_back(arr[i]);
    }

    vector<int>newarr;
    newarr.push_back(arr[(n - 1) / 2]);

    for (int i = 0; i < (n - 1) / 2; i++) {
        newarr.push_back(left[(n - 1) / 2 - 1 - i]);

        newarr.push_back(right[i]);
    }

    for (int& i : newarr) {
        cout << i << " ";
    }
    return 0;
}
