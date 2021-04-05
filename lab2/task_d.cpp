#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int gcd(int a, int b) {
    while (a != 0 && b != 0) {
        a > b ? a %= b : b %= a;
    }
    return (a + b);
}

int main(){
    int n, r, i;
    cin >> n;

    r = 0;
    i = 2;
    while (r != 1 && r != n && n >= i) {
        r = gcd(i, n);
        i *= 2;
    }
    if ((r == n) || (n == 1)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}
