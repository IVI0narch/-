#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int Salary(vector<vector<int>> v, int sum, int day) {
    int m = sum;
    vector<vector<int>> v_copied;

    v_copied = v;

    for (int i = 0; i < v.size(); ++i) {
        if (v[i][0] <= day)
            v.erase(v.begin() + i);
    }

    for (int i = 0; i < v.size(); ++i) {
        v_copied = v;
        int t = v[i][1];
        v_copied.erase(v_copied.begin() + i);
        m = max(m, Salary(v_copied, sum + t, day+1));
    }

    return m;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(2)), b(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    cout << Salary(v, 0, 0);

    return 0;
}
