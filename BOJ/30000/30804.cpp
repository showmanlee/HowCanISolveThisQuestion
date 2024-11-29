// 과일 탕후루
// https://www.acmicpc.net/problem/30804

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n), cnt(10);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int l = 0, r = 0;
    int type = 0;
    int res = 0;
    while (r < n) {
        cnt[v[r]]++;
        if (cnt[v[r]] == 1) {
            type++;
        }
        while (type > 2) {
            cnt[v[l]]--;
            if (cnt[v[l]] == 0) {
                type--;
            }
            l++;
        }
        r++;
        res = max(res, r - l);
    }
    cout << res << '\n';
}

// 1~9까지 적힌 1차원 배열에서 앞쪽과 뒷쪽 원소를 빼서 두 종류 이하의 원소만 남는 최대 길이 구하기

// 앞쪽부터 채우면서 종류 수를 세고, 3종류 이상이 되면 뒤에서 2종류만 남을 때까지 빼기
// 이 과정을 돌리며 최대 길이 확인하기