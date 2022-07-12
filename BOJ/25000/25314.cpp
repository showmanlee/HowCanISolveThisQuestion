// 코딩은 체육과목 입니다
// https://www.acmicpc.net/problem/25314

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    n /= 4;
    for (int i = 0; i < n; i++) {
        cout << "long ";
    }
    cout << "int\n";
}

// 4바이트 정수를 저장하는 자료형이 long int, 8바이트 정수를 저장하는 long long int일 때, n(n % 4 == 0)바이트 정수를 자료형 구하기

// n / 4회 만큼 long을 출력한 후 int를 출력한다