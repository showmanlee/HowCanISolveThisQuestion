// 강당 대관
// https://www.acmicpc.net/problem/31994

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    
    string ress;
    int resn = 0;
    for (int i = 0; i < 7; i++) {
        string s;
        int n;
        cin >> s >> n;
        if (resn < n) {
            ress = s;
            resn = n;
        }
    }
    cout << ress << '\n';
}

// 7가지 수업명과 수강 인원이 주어질 때, 가장 많은 사람이 듣는 수업명 출력하기