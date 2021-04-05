#include <iostream>

using namespace std;

int main() {
    int number, m;
    cin >> number;

    m = 0;
    while (number != 0) {
        if (number % 2 == 0 && number > m) {
            m = number;
        }
        cin >> number;
    }
    cout << m;
}
