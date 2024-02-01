// 접두사
// https://www.acmicpc.net/problem/1141

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<bool> visit(n);
    int res = n;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!visit[j] && v[j].substr(0, v[i].size()) == v[i]) {
                visit[j] = true;
                res--;
                break;
            }
        }
    }
    cout << res << '\n';
}

// 주어진 문자열 집합에서 어떤 단어가 다른 단어의 접두사가 되지 않는 부분집합의 최대 크기 구하기

// 문자열을 사전 순으로 정렬한 뒤, 앞에서부터 고른 문자열이 뒷 문자열의 접두사가 되는지 확인하고, 최종적으로 그렇지 않은 문자열들만 세서 출력하기