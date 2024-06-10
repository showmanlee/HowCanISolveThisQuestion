// 새끼치기
// https://www.acmicpc.net/problem/17291

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n + 1);
    v[0] = v[1] = 1;
    for (int i = 2; i <= n; i++) {
        v[i] = v[i - 1] * 2;
        if (i % 2 == 0) {
            if (i >= 4) {
                v[i] -= v[i - 4];
            }
            if (i >= 5) {
                v[i] -= v[i - 5];
            }
        }
    }
    cout << v[n] << '\n';
}

// 1마리로 시작해 매년 2배로 증식하는데 홀수 해에 태어날 경우 3년 뒤, 짝수 해에 태어난 경우 4년 뒤에 죽는 벌레가 있을 떄, n년차의 벌레 수 구하기

// dp 개념을 접목해보자 - 1년차는 4년에, 2년차는 6년에, 3년차도 6년에... 어쩄든 짝수 해에만 죽는다고 볼 수 있음
// 태어나는 게 먼저이므로 전년의 2배만큼 불린 뒤, 짝수해일 경우 그만큼 지워준다
// 인덱스 마이너스가 3/4가 아닌 4/5인 이유는 그 전년에 태어난 수가 죽어야 하기 떄문