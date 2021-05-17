#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int main(){
	double H;
	cin >> H;
	double v;
	cin >> v;
	double X;
	X = v * sqrt(2 * H / 9.81);

	printf("%.4f", X);
}
