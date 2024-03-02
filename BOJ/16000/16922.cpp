// 로마 숫자 만들기
// https://www.acmicpc.net/problem/16922

#include <iostream>
#include <algorithm>
using namespace std;

int value[4] = {1, 5, 10, 50};
bool checker[1001];
int n, res = 0;

void dfs(int cnt, int num, int sum) {
    if (cnt == n) {
        if (!checker[sum]) {
            checker[sum] = true;
            res++;
        }
        return;
    }
    for (int i = num; i < 4; i++) {
        dfs(cnt + 1, i, sum + value[i]);
    }
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    cin >> n;
    dfs(0, 0, 0);
    cout << res << '\n';
}

// 순서에 관계없이 I, V, X, L로 만들 수 있는 길이 n의 로마 숫자 값의 개수 구하기

// 중복 조합 구하기 - 순서도 의미없고, 오직 개수만 본다
// 때문에 dfs로 구할 때 굳이 다음 숫자로 4가지 숫자를 모두 볼 필요는 없음 - 오히려 그러면 분기가 많아져서 시간 초과 가능성 있음
// I부터 순서대로 하나씩 채워간다는 느낌으로 접근하기...