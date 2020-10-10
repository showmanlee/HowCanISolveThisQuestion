// Alternating Characters
// https://www.hackerrank.com/challenges/alternating-characters/

int alternatingCharacters(string s) {
    int count = 0;
    for (int i = 1; i < s.length(); i++){
        if (s[i - 1] == s[i])
            count++;
    }
    return count;
}

// A와 B로 구성된 문자열에서 반복되는 문자를 하나로 줄이고 싶은데, 그 과정에서 줄어드는 문자 개수 구하기