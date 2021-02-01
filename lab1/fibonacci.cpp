#include <iostream>
#include <cmath>

using namespace std;

int64_t fibonacci(int64_t n) {
    if (n == 1 || n == 2){
        return (n);
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {

    int16_t number;
    number = 2;
    uint64_t sum;
    sum = 0;

    while (fibonacci(number) < 4000000) {
        sum += fibonacci(number);
        number += 2;
    }

    cout << sum << endl;

    return 0;
}
