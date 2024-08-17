// 산타 춘배의 선물 나눠주기
// https://www.acmicpc.net/problem/30406

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> cnt(4);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        cnt[p]++;
    }
    int res = 0;
    vector<pr> cases = {
        {0, 3},
        {1, 2},
        {0, 2},
        {1, 3},
        {0, 1},
        {2, 3}
    };
    for (pr p : cases) {
        int x = p.first ^ p.second;
        int minn = min(cnt[p.first], cnt[p.second]);
        res += minn * x;
        cnt[p.first] -= minn;
        cnt[p.second] -= minn;
    }
    cout << res << '\n';
}

// 0~3 숫자 n개가 주어질 때, 2개씩 쌍으로 묶은 xor값의 합의 최댓값 구하기

// 2비트 xor인데, 두 비트가 모두 다르면 3, 큰쪽이 다르면 2, 작은쪽이 다르면 1이 나옴
// 따라서 0부터 3까지 나오는 횟수를 세고, xor이 많이 나오는 순서대로 경우를 빼간다