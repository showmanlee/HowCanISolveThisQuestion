// 문문문
// https://www.acmicpc.net/problem/17210

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a;
	cin >> n >> a;
	if (n <= 5) {
		for (int i = 1; i < n; i++) {
			a = !a;
			cout << a << '\n';
		}
	} else {
		cout << "Love is open door\n";
	}
}
 
// n개의 문이 놓인 공간에서 연속된 문을 같은 방식으로 밀고 당길 수 없고, 2의 배수 또는 3의 배수 번째 문들을 같은 방식으로 밀고 당겨야 하는 상황에서 첫 번째 문을 연 방법이 주어질 때, 그 다음에 어떻게 열어야 하는 지 출력하기
// 없으면 Love is open door 출력하기

// 일단 연속된 문을 같은 방식으로 열 수 없기에 나올 수 있는 방법은 010101... 또는 101010... 뿐이다
// 2의 배수일 때, 그리고 3의 배수일 때 배수끼리 문을 여는 방법이 같아야 한다 - 그런데 2와 3의 최소공배수인 6번째부터는 이 규칙을 만족할 수 없게 된다
// 따라서 6 미만일 경우에는 첫 번째 문에 맞춰 교차로 출력해주고, 이상일 경우 안 된다고 말하기
