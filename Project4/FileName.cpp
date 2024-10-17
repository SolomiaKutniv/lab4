#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

#define M_PI 3.14159265358979323846 

class SQUARE  // Квадрат
{
protected:
    double side;

public:
    SQUARE(double s) : side(s) {}

    double area() const // Площа
    {
        return side * side;
    }

    double perimeter() const // Периметр
    {
        return 4 * side;
    }

    virtual void display(ostream& out) const 
    {
        out << "Квадрат: \n";
        out << "Сторона: " << side << endl;
        out << "Площа: " << area() << endl;
        out << "Периметр: " << perimeter() << endl;
    }
};

class CIRCLE // Коло
{
protected:
    double radius;

public:
    CIRCLE(double r) : radius(r) {}

    double area() const // Площа
    {
        return M_PI * radius * radius; 
    }

    double circumference() const // Довжина кола
    {
        return 2 * M_PI * radius; 
    }

    virtual void display(ostream& out) const 
    {
        out << "Коло: \n";
        out << "Радіус: " << radius << endl;
        out << "Площа: " << area() << endl;
        out << "Довжина: " << circumference() << endl;
    }
};

class CIRCLE_IN_SQUARE : public SQUARE, public CIRCLE
{
public:
    CIRCLE_IN_SQUARE(double s, double r) : SQUARE(s), CIRCLE(r) {}

    void display(ostream& out) const override 
    {
        SQUARE::display(out);
        CIRCLE::display(out);
    }
};

void writeToFile(const CIRCLE_IN_SQUARE& shape, const string& filename)
{
    ofstream file(filename);

    if (file.is_open())
    {
        file << "Інформація про фігуру:\n";
        shape.display(file); 
        file.close();
        cout << "Інформація успішно записана у файл: " << filename << endl;
    }
    else
    {
        cout << "Не вдалося відкрити файл" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    double side, radius;
    cout << "Введіть сторону квадрата: ";
    cin >> side;
    cout << "Введіть радіус кола: ";
    cin >> radius;
    CIRCLE_IN_SQUARE shape(side, radius);
    shape.display(cout);
    writeToFile(shape, "D:/oop/shapes.txt");
    return 0;
}