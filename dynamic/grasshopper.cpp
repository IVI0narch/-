#include <iostream>
#include <vector>

using namespace std;

// просто скажу, что просидел 2 часа с этой задачей, потому что
//"транспонировал" таблицу ответов из списка задач
int main() {
	int n;
	cin >> n;

	vector<int> a(n+1);
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;
    for (int i = 3; i < n+1; ++i) {
        a[i] = a[i-3] + a[i-2] + a[i-1];
    }
	cout << a[n];

	return 0;
}
