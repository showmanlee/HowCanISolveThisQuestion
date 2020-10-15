// 나이 순 정렬
// https://www.acmicpc.net/problem/10814

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class person {
public:
	int age;
	int order;
	string name;

	person() {
		this->age = 1;
		this->order = 0;
		this->name = "";
	}
};

bool compare(person a, person b) {
	if (a.age == b.age)
		return a.order < b.order;
	else
		return a.age < b.age;
}

int main(void) {
	int n;
	cin >> n;
	vector<person> people(n);
	for (int i = 0; i < n; i++) {
		cin >> people[i].age >> people[i].name;
		people[i].order = i;
	}
	sort(people.begin(), people.end(), compare);
	for (int i = 0; i < n; i++)
		cout << people[i].age << ' ' << people[i].name << '\n';
}

// 커스텀 소팅 함수