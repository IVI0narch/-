#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    int max_s;
    int sum_s = 0;

    cin >> max_s;

    vector<int> coords;

    // ctrl + c для окончания ввода после entera
    int input;
    while (cin >> input) {
        coords.push_back(input);
    }

    sort(coords.begin(), coords.end());

    for (int i = 1; i < coords.size(); ++i) {
        if (coords[i] - coords[i-1] <= max_s)
            sum_s = coords[i];
        else
            sum_s += max_s;
    }

    cout << sum_s;

    return 0;
}
