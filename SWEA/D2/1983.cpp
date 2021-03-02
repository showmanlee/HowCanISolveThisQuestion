// 1983. 조교의 성적 매기기
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PwGK6AcIDFAUq

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef pair<double, int> pr;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
  	string grade[10] = {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n, k;
        cin >> n >> k;
        vector<pr> students;
        for (int i = 1; i <= n; i++){
            double a, b, c;
            cin >> a >> b >> c;
            double r = a * 0.35 + b * 0.45 + c * 0.2;
            students.push_back({r, i});
        }
        sort(students.begin(), students.end(), greater<pr>());
        for (int i = 0; i < n; i++)
            if (students[i].second == k){
                cout << '#' << test_case << ' ' << grade[i / (n / 10)] << '\n';
                break;
            }
	}
	return 0;
}

// 학생의 성적을 보고 등수에 따라 학점을 부여하라
// 총점을 공식에 맞게 계산하여 정렬한 뒤, 학점을 미리 배열에 저장해 학점 부여
// pair로 총점과 학생 번호를 저장하자