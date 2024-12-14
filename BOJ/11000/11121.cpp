// Communication Channels
// https://www.acmicpc.net/problem/11121

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        cout << (a == b ? "OK" : "ERROR") << '\n';
    }
}

// 주어진 2진수가 같은지 확인하기