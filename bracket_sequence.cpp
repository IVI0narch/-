#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector <char> arr;
    string str;

    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(')
            arr.push_back(str[i]);
        if (arr.empty() and (str[i] == ')')) {
            cout <<"NO";
            return 0;
        }
        if ((str[i] == ')') and (!arr.empty()) and (arr.back() == '('))
            arr.pop_back();
    }

    if (!arr.empty()) {
        cout <<"NO";
    } else {
        cout <<"YES";
    }

    return 0;
}
