// Rectangle Area
// https://www.hackerrank.com/challenges/rectangle-area/problem

class Rectangle{
protected:
    int width;
    int height;
public:
    void display(){
        cout << width << ' ' << height << '\n';
    }
};

class RectangleArea : public Rectangle{
public:
    void read_input(){
        cin >> Rectangle::width >> Rectangle::height;
    }

    void display(){
        cout << (Rectangle::width * Rectangle::height) << '\n';
    }
};

// 부모 객체를 가져올 때는 저런 식으로(protected 필요)