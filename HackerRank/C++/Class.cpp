// Class
// https://www.hackerrank.com/challenges/c-tutorial-class/problem

class Student{
private:
    int age;
    string first_name;
    string last_name;
    int standard;
public:
    void set_age(int age){
        this->age = age;
    }
    int get_age(){
        return age;
    }
    void set_first_name(string first_name){
        this->first_name = first_name;
    }
    string get_first_name(){
        return first_name;
    }
    void set_last_name(string last_name){
        this->last_name = last_name;
    }
    string get_last_name(){
        return last_name;
    }
    void set_standard(int standard){
        this->standard = standard;
    }
    int get_standard(){
        return standard;
    }
    string to_string(){
        stringstream ss;
        ss << age << "," << first_name << "," << last_name << "," << standard;
        return ss.str();
    }
};

// private, public을 이용해 캡슐화한 일반적인 클래스 구조
// cin처럼 하기 위해 string을 활용하기 위해 stringstream을 활용할 수 있습니다