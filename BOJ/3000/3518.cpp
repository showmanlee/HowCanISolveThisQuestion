// 공백왕 빈-칸
// https://www.acmicpc.net/problem/3518

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<vector<string>> strs;
    vector<int> sections;
    int cnt = -1;
    string s;
    int idx = -1;
    while (getline(cin, s)) {
        stringstream ss(s);
        idx++;
        int p = -1;
        strs.push_back(vector<string>());
        string t;
        while (ss >> t) {
            strs[idx].push_back(t);
            p++;
            if (cnt < p) {
                cnt = p;
                sections.push_back(t.length());
            } else {
                sections[p] = max(sections[p], (int)t.length());
            }
        }
    }
    for (auto& v : strs) {
        int n = v.size();
        for (int i = 0; i < n; i++) {
            cout << v[i];
            if (i != n - 1) {
                for (int j = v[i].length(); j <= sections[i]; j++) {
                    cout << ' ';
                }
            }
        }
        cout << '\n';
    }
}

// 공백이 포함된 여러 줄의 문자열을 단어 별로 열을 맞춰 출력하기

// getline으로 한 줄을 받고, stringstream으로 분리하면서 각 열의 최대 길이를 계산해준다 - 그러면서 단어 단위로 분리하고
// 이렇게 얻은 최대 길이를 이용해 단어 출력 중 공백을 넣어준다 - 마지막 단어는 공백이 빠져야 함에 주의