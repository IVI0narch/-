#include <iostream>
#include <string>
#include <cstdint>
#include <vector>

using namespace std;

int main() {
    string nomer, a, b, c;
    int speed, cash;

    cin >> speed >> nomer;

    cash = 0;
    while (nomer != "A999AA") {
        if (speed > 60) {
            a = nomer[1];
            b = nomer[2];
            c = nomer[3];
            if ((a == b) && (a == c)) {
                cash += 1000;
            }
            else if ((a == b) || (a == c) || (b == c)) {
                cash += 500;
            }
            else {
                cash += 100;
            }
        }
        cin >> speed >> nomer;
    }

    cout << cash;
}
