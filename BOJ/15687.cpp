// 직사각형
// https://www.acmicpc.net/problem/15687

class Rectangle {
    private:
        int width, height;
    public:
        Rectangle(int width, int height) {
            this->width = width;
            this->height = height;
        }
        int get_width() const {
            return width;
        }
        int get_height() const {
            return height;
        }
        void set_width(int width) {
            if (width > 0 && width <= 1000)
                this->width = width;
        }
        void set_height(int height) {
            if (height > 0 && height <= 2000)
                this->height = height;
        }
        int area() const {
            return width * height;
        }
        int perimeter() const {
            return width * 2 + height * 2;
        }
        bool is_square() const {
            return width == height;
        }
};

// C++ 클래스만 구현하면 되는 특수한 문제
// set_width, set_height의 입력값 처리에 유의