// Grading Students
// https://www.hackerrank.com/challenges/grading/problem

vector<int> gradingStudents(vector<int> grades) {
    vector<int> ret(grades.size());
    for (int i = 0; i < grades.size(); i++){
        if (grades[i] < 38)
            ret[i] = grades[i];
        else if (grades[i] % 5 >= 3)
            ret[i] = grades[i] + (5 - (grades[i] % 5));
        else
            ret[i] = grades[i];
    }
    return ret;
}

// 학생 점수가 5점 단위에서 2점까지 부족한 경우 해당 5점 단위로 올려주기
// 점수를 올려줘도 40점 미만인 경우 무시