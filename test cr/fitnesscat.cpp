#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {
    vector<vector<double>> coord;
    int N;
    double norm;
    cin >> N;
    double x, y, z;
    double d = 0;
    int s = 0;
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> z;
        vector < double > vec;
        vec.push_back(x);
        vec.push_back(y);
        vec.push_back(z);
        coord.push_back(vec);
    }
    cin >> norm;
        double x0 = coord[0][0];
        double y0 = coord[0][1];
        double z0 = coord[0][2];

    for (int i = 1; i < N; i++) {
        d += sqrt((coord[i][0] - x0) * (coord[i][0] - x0) + (coord[i][1] - y0) * (coord[i][1] - y0) + (coord[i][2] - z0) * (coord[i][2] - z0));
        s += 1;
        if (d >= norm) {
            cout << s;
            break;
        }
        x0 = coord[i][0];
        y0 = coord[i][1];
        z0 = coord[i][2];
    }
    if (d < norm) {
        cout << -1;
    }
    return 0;
}
