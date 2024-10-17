// 증가 수열
// https://www.acmicpc.net/problem/30236

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int p = 0;
        for (int i = 0; i < n; i++) {
            p++;
            if (p == v[i]) {
                p = v[i] + 1;
            }
        }
        cout << p << '\n';
    }
}

// 주어진 수열과 같은 길이에 양의 정수로 구성되어 있고 같은 자리의 값이 서로 다른 오름차순 수열의 마지막 칸 값의 최소 구하기