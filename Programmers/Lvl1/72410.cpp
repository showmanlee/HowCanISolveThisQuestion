// 신규 아이디 추천(2021 카카오)
// https://programmers.co.kr/learn/courses/30/lessons/72410

#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string new_id) {
    string answer = "", temp = "";
    
    for (int i = 0; i < new_id.length(); i++)
        if (isupper(new_id[i]))
            new_id[i] = tolower(new_id[i]);
    
    for (int i = 0; i < new_id.length(); i++)
        if (islower(new_id[i]) || isdigit(new_id[i]) || new_id[i] == '.' || new_id[i] == '-' || new_id[i] == '_')
            temp += new_id[i];
    new_id = temp;
    temp = "";
    
    bool isdot = false;
    for (int i = 0; i < new_id.length(); i++){
        if (new_id[i] == '.'){
            if (!isdot){
                isdot = true;
                temp += new_id[i];
            }
        }
        else{
            isdot = false;
            temp += new_id[i];
        }
    }
    new_id = temp;
    temp = "";
    
    if (new_id[0] == '.')
        new_id = new_id.substr(1);
    if (new_id[new_id.length() - 1] == '.')
        new_id = new_id.substr(0, new_id.length() - 1);
    
    if (new_id == "")
        new_id = "a";
    
    if (new_id.length() > 15)
        new_id = new_id.substr(0, 15);
    if (new_id[new_id.length() - 1] == '.')
        new_id = new_id.substr(0, new_id.length() - 1);
    
    while (new_id.length() < 3)
        new_id += new_id[new_id.length() - 1];
            
    answer = new_id;
    return answer;
}

// 주어진 조건대로 아이디 변환하기
// 1. 대문자를 소문자로 변환
// 2. 소문자, 숫자, ._-를 제외한 문제 제거
// 3. 연속된 . 삭제
// 4. 양 끝의 . 삭제
// 5. 4.까지 진행한 결과가 빈 문자열일 경우 a 추가
// 6. 16자 이상일 경우 15자 뒷부분 삭제(후 끝의 . 제거)
// 7. 2자 이하일 경우 3자가 될 때까지 마지막 글자 추가
// 시키는 대로 구현하면 되는 문제