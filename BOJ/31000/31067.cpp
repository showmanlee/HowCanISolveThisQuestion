// 다오의 경주 대회
// https://www.acmicpc.net/problem/31067

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (v[i - 1] >= v[i]) {
            v[i] += k;
            res++;
            if (v[i - 1] >= v[i]) {
                res = -1;
                break;
            }
        }
    }
    cout << res << '\n';
}

// 주어진 수열의 원소에 k를 최대 1번 더해서 증가하는 수열로 만들 수 있는지, 그리고 더해야 하는 횟수 구하기

// 왼쪽부터 돌면서 이전 원소보다 작거나 같으면 더하고, 그래도 작거나 같으면 아웃
// 그렇지 않으면 계속 보면서 더한 횟수 계산하기