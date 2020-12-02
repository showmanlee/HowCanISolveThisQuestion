// 가장 큰 수
// https://programmers.co.kr/learn/courses/30/lessons/42746

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strs;
    for (int i = 0; i < numbers.size(); i++)
        strs.push_back(to_string(numbers[i]));
    
    sort(strs.begin(), strs.end(), [](string a, string b){return (a + b) > (b + a);});
    
    for (int i = 0; i < strs.size(); i++)
        answer += strs[i];
    if (answer[0] == '0')
        return "0";
    return answer;
}

// 음이 아닌 정수들이 주어졌을 때, 정수를 이어붙여 만들 수 있는 가장 큰 수 구하기
// int(a+b)와 int(b+a)를 비교해 정렬하고, 정렬한 결과를 이어붙이면 결과가 나옴
// ex) 3, 30의 비교 - 330 vs 303 = 3이 먼저 나오는 게 우선
// string 간의 비교가 가능하고, 정수만 있는 문자열 비교는 곧 정수 비교와 같기 때문에 int로 형변환을 하지 않아도 정렬 가능
// 그건 그렇고 익명 함수는 저렇게 씁니다. sort 사용할 때 요긴하게 사용하세요