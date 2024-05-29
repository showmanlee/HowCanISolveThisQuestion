// 손가락 게임
// https://www.acmicpc.net/problem/31866

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool isValid(int n) {
    return n == 0 || n == 2 || n == 5;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    char res = ' ';
    if (isValid(a) && isValid(b)) {
        if (a == 0) {
            res = (b == 5 ? '<' : (b == 2 ? '>' : '='));
        } else if (a == 2) {
            res = (b == 0 ? '<' : (b == 5 ? '>' : '='));
        } else if (a == 5) {
            res = (b == 2 ? '<' : (b == 0 ? '>' : '='));
        }
    } else if (isValid(a)) {
        res = '>';
    } else if (isValid(b)) {
        res = '<';
    } else {
        res = '=';
    }
    cout << res << '\n';
}

// 가위바위보에서 이상한 손가락 개수를 내면 무효가 되어 패배할 때, 양쪽이 펼친 손가락 개수를 보고 승패 판단하기

// 조건을 나눠봅시다