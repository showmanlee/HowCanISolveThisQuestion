// 숫자 맞추기
// https://www.acmicpc.net/problem/4335

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    vector<pr> v;
    while (true) {
        getline(cin, s);
        if (s == "0") {
            break;
        } else {
            int n = stoi(s);
            getline(cin, s);
            if (s == "right on") {
                bool res = true;
                for (pr p : v) {
                    if ((p.second == 1 && p.first <= n) || (p.second == 2 && p.first >= n)) {
                        res = false;
                        break;
                    }
                }
                cout << (res ? "Stan may be honest" : "Stan is dishonest") << '\n';
                v.clear();
            } else if (s == "too high") {
                v.push_back({n, 1});
            } else if (s == "too low") {
                v.push_back({n, 2});
            }
        }
    }
}

// 업다운 게임에서 숫자와 대답이 주어질 때, 거짓말을 했는지 확인하기

// 반드시 게임이 끝난 경우(원래 숫자를 말한 경우)만 주어지므로 그 수를 이용해 진위 여부를 확인하면 된다