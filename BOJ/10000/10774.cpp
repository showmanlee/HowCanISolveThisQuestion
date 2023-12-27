// 저지
// https://www.acmicpc.net/problem/10774

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int j, a;
    cin >> j >> a;
    vector<char> judge(j + 1);
    for (int i = 1; i <= j; i++) {
        cin >> judge[i];
    }
    int res = 0;
    for (int i = 0; i < a; i++) {
        char c;
        int n;
        cin >> c >> n;
        if (judge[n] == 'S') {
            if (c == 'S') {
                judge[n] = 'X';
                res++;    
            }
        } else if (judge[n] == 'M') {
            if (c == 'M' || c == 'S') { 
                judge[n] = 'X';
                res++;
            }
        } else if (judge[n] == 'L') { 
            if (c == 'L' || c == 'M' || c == 'S') { 
                judge[n] = 'X'; 
                res++;
            }    
        }
    }
    cout << res << '\n';
}

// 각자 선호하는 번호와 선호하는 사이즈 또는 그 보다 큰 저지를 입을 때 만족할 때, 주어진 번호와 사이즈의 저지로 최대로 만족시킬 수 있는 사람 구하기

// 일단 사람이 만족하기 위해서는 무조건 같은 번호여야 함 - 그리고 한 장만 받을 수 있음
// 따라서 저지들을 순회할 때 그 사람이 원하는 저지의 번호에 사이즈가 맞을 때, 그 사람에게 줘버린다