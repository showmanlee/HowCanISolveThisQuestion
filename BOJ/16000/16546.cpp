// Missing Runners
// https://www.acmicpc.net/problem/16546

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<bool> visit(n + 1);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        visit[p] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!visit[i]) {
            cout << i << '\n';
        }
    }
}

// 1~n번 선수 중 들어운 n-1명의 선수 번호가 주어질 때, 들어오지 못한 선수 구하기

// 배열로 체크하며 확인해봅시다