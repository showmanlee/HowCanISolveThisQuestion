// НАМИСЛИХ СИ ЧИСЛО
// https://www.acmicpc.net/problem/31261

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    int res = (b + a) * a;
    res = (res + a) * a;
    cout << res << '\n';
}

// 어떤 수를 a로 나누고 a를 뺀 다음, 똑같은 계산을 한번 더 했을 때 b가 나오는 수 구하기

// 반대로 해서 구하기