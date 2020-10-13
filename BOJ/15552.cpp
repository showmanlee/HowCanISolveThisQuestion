// 빠른 A+B
// https://www.acmicpc.net/problem/15552

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		cout << (a + b) << '\n';
	}
}

// C++에서 출력 속도 높이는 방법
// 1. 출력 버퍼를 비우는 endl 대신 '\n'으로 개행 처리
// 2. cin.tie(NULL); 적용 - cin과 cout의 묶음을 풀어주면서, cin 사용 시 자동으로 출력 버퍼를 지우는 문제를 해결
// 3. ios_base::sync_with_stdio(false); 적용 - C(stdio)와 C++(iostream)의 버퍼 분리로 성능 향상 가능. 단, 이 경우 <cstdio>의 입출력함수를 사용할 수 없음
// 출력 버퍼를 지우면 화면에 바로 출력할 수 있지만, 알고리즘 풀이에서는 중요하지 않음
// 정 안 되면 <cstdio>의 printf와 scanf를 사용할 수 있음 - 이러한 처리할 필요 없이 충분히 빠름
