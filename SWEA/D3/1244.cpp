// 1244. [S/W 문제해결 응용] 2일차 - 최대 상금
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15Khn6AN0CFAYD

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dfs(string s, int n){
    if (n == 0)
        return stoi(s);
    int len = s.length();
    int ret = 0;
    for (int i = 0; i < len - 1; i++){
        for (int j = i + 1; j < len; j++){
            swap(s[i], s[j]);
            ret = max(ret, dfs(s, n - 1));
            swap(s[i], s[j]);
        }
    }
    return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string s;
        int n;
        cin >> s >> n;
        if (n > s.length())
            n = s.length();
        cout << '#' << test_case << ' ' << dfs(s, n) << '\n';
	}
	return 0;
}

// 일렬로 놓인 숫자 카드를 n번 교환해 만들 수 있는 최댓값 구하기
// 브루트포스 - 그러나 교환 횟수가 넘어가면 시간 초과?
// 관점의 전환 - 사실 카드 두 장을 교환하는 행위는 카드 하나를 원하는 위치에 넣는 것과 크게 다르지 않다
// 그리고 문제에서도 두 번 교환하여 원래 상태로 돌아가는 것을 허용하고 있음
// 따라서 n이 카드의 수보다 많을 경우 n을 카드의 수만큼 줄여도 원하는 결과를 얻을 수 있음(?)