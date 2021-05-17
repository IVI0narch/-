#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int main(){
	vector<double>arr;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		double R;
		cin >> R;
		arr.push_back(R);
	}

	double S;
	S = 0;
	for (double& i : arr) {
		S += i * i;
	}

	printf("%.4f", sqrt(S));
}
