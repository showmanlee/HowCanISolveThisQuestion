// 차집합
// https://www.acmicpc.net/problem/1822

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    vector<int> v(a);
    map<int, int> exist;
    for (int i = 0; i < a; i++) {
        cin >> v[i];
        exist[v[i]] = 3;
    }
    for (int i = 0; i < b; i++) {
        int p;
        cin >> p;
        exist[p] -= 2;
    }
    vector<int> res;
    for (int i = 0; i < a; i++) {
        if (exist[v[i]] == 3) {
            res.push_back(v[i]);
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for (int i : res) {
        cout << i << ' ';
    }
    cout << '\n';
}

// 두 자연수 집합 A, B가 주어질 때, 차집합 A-B의 원소 구하기

// 자연수의 범위가 int 범위이므로 배열로는 관리 불가 - map을 사용하여 마킹한다
// A에서 나오면 3을 더하고, B에서 나오면 2를 빼는 식으로 map에 기록해 미리 저장한 A 배열을 순회하며 집합 위치를 확인하며 결과 배열에 기록한다
// 결과 배열을 정렬해서 출력해야 함에 주의