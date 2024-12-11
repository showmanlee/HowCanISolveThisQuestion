// Os últimos serão os primeiros
// https://www.acmicpc.net/problem/30658

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        reverse(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            cout << v[i] << '\n';
        }
        cout << 0 << '\n';
    }
}

// 주어진 배열을 뒤집어서 출력하기