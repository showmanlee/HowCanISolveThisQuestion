// 7701. 염라대왕의 이름 정렬
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWqU0zh6rssDFARG

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    if (a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        cin >> n;
        vector<string> names(n);
        for (string& s : names)
            cin >> s;
        sort(names.begin(), names.end(), compare);
        names.erase(unique(names.begin(), names.end()), names.end());
        cout << '#' << test_case << '\n';
        for (string s : names)
            cout << s << '\n';
	}
	return 0;
}

// 이름의 중복을 모두 제거하고(erase(unique(begin(), end()), end())), 길이 순(같을 경우 사전 순)으로 정렬하라