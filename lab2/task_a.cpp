#include <iostream>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    while (a != 0 && b != 0) {
        a > b ? a %= b : b %= a;
    }
    cout << (a + b) << endl;
}
