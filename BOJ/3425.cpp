// 고스택
// https://www.acmicpc.net/problem/3425

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<string, int> prs;

class stack {
	vector<int> v;
	int idx;
public:
	stack() {
		v.resize(1001);
		idx = -1;
	}

	int getsize() {
		return idx;
	}
	int getres() {
		return v[idx];
	}
	bool NUM(int x) {
		if (idx >= 1000)
			return false;
		idx++;
		v[idx] = x;
		return true;
	}
	bool POP() {
		if (idx == -1)
			return false;
		idx--;
		return true;
	}
	bool INV() {
		if (idx == -1)
			return false;
		v[idx] = -v[idx];
		return true;
	}
	bool DUP() {
		if (idx >= 1000 || idx == -1)
			return false;
		idx++;
		v[idx] = v[idx - 1];
		return true;
	}
	bool SWP() {
		if (idx <= 0)
			return false;
		swap(v[idx], v[idx - 1]);
		return true;
	}
	bool ADD() {
		if (idx <= 0)
			return false;
		long long res = (long long)v[idx - 1] + (long long)v[idx];
		if (abs(res) > 1000000000)
			return false;
		idx--;
		v[idx] = res;
		return true;
	}
	bool SUB() {
		if (idx <= 0)
			return false;
		long long res = (long long)v[idx - 1] - (long long)v[idx];
		if (abs(res) > 1000000000)
			return false;
		idx--;
		v[idx] = res;
		return true;
	}
	bool MUL() {
		if (idx <= 0)
			return false;
		long long res = (long long)v[idx - 1] * (long long)v[idx];
		if (abs(res) > 1000000000)
			return false;
		idx--;
		v[idx] = res;
		return true;
	}
	bool DIV() {
		if (idx <= 0)
			return false;
		if (v[idx] == 0)
			return false;
		long long res = (long long)v[idx - 1] / (long long)v[idx];
		if (abs(res) > 1000000000)
			return false;
		idx--;
		v[idx] = res;
		return true;
	}
	bool MOD() {
		if (idx <= 0)
			return false;
		if (v[idx] == 0)
			return false;
		long long res = (long long)v[idx - 1] % (long long)v[idx];
		if (abs(res) > 1000000000)
			return false;
		idx--;
		v[idx] = res;
		return true;
	}
};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while(true){
		vector<prs> inst;
		string s;
		cin >> s;
		if (s == "QUIT")
			break;
		else {
			while (true) {
				if (s == "END")
					break;
				inst.push_back({ s, 0 });
				if (s == "NUM") {
					int i;
					cin >> i;
					inst[inst.size() - 1].second = i;
				}
				cin >> s;
			}
		}
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			stack st;
			int t;
			cin >> t;
			st.NUM(t);
			bool succ = true;
			for (prs p : inst) {
				if (p.first == "NUM")
					succ = st.NUM(p.second);
				if (p.first == "POP")
					succ = st.POP();
				if (p.first == "INV")
					succ = st.INV();
				if (p.first == "DUP")
					succ = st.DUP();
				if (p.first == "SWP")
					succ = st.SWP();
				if (p.first == "ADD")
					succ = st.ADD();
				if (p.first == "SUB")
					succ = st.SUB();
				if (p.first == "MUL")
					succ = st.MUL();
				if (p.first == "DIV")
					succ = st.DIV();
				if (p.first == "MOD")
					succ = st.MOD();
				if (!succ)
					break;
			}
			if (st.getsize() != 0)
				succ = false;
			if (succ)
				cout << st.getres() << '\n';
			else
				cout << "ERROR\n";
		}
		cout << '\n';
	}
}

// 특별한 연산자들이 추가된 스택에서 작동하는 명령어 프로그램이 주어질 때, 처음에 특정 수를 넣고 프로그램을 돌린 결과 출력하기

// NUM(PUSH), POP을 제외한 추가된 연산자는 대개 top 아래의 수도 다루는 경우 - 따라서 직접 구현하는 것이 편함
// INV - top 부호 바꾸기, DUP - top을 다시 push, SWP - top과 그 아래 수의 위치 교체
// ADD, SUB, MUL, DIV, MOD - top 아래의 수와 top을 연산한 값을 삽입(두 수를 pop 한 이후에 결과값 push, div 0 또는 결과의 절댓값이 1000000000을 넘을 경우 에러)
// 이러한 연산자 + 크기와 top을 반환하는 함수를 가진 새로운 스택 클래스를 만들어서 사용해보자 - 인덱스 포인터를 활용하여 연산

// 우선 명령어들을 받는다 - NUM의 경우 push하는 수까지 같이 받으므로 pair 배열 형태로 저장
// 이후 초기에 들어가는 숫자를 받고 프로그램을 돌리는데, 실행 중 에러 발생이 확인된 경우(스택 함수 반환값) 바로 실행 종료 후 에러 판정
// 그리고 스택 크기를 확인하여 스택 사이즈가 1(인덱스가 0)이 아닐 때도 에러 판정
// 그렇게 에러 판정이 안 뜬 경우 top 값(스택의 유일한 값)을 출력