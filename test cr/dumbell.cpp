#include<iostream>
#include<vector>
#include<string>
#include<cmath>


using namespace std;


int main(){
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cout << '|';
    }
    for (int i = 0; i < N; i++) {
        cout << '=';
    }
    for (int i = 0; i < M; i++) {
        cout << '|';
    }
    return 0;
}
