#include<iostream>
#include<vector>

using namespace std;

vector<int> run(vector<int>arr) {
	vector<int> ways;
	ways.resize(arr.size());
	ways[0] = 1;
	for (int i = 0; i < arr.size() - 1; i++) {
		if ((arr[i] + i) < arr.size() and arr[i] != 1) {
			ways[arr[i] + i] = (ways[arr[i] + i] + ways[i]) % 937;
		}
		ways[i + 1] = (ways[i] + ways[i + 1]) % 937;
	}
	return ways;
}

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << run(arr)[n - 1] % 937;

    return 0;
}
