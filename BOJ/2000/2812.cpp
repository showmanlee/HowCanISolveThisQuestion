// 크게 만들기
// https://www.acmicpc.net/problem/2812

#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    deque<char> res;
    for (char c : s) {
        while (k != 0 && !res.empty() && res.back() < c) {
            res.pop_back();
            k--;
        }
        res.push_back(c);
    }
    for (int i = 0; i < k; i++)
        res.pop_back();
    while (!res.empty()) {
        cout << res.front();
        res.pop_front();
    }
    cout << '\n';
}

// 주어진 n자리 수에서 숫자의 순서를 바꾸지 않고 k개의 숫자를 지워서 얻을 수 있는 최댓값은?
// 그리디 관점에서 문제를 보면, 앞자리들이 최대한 높아야 최대한 값을 높일 수 있다
// 앞자리의 작은 숫자들을 빼면 곧 최댓값이 된다
// 숫자가 들어왔을 때, 내 앞에 나보다 작은 숫자들이 있으면 그 숫자들을 최대한 뺀 후 숫자를 넣는다
// 그렇게 했음에도 빼야 하는 숫자가 남았을 때는 뒤의 숫자들을 빼준다 - 앞을 뺄 수는 없으니
// 뺄 때는 뒤를 빼고, 출력할 때는 앞을 빼야 하니 deque 기반으로 작성