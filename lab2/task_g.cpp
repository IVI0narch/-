#include <iostream>
#include <string>
#include <cstdint>
#include <vector>

using namespace std;

int main() {
    int number, q;
    cin >> number;

    q = 2;
    while (q * q <= number && number % q != 0) {
        q++;
    }
    if (q * q > number) {
        cout << 1;
    } else {
        cout << 0;
    }
}
