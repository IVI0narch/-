#include<iostream>
#include<vector>
#include<string>
#include<cmath>


using namespace std;

int main(){
    int N;
    vector<double> arr;
    cin >> N;
    double R, H, rho;
    cin >> R >> H >> rho;
    int k = 1;
    double mass = rho * R * R * H;
    for (int i = 1; i < N; i++) {
        cin >> R >> H >> rho;
        if (rho * R * R * H > mass) {
            mass = rho * R * R * H;
            k = i;
        }
    }
    cout << k;
}
