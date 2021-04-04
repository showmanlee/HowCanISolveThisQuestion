// 팩토리얼 0의 개수
// https://www.acmicpc.net/problem/1676

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n, res = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i % 5 == 0)
			res++;
		if (i % 25 == 0)
			res++;
		if (i % 125 == 0)
			res++;
	}
	cout << res;
}

// 최대 500!에서 등장하는 뒤쪽 0의 개수를 구하라 - 천하의 Python도 이건 느려서 못함
// 0이 나오는 경우는 10을 곱하는 경우 - 정확히는 2*5가 나오는 경우
// 2의 배수와 5의 배수 한번씩 나올 때마다 0이 추가된다고 볼 수 있음
// 그런데 2는 충분히 나오니 5만 봐주면 됨 - 5의 배수가 한 번 나올 때마다 0이 나온다고 해도 된다는 말 
// 여기서 5*5(25), 5*5*5(125)의 배수가 나오면 5가 2~3번 나왔으니 0도 2~3개가 나옴에 주의