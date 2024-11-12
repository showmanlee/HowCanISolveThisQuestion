// Класс
// https://www.acmicpc.net/problem/27225

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    int minn = min(a, b);
    int p = max(a, b) - minn;
    int res = minn * 2 + p % 2;
    cout << res << '\n';
}

// 남녀공학 교실에서 2명씩 붙어 앉아야 하는 남자와 여자 수가 주어지고, 이 학생들이 남녀끼리, 또는 혼자 붙어 앉아야 집중력이 생길 때 집중력을 생기게 할 수 있는 최대 인원수 구하기