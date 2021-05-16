#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<int> buf;
    vector<int> res = {1, 1, 1};
    int N;

    cin >> N;

    for (int i = 1; i < N; i++) {
        buf.push_back(res[1] + res[2]);
        buf.push_back(res[0] + res[1] + res[2]);
        buf.push_back(res[0] + res[1] + res[2]);
        res = buf;
        buf.clear();
    }

    cout << res[0] + res[1] + res[2];

    return 0;
}

