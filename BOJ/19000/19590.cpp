// 비드맨
// https://www.acmicpc.net/problem/19590

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    long long maxx = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long p;
        cin >> p;
        sum += p;
        maxx = max(maxx, p);
    }
    sum -= maxx;
    if (maxx >= sum) {
        cout << (maxx - sum) << '\n';
    } else {
        cout << ((maxx + sum) % 2) << '\n';
    }
}

// n종류의 구슬이 여러 개 있고, 서로 다른 구슬을 부딪히면 서로 깨질 때, 최대한 깨뜨려서 남는 구슬 개수는?

// 어려워 보이지만, 경우의 수를 잘 생각해보면 된다 - 가장 많은 구슬의 개수가 나머지 구슬의 합보다 작은가 아닌가?
// 작다면 - 보이는 서로 다른 구슬을 잡아 깨다보면 결과적으로 0개나 1개가 남게 된다, 따라서 모든 구슬의 합 % 2를 출력
// 아니라면 - 나머지 구슬을 가장 많은 구슬과 함께 깨면 가장 많은 구슬이 남게 된다, 따라서 가장 많은 구슬 - 나머지 구슬을 출력