#include <iostream>
#include <string>
#include <cstdint>
#include <vector>

using namespace std;

void vavilon(int n) {
    if (n < 60) {
        for (int i = 0; i < n / 10; i++) {
            cout << "<";
        }
        for (int i = 0; i < n % 10; i++) {
            cout << "v";
        }
    }
    if (n >= 60) {
        vavilon(n / 60);
        cout << ".";

        n %= 60;
        vavilon(n);
    }
}

int main() {
    int n;
    cin >> n;

    vavilon(n);
}
