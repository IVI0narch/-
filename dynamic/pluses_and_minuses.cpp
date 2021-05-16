#include <iostream>
#include <vector>

using namespace std;


bool check_str(vector<int> prev, int cor, int n) {
    if (n == prev.size()) {
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += prev[i];
        if (cor == sum)
            return 1;
        else
            return 0;
    }
    vector<int> cont = prev;

    cont[n] *= -1;

    if (check_str(cont, cor, n + 1) || check_str(prev, cor, n + 1))
        return 1;

    return 0;
}

int main() {
    int number;
    cin >> number;

    vector<int> v;

    // ctrl + c для окончания ввода после entera
    int input;
    while (cin >> input) {
        v.push_back(input);
    }

    if (check_str(v, number, 0))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
