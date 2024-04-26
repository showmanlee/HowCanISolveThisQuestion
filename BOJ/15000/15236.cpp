// Dominos
// https://www.acmicpc.net/problem/15236

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            res += i + j;
        }
    }
    cout << res << '\n';
}

// 한 칸에 최대 n개의 점이 들어갈 수 있는 도미노에서 만들 수 있는 모든 도미노 형태에 있는 모든 점의 개수 구하기

// 반복문을 돌려봅시다 - 아래 점 수에 따라 위에 올 수 있는 최대 점이 결정된다고 생각하기