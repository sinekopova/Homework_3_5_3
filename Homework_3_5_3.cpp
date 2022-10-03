#include <iostream>
#include <string>

class Figure {
public:
    Figure() {
        sidesCount = 0;
        name = "Фигура";
    };
    virtual std::string getSides() {
        return "";
    };
    virtual std::string getAngles() {
        return "";
    };
    std::string getName() {
        return name;
    };
    virtual bool checkFigure() {
        if (sidesCount != 0) {
            return false;
        }
        return true;
    };
    int getSidesCount() {
        return sidesCount;
    };

protected:
    std::string name;
    int sidesCount;
};

class Triangle : public Figure {
public:
    Triangle(int a, int b, int c, int A, int B, int C) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
        name = "Треугольник";
        sidesCount = 3;
    };
    std::string getSides() override {
        return "a = " + std::to_string(a) + ", b = " + std::to_string(b) + ", c = " + std::to_string(c);
    };
    std::string getAngles() override {
        return "A = " + std::to_string(A) + ", B = " + std::to_string(B) + ", C = " + std::to_string(C);
    };
    bool checkFigure() override{
        if (sidesCount != 3) {
            return false;
        }
        if (a == 0 || b == 0 || c == 0){
            return false;
        }
        if ( A + B + C != 180 ){
            return false;
        }        
        return true;
    };
protected:
    int A, B, C;
    int a, b, c;
};

class Quadrangle : public Figure {
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
        name = "Четырехугольник";
        sidesCount = 4;
    };
    std::string getSides() override {
        return "a = " + std::to_string(a) + ", b = " + std::to_string(b) + ", c = " + std::to_string(c) + ", d = " + std::to_string(d);
    };
    std::string getAngles() override {
        return "A = " + std::to_string(A) + ", B = " + std::to_string(B) + ", C = " + std::to_string(C) + ", D = " + std::to_string(D);
    };
    bool checkFigure() override {
        if (sidesCount != 4) {
            return false;
        }
        if (a == 0 || b == 0 || c == 0 || d ==0 ) {
            return false;
        }
        if (A + B + C + D != 360) {
            return false;
        }
        return true;
    };
protected:
    int A, B, C, D;
    int a, b, c, d;
};

class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
        name = "Прямоугольный треугольник";
    };
    bool checkFigure() {
        bool result = Triangle::checkFigure();
        if ( C != 90) {
            result = false;
        }
        return result;
    };
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int c, int A, int B) : Triangle(a, a, c, A, B, A) {
        name = "Равнобедренный треугольник";
    };
    bool checkFigure() {
        bool result = Triangle::checkFigure();
        if (a != c || A != C) {
            result = false;
        }
        return result;
    };
};

class EquilateralTriangle : public IsoscelesTriangle {
public:
    EquilateralTriangle(int a) : IsoscelesTriangle(a, a, 60, 60) {
        name = "Равносторонний треугольник";
    };
    bool checkFigure() {
        bool result = IsoscelesTriangle::checkFigure();
        if ( !( a == b  &&  b == c && A == B && B == C && C == 60 ) )  {
            result = false;
        }
        return result;
    };
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) {
        name = "Параллелограм";
    };
    bool checkFigure() {
        bool result = Quadrangle::checkFigure();
        if ( !( a == c && b == d ) || !(A == C && B == D ) ) {
            result =  false;
        }
        return result;
    };
};

class Rectangle : public Parallelogram {
public:
    Rectangle(int a, int b) : Parallelogram(a, b, 90, 90) {
        name = "Прямоугольник";
    };
    bool checkFigure() {
        bool result = Parallelogram::checkFigure();
        if (!(a == c && b == d) || !(A == B && B == C && C == D && D == 90 ) ) {
            result =  false;
        }
        return result;
    };
};

class Rhomb : public Parallelogram {
public:
    Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B) {
        name = "Ромб";
    };
    bool checkFigure() {
        bool result = Parallelogram::checkFigure();
        if ( !( a == b && b == c && c == d) || !( A == C && B == D ) ) {
            result =  false;
        }
        return result;
    };
};

class Square : public Rhomb {
public:
    Square(int a) : Rhomb(a, 90, 90) {
        name = "Квадрат";
    };
    bool checkFigure() {
        bool result = Rhomb::checkFigure();
        if ( !(A == B && B == C && C == D && D == 90) ) {
            result = false;
        }
        return result;
    };
};

void printFigureInfo(Figure* fig) {
    std::cout << fig->getName() << " : " << std::endl;
    std::cout << (fig->checkFigure()?"Правильная":"Неправильная") << std::endl;
    std::cout << "Количество сторон : " << fig->getSidesCount() << std::endl;
    std::string sides = fig->getSides();
    if (!sides.empty()) {
        std::cout << "Стороны : " << sides << std::endl;
    }
    std::string angles = fig->getAngles();
    if (!angles.empty()) {
        std::cout << "Углы : " << angles << std::endl;
    }; 
    std::cout << std::endl;
};

int main()
{

    setlocale(LC_ALL, "Russian");

    Figure figure;
    printFigureInfo(&figure);

   Triangle triangle(10, 20, 30, 50, 60, 70);
    printFigureInfo(&triangle);

    RightTriangle rightTriangle1(10, 20, 30, 50, 60);
    printFigureInfo(&rightTriangle1);

    RightTriangle rightTriangle2(10, 20, 30, 50, 40);
    printFigureInfo(&rightTriangle2);

    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
    printFigureInfo(&isoscelesTriangle);

    EquilateralTriangle equilateralTriangle(30);
    printFigureInfo(&equilateralTriangle);

    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    printFigureInfo(&quadrangle);

    Rectangle rectangle(10, 20);
    printFigureInfo(&rectangle);

    Square square(20);
    printFigureInfo(&square);

    Parallelogram parallelogram(20, 30, 30, 40);
    printFigureInfo(&parallelogram);        

    Rhomb rhomb(30, 30, 40);
    printFigureInfo(&rhomb);

}
