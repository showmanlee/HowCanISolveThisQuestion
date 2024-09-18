// 당직 근무표
// https://www.acmicpc.net/problem/31408

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<int> v(100001);
    int n;
    cin >> n;
    int maxx = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        v[p]++;
        maxx = max(maxx, v[p]);
    }
    int half = n / 2 + (n % 2);
    cout << (maxx > half ? "NO" : "YES") << '\n';
}

// 주어진 수열의 원소 순서를 바꿔 같은 수가 연속으로 나오지 않게 할 수 있는지 구하기