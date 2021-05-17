#include <iostream>

using namespace std;


int main() {
    int N, M, s;
    cin >> N;
    M = N / 2;
    int** A = (int**)malloc(N * sizeof(int*));
    for (int i = 0;i < N;++i)
    {
        int* a = (int*)malloc(2 * sizeof(int));
        cin >> a[0] >> a[1];
        A[i] = a;
    }
    cin >> s;
    for (int i = 0; i < M;++i)
    {
        A[i + 1][1] += A[i][1];
        A[i][1] = 0;
        for (int j = i + 1; j < N - 1;++j)
        {
            if (A[j][1] + A[j][0] > s)
            {
                A[j + 1][1] += A[j][0] + A[j][1] - s;
                A[j][1] = s - A[j][0];
            }
            else
                break;
        }
    }
    for (int i = 0;i < N;++i)
    {
        cout << A[i][0] << " " << A[i][1] << endl;
    }
    for (int i = 0;i < N;++i)
        free(A[i]);
    free(A);
}
