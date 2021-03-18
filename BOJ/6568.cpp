// 귀도 반 로썸은 크리스마스날 심심하다고 파이썬을 만들었다
// https://www.acmicpc.net/problem/6568

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int to_int(string s) {
	int ret = 0, len = s.length() - 1;
	for (char c : s) {
		ret += (c - '0') * pow(2, len);
		len--;
	}
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string input;
	while (cin >> input) {
		vector<int> mem(32);
		for (int i = 0; i < 32; i++) {
			if (i != 0)
				cin >> input;
			mem[i] = to_int(input);
		}
		int adder = 0;
		int idx = 0;
		while (true) {
			int op = mem[idx] / 32;
			int val = mem[idx] % 32;
			bool flag = false;
			idx = (idx + 1) % 32;
			switch (op) {
			case 0:
				mem[val] = adder;
				break;
			case 1:
				adder = mem[val];
				break;
			case 2:
				if (adder == 0)
					idx = val;
				break;
			case 3:
				break;
			case 4:
				adder = (adder + 255) % 256;
				break;
			case 5:
				adder = (adder + 1) % 256;
				break;
			case 6:
				idx = val;
				break;
			case 7:
				flag = true;
				break;
			}
			if (flag)
				break;
		}
		for (int i = 7; i >= 0; i--)
			cout << ((adder >> i) & 1);
		cout << '\n';
	}
}

/* 
   8비트 가산기, 5비트 프로그램 카운터, 32바이트(32 * 8비트) 메모리와 아래와 같은 명령어 구조를 갖춘 컴퓨터 구조를 만들어 32줄의 프로그램을 돌린 후 가산기의 상태 출력하기
   000xxxxx   STA x   메모리 주소 x에 가산기의 값을 저장한다.
   001xxxxx   LDA x   메모리 주소 x의 값을 가산기로 불러온다.
   010xxxxx   BEQ x   가산기의 값이 0이면 PC 값을 x로 바꾼다.
   011-----   NOP     아무 연산도 하지 않는다.
   100-----   DEC     가산기 값을 1 감소시킨다.
   101-----   INC     가산기 값을 1 증가시킨다.
   110xxxxx   JMP x   PC 값을 x로 바꾼다.
   111-----   HLT     프로그램을 종료한다.
*/

// 우선 여러 개의 테케게 있을 수 있음에 주의 - 더 이상의 입력이 주어지지 않으면(while(cin >> input)) 아웃, 입력 첫 줄은 while에서 대신 받기
// PC가 5비트라서 주어지는 줄도 32개 - 프로그램을 저장할 메모리가 32바이트인 것도 위와 같음
// 따라서 mem은 32칸짜리 배열로 구현
// PC가 31에 도달한다 해도 프로그램은 끝나지 않음 - 실행 자체는 while로 HLT가 나올 때까지 돌려야 하고, ++하는데 mod 연산 필요
// adder는 8비트 - 따라서 연산 역시 mod 연산이 필요함
// 이 문제로 기본적인 컴퓨터구조를 습득하고, 2진수 출력 방법도 습득합시다