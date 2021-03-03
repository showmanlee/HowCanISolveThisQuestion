// 1966. 숫자를 정렬하자
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PrmyKAWEDFAUq

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int& i : v)
            cin >> i;
        sort(v.begin(), v.end());
        cout << '#' << test_case << ' ';
        for (int i : v)
            cout << i << ' ';
        cout << '\n';
	}
	return 0;
}

// 말 그대로 정렬하기
// 이미 좋은 알고리즘이 있는데 구현해서 쓰면 귀찮기도 해 어떻게 다른 걸 쓰겠어
// 그런데 TIL에 있는 정렬 알고리즘이 안 먹힌다 - nlogn 코드들은 모두 손봐야겠다 