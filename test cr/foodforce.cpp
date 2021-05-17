#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
    int N;
    double x0, y0;
    x0 = 0;
    y0 = 0;
    cin >> N;
    double x, y, F;
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> F;
        x0 += F*x / sqrt(x*x + y*y);
        y0 += F*y / sqrt(x*x +y*y);
    }
    printf("%.4f", x0);
    cout << " ";
    printf("%.4f", y0);
}
