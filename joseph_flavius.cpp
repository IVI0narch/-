#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int winner = 0; // ����� ����������
    for (int i = 2; i <= n; i++){
        winner = (winner + k) % i; // ���������� �������
    }

    cout << winner + 1;
    return 0;
}
