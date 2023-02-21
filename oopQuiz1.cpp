#include<iostream>
#include<conio.h>
using namespace std;

class Point {
private:
	double x, y;
public: 
	Point() {
		x = 0.0;
		y = 0.0;
	}
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}

    void setX(double x)
    {
        this->x = x;
    }

    void setY(double y)
    {
        this->y = y;
    }

    double getX() const
    {
        return x;
    }

    double getY() const
    {
        return y;
    }
    double distanceToPoint(const Point& pointA)
    {
        double xDiff = x - pointA.getX();
        double yDiff = y - pointA.getY();
        return sqrt(xDiff * xDiff + yDiff * yDiff);
    }
};

int main() {
    Point A(2, 3);
    Point B(1, 1);
    cout << pow(A.distanceToPoint(B), 2);
    return 0;
}