#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Shape {
public:
    virtual void draw() = 0;
    virtual void erase() = 0;
    virtual ~Shape();
    class BadShapeCreation : public exception {
        string reason;
    public:
        BadShapeCreation(string type) {
            reason = "cannot create type " + type;
        }
        const char *what() const {
            return reason.c_str();
        }
    };
    static Shape* factory(string type) throw(BadShapeCreation);
};

class Circle : public Shape {
    Circle();
    friend class Shape;
public:
    void draw() {cout << "Circle::draw" << endl;}
    void erase() {cout << "Circle::erase" << endl;}
    ~Circle() {cout << "Circle::~Circle" << endl;}
};

class Square: public Shape {
    Square();
    friend class Shape;
public:
    void draw() {cout << "Square::draw" << endl;}
    void erase() {cout << "Square::erase" << endl;}
    ~Square() {cout << "Square::~Square" << endl;}
};

Shape* Shape::factory (string type) throw(BadShapeCreation) {
    if (type == "Circle") return new Circle;
    if (type == "Square") return new Square;
    throw BadShapeCreation(type);
}


#endif
