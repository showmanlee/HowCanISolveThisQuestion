// Sherlock and the Valid String
// https://www.hackerrank.com/challenges/sherlock-and-valid-string

string isValid(string s) {
    vector<int> count(26);
    for (int i = 0; i < s.length(); i++)
        count[s[i] - 'a']++;
    sort(count.begin(), count.end(), greater<int>());
    for (int i = 0; i < 26; i++)
        cout << count[i] << ' ';
    cout << endl;

    int prev = count[0];
    bool checked = false;
    int checker = 0;
    int all = 0;
    bool sp = 0;

    for (int i = 0; i < 26; i++){
        if (count[i] == 0)
            break;
        all++;
        if (prev - count[i] > 1){
            if (count[i] != 1)
                return "NO";
            checked = true;
            checker++;
            sp = true;
        }
        else if (prev - count[i] == 1){
            if (checked)
                return "NO";
            checked = true;
            checker++;
        }
        else{
            if (checked)
                checker++;
            if (sp && count[i] == 1)
                return "NO";
        }
        prev = count[i];
    }
    cout << checked << " " << all << " " << checker << endl;
    if (checked){
        if (checker == 1 || all - checker == 1)
            return "YES";
        return "NO";
    }
    return "YES";
}

// 알파벳 소문자로 이루어진 문장에서 모든 글자가 같은 수로 나오거나 한 글자만 빼서 같은 수로 만들 수 있으면 YES, 그렇지 않으면 NO
// 하나만 1인 경우 핸들링 필요 -> 하나 빼고 모두 1인 경우도 핸들링 필요