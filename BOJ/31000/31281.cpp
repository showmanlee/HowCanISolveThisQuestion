// ЗЛАТНАТА СРЕДА
// https://www.acmicpc.net/problem/31281

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<long long> v(3);
    for (int i = 0; i < 3; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << v[1] << '\n';
}

// 세 수 중 중앙값 구하기