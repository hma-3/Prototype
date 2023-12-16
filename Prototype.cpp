#include <iostream>

using namespace std;

class Shape {
public:
    virtual void draw() = 0;
};

class Rectangle : public Shape {
public:
    Rectangle(int width, int height) : width_(width), height_(height) {}

    void draw() override {
        cout << "Drawing rectangle with width " << width_ << " and height " << height_ << endl;
    }

private:
    int width_;
    int height_;
};

class Circle : public Shape {
public:
    Circle(int radius) : radius_(radius) {}

    void draw() override {
        cout << "Drawing circle with radius " << radius_ << endl;
    }

private:
    int radius_;
};

class ShapeBuilder {
public:
    virtual Shape* createRectangle(int width, int height) = 0;
    virtual Shape* createCircle(int radius) = 0;
};

class RectangleBuilder : public ShapeBuilder {
public:
    Shape* createRectangle(int width, int height) override {
        return new Rectangle(width, height);
    }

    Shape* createCircle(int radius) override {
        return nullptr;
    }
};

class CircleBuilder : public ShapeBuilder {
public:
    Shape* createRectangle(int width, int height) override {
        return nullptr;
    }

    Shape* createCircle(int radius) override {
        return new Circle(radius);
    }
};

int main() {
    RectangleBuilder rectangleBuilder;
    Shape* rectangle = rectangleBuilder.createRectangle(10, 20);
    rectangle->draw();

    CircleBuilder circleBuilder;
    Shape* circle = circleBuilder.createCircle(5);
    circle->draw();

    return 0;
}
