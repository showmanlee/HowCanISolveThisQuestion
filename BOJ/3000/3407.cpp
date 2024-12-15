// 맹세
// https://www.acmicpc.net/problem/3407

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

string dict[114] = { "h", "li", "na", "k", "rb", "cs", "fr", "be", "mg", "ca", "sr", "ba", "ra", "sc", "y", "ti", "zr", "hf", "rf", "la", "ac", "v", "nb", "ta", "db", "ce", "th", "cr", "mo", "w", "sg", "pr", "pa", "mn", "tc", "re", "bh", "nd", "u", "fe", "ru", "os", "hs", "pm", "np", "co", "rh", "ir", "mt", "sm", "pu", "ni", "pd", "pt", "ds", "eu", "am", "cu", "ag" ,"au", "rg", "gd", "cm", "zn", "cd", "hg", "cn", "tb", "bk", "b", "al", "ga", "in", "tl", "dy", "cf", "c", "si", "ge", "sn", "pb", "fl", "ho", "es", "n", "p", "as", "sb", "bi", "er", "fm", "o", "s", "se", "te", "po", "lv", "tm", "md", "f", "cl", "br", "i", "at", "yb", "no", "he", "ne", "ar", "kr", "xe", "rn","lu", "lr" };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        string s;
        cin >> s;
        queue<int> q;
        vector<bool> visit(s.length() + 1, false);
        q.push(0);
        visit[0] = true;
        bool res = false;
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            if (p == s.length()) {
                res = true;
                break;
            }
            string s1, s2;
            s1 = s.substr(p, 1);
            if (p < s.length() - 1) {
                s2 = s.substr(p, 2);
            }
            for (int i = 0; i < 114; i++) {
                if (!visit[p + 1] && s1 == dict[i]) {
                    visit[p + 1] = true;
                    q.push(p + 1);
                } else if (!visit[p + 2] && s2 == dict[i]) {
                    visit[p + 2] = true;
                    q.push(p + 2);
                }
            }
        }
        cout << (res ? "YES" : "NO") << '\n';
    }
}

// 원소 기호만으로 주어진 소문자 문자열을 구성할 수 있는지 구하기