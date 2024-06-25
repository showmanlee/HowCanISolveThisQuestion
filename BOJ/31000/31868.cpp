// 수박 게임
// https://www.acmicpc.net/problem/31868

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        k /= 2;
    }
    cout << k << '\n';
}

// 같은 과일 2개를 뭉쳐서 더 큰 과일을 만드는 게임에서 1단계 과일이 k개 있고 마지막 단계가 n단계일 때, 만들 수 있는 n단계 과일 개수 출력하기