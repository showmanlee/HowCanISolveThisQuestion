// 접시 안의 원
// https://www.acmicpc.net/problem/16483

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    double t;
    cin >> t;
    double res = (t / 2.0) * (t / 2.0);
    cout << ((int)(res + 0.5)) << '\n';
}

// 한 원 안에 다른 원이 포함된 도형에서 작은 원의 접선이 큰 원과 만나는 두 점 사이의 거리를 T라고 할 때, 두 원의 제곱의 차 구하기

// 해당 접선은 작은 원의 반지름과 큰 원의 반지름을 변으로 하는 삼각형으로 만들 수 있음 - 피타고라스를 이용하면 원하는 값을 구할 수 있지
// a^2 + (t/2)^2 = b^2, (t/2)^2 = a^2 - b^2
// 정수로 반올림해줘야 함에 주의 - (int)(n + 0.5)