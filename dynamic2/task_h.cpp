#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main() {
	vector<vector<int>>blacks;
	vector<vector<int>>path;
	int N;

	cin >> N;

	blacks.resize(10);
	for (int i = 0; i < 10; ++i) {
		blacks[i].resize(10);
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			blacks[i][j] = 0;
		}
	}

	path.resize(10);
	for (int i = 0; i < 10; ++i) {
		path[i].resize(10);
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			path[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		string in;
		cin >> in;
		char n = in[1];
		int b = n - 48;
		b = b ;
		if (in[0] == 'a') {
			blacks[b][1] = 1;
		}
		if (in[0] == 'b') {
			blacks[b][2] = 1;
		}
		if (in[0] == 'c') {
			blacks[b][3] = 1;
		}
		if (in[0] == 'd') {
			blacks[b][4] = 1;
		}
		if (in[0] == 'e') {
			blacks[b][5] = 1;
		}
		if (in[0] == 'f') {
			blacks[b][6] = 1;
		}
		if (in[0] == 'g') {
			blacks[b][7] = 1;
		}
		if (in[0] == 'h') {
			blacks[b][8] = 1;
		}
	}

	string white;
	cin >> white;
	char n = white[1];
	int b = n - 48;

	if (white[0] == 'a') {
		path[b][1] = 1;
	}
	if (white[0] == 'b') {
		path[b][2] = 1;
	}
	if (white[0] == 'c') {
		path[b][3] = 1;
	}
	if (white[0] == 'd') {
		path[b][4] = 1;
	}
	if (white[0] == 'e') {
		path[b][5] = 1;
	}
	if (white[0] == 'f') {
		path[b][6] = 1;
	}
	if (white[0] == 'g') {
		path[b][7] = 1;
	}
	if (white[0] == 'h') {
		path[b][8] = 1;
	}

	for (int i = b; i <= 8; i++) {
		for (int j = 0; j <= 8; j++) {
			if (blacks[i][j] == 1) {
				path[i][j] += path[i - 1][j - 1] + path[i - 1][j + 1];
			}
			else {
				if (path[i - 1][j] > 0) {
					path[i][j] += path[i - 1][j];
				}
			}
		}
	}

	int sum;
	sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += path[8][i];
	}

	cout << sum;

	return 0;
}
