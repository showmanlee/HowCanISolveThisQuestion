// 나는 위대한 슈퍼스타K
// https://www.acmicpc.net/problem/2865

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    cout << fixed;
    cout.precision(1);

    int n, m, k;
    cin >> n >> m >> k;
    vector<float> maxx(n + 1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int p;
            float f;
            cin >> p >> f;
            maxx[p] = max(maxx[p], f);
        }
    }
    float res = 0;
    sort(maxx.begin(), maxx.end(), greater<float>());
    for (int i = 0; i < k; i++) {
        res += maxx[i];
    }
    cout << res << '\n';
}

// 오디션 참가자 n명의 m종류의 장르 실력이 주어지고, n명 중 k명이 하나의 장르로 출전할 수 있을 때, 출전한 모든 플레이어의 실력의 합 구하기

// 개인별로 실력 최댓값을 구하고, 해당 값들을 정렬하여 상위 k명의 값을 더해 출력한다
// 장르는 중복돼도 됩니다