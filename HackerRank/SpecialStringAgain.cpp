// Special String Again
// https://www.hackerrank.com/challenges/special-palindrome-again

long substrCount(int n, string s) {
    long count = 0;
    for (int i = 0; i < n; i++){
        char c = s[i];
        int p = -1;
        count++;
        for (int j = i + 1; j < n; j++){
            if (s[j] == c){
                if (p == -1)
                    count++;
                else if (p > 0){
                    p--;
                    if (p == 0){
                        count++;
                        break;
                    }
                }
            }
            else{
                if (p == -1)
                    p = j - i;
                else
                    break;
            }
        }
    }
    return count;
}

// 소문자로 구성된 문자열에서 전체가 같은 글자거나(a, aaa...), 중앙의 한 글자만 다른 경우(aabaa, aba, eeeebeeee...)인 substring의 개수는(중복 허용)?