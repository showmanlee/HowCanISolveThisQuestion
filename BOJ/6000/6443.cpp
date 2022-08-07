// 애너그램
// https://www.acmicpc.net/problem/6443

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        do {
            cout << s << '\n';
        } while(next_permutation(s.begin(), s.end()));
    }
}

// 주어진 문자열의 글자들을 재배치하여 만들 수 있는 모든 경우를 중복 없이 출력하기

// string은 곧 vector - 그리고 vector에는 next_permutation으로 모든 순열을 구할 수 있음
// 그리고 next_permutation은 중복도 걸러준다 - 따라서 이걸 이용해 풀 수 있음
// 만약 이걸 못 쓴다면 문자열을 정렬한 뒤 백트래킹으로 하나씩 뽑으며, 중복되는 문자열이 있는지 set 등으로 확인해야 함