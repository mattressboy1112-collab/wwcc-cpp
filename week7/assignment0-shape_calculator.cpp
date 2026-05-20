#include <iostream>
#include <iomanip>
using namespace std;

double const PI = 3.14159;

class Rectangle {
    private:
        int length, width;
    public:
        Rectangle(double l = 1, double w = 1) {length = l; width = w;};
        Rectangle resize(double resize_factor) {
            this->length *= resize_factor;
            this->width *= resize_factor;
            return *this;
        }    
        double area() {
            return (this->length * this->width);
        }
        void area(double& var)   {
            var = this->length * this->width;
        }
        double getLength() const {
            return length;
        }
        double getWidth() const {
            return width;
        }
        bool setLength(double l) {
            if (l > 0) {
                this->length = l;
                return true;
            }
            return false;
        }
        bool setWidth(double w) {
            if (w > 0) {
                this->width = w;
                return true;
            }
            return false;
        }
        void print() {
            double temp_area;
            cout << endl << "Rectangle (Length: "<< length << ", Width: " << width << ')' << endl;
            cout << "Area: " << this->area() << endl;
            this->area(temp_area);
            cout << "Area via reference: " << temp_area << endl;
        }
};

class Circle {
    private:
        double radius;
    public:
        Circle(double r = 1) {radius = r;}
        bool setRadius(double r) {
            if (r > 0) {
                this->radius = r;
                return true;
            }
            return false;
        }
        double getRadius() const {
            return this->radius;
        }
        double circumference() {return (2 * PI * radius);}
        double area() {return (PI * radius * radius);}
        void print() {
            cout << endl << "Circle (Radius: "<< radius << ')' << endl;
            cout << "Area: " << this->area() << endl;
            cout << "Circumference: " << this->circumference() << endl;
        }
        void print(bool check) {
            if (check == true) {
                cout << endl << "Circle Details:" << endl;
                cout << "Radius:\t\t" << radius << endl;
                cout << "Area:\t\tpi x " << radius << "^2 = " << this->area() << endl;
                cout << "Circumference:\t2 x pi x" << radius << " = " << this->circumference() << endl;
            } else {
                print();
            }
        }
};

Rectangle subtract(Rectangle& rec1, Rectangle rec2) {
    rec1.setLength(rec1.getLength()-rec2.getLength());
    rec1.setWidth(rec1.getWidth()-rec2.getWidth());
    return rec1;
}

Rectangle add(Rectangle& rec1, Rectangle rec2) {
    rec1.setLength(rec1.getLength()+rec2.getLength());
    rec1.setWidth(rec1.getWidth()+rec2.getWidth());
    return rec1;
}

Rectangle makeSquare(double size) {
    Rectangle rec (size,size);
    return rec;
}

int main() {
    cout << "SHAPE CALCULATOR" << endl;
    cout << "----------------" << endl;
    Rectangle r (9,10);
    r.print();
    Circle c (3);
    c.print();
    c.print(true);
    cout << endl << "Method chaining:" << endl;
    cout << "Original:\t\tLength = " << r.getLength() << ", Width = " << r.getWidth() << endl;
    cout << "After Resize(2.0):\tLength = " << r.resize(2).getLength() << ", Width = " << r.getWidth() << endl;
    cout << endl << "Test:" << endl;
    cout << r.setLength(0) << endl;
    cout << r.setWidth(0) << endl;
    cout << c.setRadius(0) << endl;
    Rectangle r2;
    r2.setLength(4);
    cout << subtract(r,r2).getLength() << ' ' << r.getWidth();
    return 0;
}