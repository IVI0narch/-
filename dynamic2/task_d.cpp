#include<iostream>
#include<vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> p_count(N);
    vector<int> step;
    vector<int> sum;

    for (int i = 0; i < N; ++i) {
        cin >> p_count[i];
    }

    sum.push_back(p_count[0]);
    step.push_back(-1);
    sum.push_back(p_count[1]);
    step.push_back(-1);

    for (int i = 2; i < N; ++i) {
        if (sum[i - 1] > sum[i - 2]) {
            sum.push_back(p_count[i] + sum[i - 2]);
            step.push_back(i - 2);
        }
        else {
            sum.push_back(p_count[i] + sum[i - 1]);
            step.push_back(i - 1);
        }
    }

    cout << sum[N - 1] << endl;

    vector<int> Way;
    int ceil_n = N - 1;

    Way.push_back(ceil_n);
    while (ceil_n != -1) {
        ceil_n = step[ceil_n];
        Way.push_back(ceil_n);
    }

    Way.pop_back();

    for (int i = Way.size() - 1; i >= 0; --i) {
        cout << Way[i] << " ";
    }

    return 0;
}
