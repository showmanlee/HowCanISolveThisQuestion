// Zero or One
// https://www.acmicpc.net/problem/13623

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    if (a != b && a != c) {
        cout << "A\n";
    } else if (b != a && b != c) {
        cout << "B\n";
    } else if (c != a && c != b) {
        cout << "C\n";
    } else {
        cout << "*\n";
    }
}

// 0과 1로 주어지는 3개의 수 중 다른 수의 위치 찾기

// 숫자가 0과 1밖에 주어지지 않으므로 필연적으로 다른 두 숫자는 같을 수밖에 없음
// 하지만 세 수가 모두 동일한 경우가 나올 수 있으므로 어떤 숫자가 다른 두 숫자와 모두 다른지 판정하여 결과 출력하기