#include <iostream>

using namespace std;

int main() {
    int number, m, k;
    cin >> number;

    m = 0;
    k = 0;
    while (number != 0) {
        if (number > m) {
            m = number;
            k = 1;
        } else if (number == m) {
            k++;
        }
        cin >> number;
    }
    cout << k;
}
