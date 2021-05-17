#include<iostream>
#include<vector>
#include<string>

using namespace std;


int main() {
	int M, N;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cout << "*";
	}
	cout << endl;
	for (int i = 0; i < N-2; i++) {
		cout << "*";
		for (int i = 1; i < M-1; i++) {
			cout << " ";
		}
		cout << "*";
		cout << endl;
	}
	for (int i = 0; i < M; i++) {
		cout << "*";
	}

    return 0;
}
