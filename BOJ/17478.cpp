// 재귀함수가 뭔가요?
// https://www.acmicpc.net/problem/17478

#include <iostream>
#include <string>
using namespace std;

void rec(int n, int max) {
	string jump = "";
	for (int i = 0; i < n; i++)
		jump += "____";
	cout << jump <<  "\"재귀함수가 뭔가요?\"" << '\n';
	if (n == max) {
		cout << jump << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << '\n';
	}
	else {
		cout << jump << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << '\n';
		cout << jump << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << '\n';
		cout << jump << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << '\n';
		rec(n + 1, max);
	}
	cout << jump << "라고 답변하였지." << '\n';
}

int main(void) {
	int n;
	cin >> n;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << '\n';
	rec(0, n);
}

// 재귀함수로 문장 출력하기
// 최초 호출 전 "어느 한..."
// 함수 진입 후 "재귀함수가..."
// 중단 조건이면 "재귀함수는..." 아니라면 "잘 들어보게..." 후 재귀 호출
// 함수 탈출 직전에 "라고 답변하였지."
// 깊이가 깊어질 수록 ____이 앞에 붙어야 함
// 문장이 정확히 출력되고 있는지 확인(띄어쓰기, 마침표, 따옴표 등)