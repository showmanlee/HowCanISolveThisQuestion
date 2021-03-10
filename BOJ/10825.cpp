// 국영수
// https://www.acmicpc.net/problem/10825

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct student {
	int korean;
	int english;
	int math;
	string name;
	student() {
		korean = english = math = 0;
		name = "";
	}
	student(int k, int e, int m, string n) : korean(k), english(e), math(m), name(n) {}
	bool operator<(student a) {
		if (this->korean != a.korean)
			return this->korean > a.korean;
		if (this->english != a.english)
			return this->english < a.english;
		if (this->math != a.math)
			return this->math > a.math;
		return this->name < a.name;
	}
};

int main(void) {
	int n;
	cin >> n;
	vector<student> v(n);
	for (student& s : v)
		cin >> s.name >> s.korean >> s.english >> s.math;
	sort(v.begin(), v.end());
	for (student& s : v)
		cout << s.name << '\n';
}

// 학생들을 주어진 순서대로 정렬하라
// 국어 내림차순 -> 영어 오름차순 -> 수학 내림차순 -> 이름 사전순
// < 연산자 오버로딩 후 sort 돌리기
// < 은 오름차순, > 은 내림차순