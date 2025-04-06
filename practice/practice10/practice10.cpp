//used chat gpt to assist

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <cmath>
#include <iomanip>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
    double width;
    double height;

public:
    Rectangle(double width, double height)
        : width(width), height(height) {
    }

    double getArea() const override {
        return width * height;
    }
};

class Circle : public Shape {
    double radius;

public:
    Circle(double radius)
        : radius(radius) {
    }

    double getArea() const override {
        return M_PI * radius * radius;
    }
};

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        std::cout << "Area: " << std::fixed << std::setprecision(4)
            << shape->getArea() << std::endl;
    }
}

int main() {
    std::ifstream inputFile("shapes.txt");
    if (!inputFile) {
        std::cerr << "cant open shapes file" << std::endl;
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;

    while (std::getline(inputFile, line)) {
        std::istringstream lineStream(line);
        std::string shapeType;
        lineStream >> shapeType;

        if (shapeType == "rectangle") {
            double width, height;
            lineStream >> width >> height;
            shapes.push_back(std::make_unique<Rectangle>(width, height));
        }
        else if (shapeType == "circle") {
            double radius;
            lineStream >> radius;
            shapes.push_back(std::make_unique<Circle>(radius));
        }
    }

    printAllAreas(shapes);
    return 0;
}