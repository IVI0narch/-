#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {
    int M;
    cin >> M;
    float** arr;
    arr = (float**)malloc(M * sizeof(float**));
    for (int i = 0; i < M; ++i) {
        arr[i] = (float*)malloc(M * sizeof(float*));
    }
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            float a;
            cin >> a;
            arr[i][j] = a;
        }
    }
    int s = 0;
    for (int i = M - 1; i >= 0; i--) {
        s += arr[M- 1 -i][i];
    }
    cout << s;
    for (int i = 0; i < M; i++) {
        free(arr[i]);
    }
    free(arr);
}
