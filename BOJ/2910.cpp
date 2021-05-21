// 빈도 정렬
// https://www.acmicpc.net/problem/2910

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, int> prr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, c;
	cin >> n >> c;
	vector<int> shown;
	map<int, int> count;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (find(shown.begin(), shown.end(), p) == shown.end())
			shown.push_back(p);
		count[p]++;
	}
	vector<prr> sorter;
	for (int i = 0; i < shown.size(); i++)
		sorter.push_back({ {-count[shown[i]], i}, shown[i] });
	sort(sorter.begin(), sorter.end());
	for (int i = 0; i < shown.size(); i++) {
		int cnt = -sorter[i].first.first;
		int num = sorter[i].second;
		for (int j = 0; j < cnt; j++)
			cout << num << ' ';
	}
	cout << '\n';
}

// c까지의 자연수가 등장할 수 있는 길이 n의 수열을 등장 횟수 내림차순 -> 등장 순서 오름차순으로 정렬하여 출력하기
// 즉, 일종의 카운팅 정렬 문제 - 그런데 등장 순서까지 따져줘야 하는
// c가 10억까지 갈 수 있기에 단순 배열로는 카운팅 불가능 - map을 이용해 등장한 수만 카운팅할 수 있도록
// 여기서 등장한 수를 등장 배열에 기록 - set으로 하지 않는 것은 등장 순서까지 기록하기 위해
// 이후 {{등장 횟수, 등장 순서}, 원래 숫자}를 저장하는 정렬용 배열에 지금까지 등장한 수를 순서대로 넣고, 조건에 맞게 정렬({{-a, b}, c})
// 그렇게 정렬한 배열을 순서대로 순회하며 원래 숫자를 등장 횟수만큼 출력해주기