// 새로운 하노이 탑
// https://www.acmicpc.net/problem/12906

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<pair<string, string>, string> prr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int na, nb, nc;
    string sa, sb, sc;
    string da, db, dc;
    cin >> na;
    if (na > 0) {
        cin >> sa;
        for (char c : sa) {
            if (c == 'A') {
                da += 'A';
            }
            if (c == 'B') {
                db += 'B';
            }
            if (c == 'C') {
                dc += 'C';
            }
        }
    }
    cin >> nb;
    if (nb > 0) {
        cin >> sb;
        for (char c : sb) {
            if (c == 'A') {
                da += 'A';
            }
            if (c == 'B') {
                db += 'B';
            }
            if (c == 'C') {
                dc += 'C';
            }
        }
    }
    cin >> nc;
    if (nc > 0) {
        cin >> sc;
        for (char c : sc) {
            if (c == 'A') {
                da += 'A';
            }
            if (c == 'B') {
                db += 'B';
            }
            if (c == 'C') {
                dc += 'C';
            }
        }
    }
    map<prr, int> visit;
    queue<prr> q;
    q.push({{sa, sb}, sc});
    visit[{{sa, sb}, sc}] = 1;
    int res = 0;

    while (!q.empty()) {
        string a = q.front().first.first;
        string b = q.front().first.second;
        string c = q.front().second;
        q.pop();
        if (a == da && b == db && c == dc) {
            res = visit[{{a, b}, c}] - 1;
            break;
        }

        string aa, bb, cc;

        if (!a.empty()) {
            aa = a.substr(0, a.length() - 1);
            bb = b + a.back();
            cc = c;
            if (visit[{{aa, bb}, cc}] == 0) {
                visit[{{aa, bb}, cc}] = visit[{{a, b}, c}] + 1;
                q.push({{aa, bb}, cc});
            }
            aa = a.substr(0, a.length() - 1);
            bb = b;
            cc = c + a.back();
            if (visit[{{aa, bb}, cc}] == 0) {
                visit[{{aa, bb}, cc}] = visit[{{a, b}, c}] + 1;
                q.push({{aa, bb}, cc});
            }
        }
        if (!b.empty()) {
            aa = a + b.back();
            bb = b.substr(0, b.length() - 1);
            cc = c;
            if (visit[{{aa, bb}, cc}] == 0) {
                visit[{{aa, bb}, cc}] = visit[{{a, b}, c}] + 1;
                q.push({{aa, bb}, cc});
            }
            aa = a;
            bb = b.substr(0, b.length() - 1);
            cc = c + b.back();
            if (visit[{{aa, bb}, cc}] == 0) {
                visit[{{aa, bb}, cc}] = visit[{{a, b}, c}] + 1;
                q.push({{aa, bb}, cc});
            }
        }
        if (!c.empty()) {
            aa = a + c.back();
            bb = b;
            cc = c.substr(0, c.length() - 1);
            if (visit[{{aa, bb}, cc}] == 0) {
                visit[{{aa, bb}, cc}] = visit[{{a, b}, c}] + 1;
                q.push({{aa, bb}, cc});
            }
            aa = a;
            bb = b + c.back();
            cc = c.substr(0, c.length() - 1);
            if (visit[{{aa, bb}, cc}] == 0) {
                visit[{{aa, bb}, cc}] = visit[{{a, b}, c}] + 1;
                q.push({{aa, bb}, cc});
            }
        }
    }
    cout << res << '\n';
}

// A/B/C 기둥에 A/B/C 원판을 모두 옮겨야 하는 새로운 하노이 탑이 있을 때, 주어진 상태에서 최종 상태로 만드는 최소 이동 횟수 구하기

// 문자열 형태로 주어지긴 하지만, string pair와 map으로 visit를 두면 bfs로 접근 가능