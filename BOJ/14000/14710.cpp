// 고장난 시계
// https://www.acmicpc.net/problem/14710

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    cout << (a % 30 * 12 == b ? "O" : "X") << '\n';
}

// 시침과 분침의 각도가 주어질 떄, 자연스럽게 나올 수 있는 각도안지 판정하기

// 일단 매 시간에 시침이 차지할 수 있는 영역은 30도씩 - 그리고 시침 1도 당 분침이 있을 수 있는 영역은 12도씩
// 이를 이용해, 시침의 위치를 보고 분침이 제대로 있는지 확인해본다 - 초는 신경쓸 필요 없으니까