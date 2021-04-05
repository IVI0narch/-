#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k, x, y;
    cin >> n >> m >> k;

    vector < vector <int> > a(n, vector <int> (m, 0) );

    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        x--;
        y--;
        a[x][y] = -1;
        if (x == 0) {
            if (y == 0) {
                a[x][y+1]++;
                a[x+1][y]++;
                a[x+1][y+1]++;
            } else if (y == m) {
                a[x][y-1]++;
                a[x+1][y-1]++;
                a[x+1][y]++;
            } else {
                a[x][y-1]++;
                a[x][y+1]++;
                a[x+1][y-1]++;
                a[x+1][y]++;
                a[x+1][y+1]++;
            }
        } else if (x == n) {
            if (y == 0) {
                a[x-1][y]++;
                a[x-1][y+1]++;
                a[x][y+1]++;
            } else if (y == m) {
                a[x][y-1]++;
                a[x-1][y-1]++;
                a[x-1][y]++;
            } else {
                a[x][y-1]++;
                a[x][y+1]++;
                a[x-1][y-1]++;
                a[x-1][y]++;
                a[x-1][y+1]++;
            }
        } else {
            a[x][y+1]++;
            a[x+1][y+1]++;
            a[x+1][y]++;
            a[x+1][y-1]++;
            a[x][y-1]++;
            a[x-1][y-1]++;
            a[x-1][y]++;
            a[x-1][y+1]++;
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
