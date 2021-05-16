#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int main() {
	vector<int> coord;

	int input;
	while (cin >> input) {
		coord.push_back(input);
	}

	sort(coord.begin(), coord.end());

	vector<int> thread_length;
	thread_length.resize(coord.size());
	thread_length[0] = 0;
	thread_length[1] = coord[1] - coord[0];
	thread_length[2] = coord[2] - coord[0];

	for (int i = 3; i < coord.size(); ++i) {
		thread_length[i] = min(thread_length[i - 2], thread_length[i - 1]) + coord[i] - coord[i - 1];
	}

	cout << thread_length[coord.size() - 1];

    return 0;
};
