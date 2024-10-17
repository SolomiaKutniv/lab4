#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

#define M_PI 3.14159265358979323846 

class SQUARE  // �������
{
protected:
    double side;

public:
    SQUARE(double s) : side(s) {}

    double area() const // �����
    {
        return side * side;
    }

    double perimeter() const // ��������
    {
        return 4 * side;
    }

    virtual void display(ostream& out) const 
    {
        out << "�������: \n";
        out << "�������: " << side << endl;
        out << "�����: " << area() << endl;
        out << "��������: " << perimeter() << endl;
    }
};

class CIRCLE // ����
{
protected:
    double radius;

public:
    CIRCLE(double r) : radius(r) {}

    double area() const // �����
    {
        return M_PI * radius * radius; 
    }

    double circumference() const // ������� ����
    {
        return 2 * M_PI * radius; 
    }

    virtual void display(ostream& out) const 
    {
        out << "����: \n";
        out << "�����: " << radius << endl;
        out << "�����: " << area() << endl;
        out << "�������: " << circumference() << endl;
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
        file << "���������� ��� ������:\n";
        shape.display(file); 
        file.close();
        cout << "���������� ������ �������� � ����: " << filename << endl;
    }
    else
    {
        cout << "�� ������� ������� ����" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    double side, radius;
    cout << "������ ������� ��������: ";
    cin >> side;
    cout << "������ ����� ����: ";
    cin >> radius;
    CIRCLE_IN_SQUARE shape(side, radius);
    shape.display(cout);
    writeToFile(shape, "D:/oop/shapes.txt");
    return 0;
}