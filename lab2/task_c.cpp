#include <iostream>

using namespace std;

int main() {
    int number, k;
    cin >> number;

    k = 0;
    while (number != 0) {
        if (number % 2 == 0) {
            k += 1;
        }
        cin >> number;
    }
    cout << k;
}
