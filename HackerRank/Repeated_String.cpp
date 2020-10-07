// Repeated String
// https://www.hackerrank.com/challenges/repeated-string

long repeatedString(string s, long n) {
    int nn = n % s.length();
    vector<int> aa;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == 'a')
            aa.push_back(i);
    long answer = n / s.length() * aa.size();
    for (int i = 0; i < aa.size(); i++)
        if (aa[i] < nn)
            answer++;
    return answer;
}

// 주어진 문자열은 n글자만큼 반복했을 때, a는 얼마나 많이 나오는가?