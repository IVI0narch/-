#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {
    double a, v, R;
    cin >> a >> v >> R;
    double t1 = sqrt(2*R / a);
    double t2 = R / v;
    if (t2 > t1) {
        cout << '1';
    }
    else {cout << '2';}

}
