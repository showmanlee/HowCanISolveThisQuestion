// 수 이어 쓰기 1
// https://www.acmicpc.net/problem/1748

#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int res = 0, pow = 1;
	while (pow <= n){
		res += (n - pow + 1);
		pow *= 10;	
	}
	cout << res;
}

// 1부터 N까지 이어쓸 때 몇 자리가 나오는가
// 0.15초 제한 - for 순회나 string 변환은 답이 아님
// 따라서 계산을 해야 한다
// 1자리 수는 9개, 2자리 수는 90개, 3자리 수는 900개...
// 이를 일반식으로 표현하면 n - pow + 1
// 이 식을 계속 돌리면 x자리 수 판정도 처리 가능 - 1자리 수는 한 번만 더하고, 2자리수는 9(1) + 90(10)번 더하니까