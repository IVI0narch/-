#include<iostream>
#include<vector>
#include<string>


using namespace std;

struct coord {
	double x, y, z;


	coord() {
		cin >> x >> y >> z;
	}
};

double det(vector<double>a1, vector<double>a2, vector<double>a3) {
	double D;
	D = a1[0] * (a2[1] * a3[2] - a2[2] * a3[1]) - a1[1] * (a2[0] * a3[2] - a2[2] * a3[0]) + a1[2] * (a2[0] * a3[1] - a2[1] * a3[0]);
	return D;
}


int main() {
	coord t1;
	coord t2;
	coord t3;
	coord t4;

	vector<double>a1;
	a1.push_back(t2.x - t1.x);
	a1.push_back(t2.y - t1.y);
	a1.push_back(t2.z - t1.z);


	vector<double>a2;
	a2.push_back(t3.x - t1.x);
	a2.push_back(t3.y - t1.y);
	a2.push_back(t3.z - t1.z);

	vector<double>a3;
	a3.push_back(t4.x - t1.x);
	a3.push_back(t4.y - t1.y);
	a3.push_back(t4.z - t1.z);


	double V;
	double D = det(a1, a2, a3);
	if (D < 0) {
		D = -D;
	}
	V = D / 6;
	printf("%.4f", V);

	return 0;
}
