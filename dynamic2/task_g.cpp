#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>

using namespace std;

int main() {
	int N;

	cin >> N;

	vector<int> height(N);
	for (int i = 0; i < N; ++i) {
		cin >> height[i];
	}

	vector<int> sum(N);
	sum[0] = 0;
	sum[1] = abs(height[0] - height[1]);
	for (int i = 2; i < N; ++i) {
		sum[i] = min(sum[i - 2] + 3 * abs(height[i] - height[i - 2]), sum[i - 1] + abs(height[i] - height[i - 1]));
	}

	cout << sum[N - 1];

    return 0;
}
