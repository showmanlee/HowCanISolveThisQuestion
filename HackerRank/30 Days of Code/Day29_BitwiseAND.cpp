// Day 29: Bitwise AND
// https://www.hackerrank.com/challenges/30-bitwise-and/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nk_temp;
        getline(cin, nk_temp);

        vector<string> nk = split_string(nk_temp);

        int n = stoi(nk[0]);
        int k = stoi(nk[1]);
        
        int res = 0;
        for (int i = 1; i < n; i++){
            for (int j = i + 1; j <= n; j++)
                if ((i & j) > res && (i & j) < k)
                    res = (i & j);
        }
        cout << res << '\n';
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

// 1~n까지 수 사이에 AND 연산한 결과 중 k 미만의 가장 큰 값 출력하기
// 30 Days of Code 끝! 올 한 해 마무리 잘 하시길 바랍니다
// 이제 문풀에 집중합시다