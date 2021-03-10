// 트ㅏㅊ;
// https://www.acmicpc.net/problem/4378

#include <iostream>
#include <string>
using namespace std;

char convert(char c) {
	switch (c) {
	case '1': return '`';
	case '2': return '1';
	case '3': return '2';
	case '4': return '3';
	case '5': return '4';
	case '6': return '5';
	case '7': return '6';
	case '8': return '7';
	case '9': return '8';
	case '0': return '9';
	case '-': return '0';
	case '=': return '-';
    case 'W': return 'Q';
    case 'E': return 'W';
    case 'R': return 'E';
    case 'T': return 'R';
    case 'Y': return 'T';
    case 'U': return 'Y';
    case 'I': return 'U';
    case 'O': return 'I';
    case 'P': return 'O';
    case '[': return 'P';
    case ']': return '[';
    case '\\': return ']';
    case 'S': return 'A';
    case 'D': return 'S';
    case 'F': return 'D';
    case 'G': return 'F';
    case 'H': return 'G';
    case 'J': return 'H';
    case 'K': return 'J';
    case 'L': return 'K';
    case ';': return 'L';
    case '\'': return ';';
    case 'X': return 'Z';
    case 'C': return 'X';
    case 'V': return 'C';
    case 'B': return 'V';
    case 'N': return 'B';
    case 'M': return 'N';
    case ',': return 'M';
    case '.': return ',';
    case '/': return '.';
    case ' ': return ' ';
	}
	return ' ';
}

int main(void) {
    while (true) {
        string s;
        getline(cin, s);
        if (s.length() == 0)
            break;
        for (char c : s)
            cout << convert(c);
        cout << '\n';
    }
}

// 쿼티 키보드를 오른쪽으로 한 칸씩 밀려쳤을 때, 정상적인 키 입력으로 변환하기
// 말 그대로 `QAZ을 제외하고 나머지 문자들을 한 칸 왼쪽의 문자로 변환하면 된다
// 여러 줄이 입력됨에 주의
// 문제의 제목은 '쿼티'