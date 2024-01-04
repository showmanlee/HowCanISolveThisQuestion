// 이제는 더 이상 물러날 곳이 없다
// https://www.acmicpc.net/problem/30455

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cout << (n % 2 ? "Goose" : "Duck") << '\n';
}

// n칸의 1차원 공간에서 Duck과 Goose가 양쪽에 있고, 각자의 턴마다 좌/우로 1칸 이동 또는 인접한 적 공격을 할 수 있을 때, 나올 수 있는 승자 구하기

// 홀수면 Goose, 짝수면 Duck 우승 - '최선을 다해 승부'하면 무조건 상대 쪽으로 돌진할 수밖에 없고, 이 경우 먼저 닿은 쪽이 진다
// 설령 피하더라도 결국 보드의 끝을 보게 되고, 그 끝에서 결국 지게 된다 - 따라서 무조건 저 결과가 성립하는 것