#include "purge.h"
#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <map>

using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual void erase() = 0;
    virtual ~Shape(){}
};

class ShapeFactory {
    virtual Shape* create() = 0;
    static map<string, ShapeFactory*> factories;
public:
    virtual ~ShapeFactory() {}
    friend class ShapeFactoryInizializer;
    class BadShapeCreation : public exception {
        string reason;
    public:
        BadShapeCreation(string type) {
            reason = "cannot create type " + type;
        }
        const char *what() const throw() {
            return reason.c_str();
        }
    };
    static Shape *createShape(string type) throw(BadShapeCreation) {
        if (factories.find(type) != factories.end()) {
            return factories[type]->create();
        }
        else
            throw BadShapeCreation(type);
    }
};

map<string, ShapeFactory*> ShapeFactory::factories;


class Circle : public Shape {
    Circle() {}
public:
    void draw() {cout << "Circle::draw" << endl;}
    void erase() {cout << "Circle::erase" << endl;}
    ~Circle() {cout << "Circle::~Circle" << endl;}
    class Factory;
    friend class Factory;
    class Factory : public ShapeFactory {
    public:
        Shape* create() { return new Circle; }
    };
};

class Square : public Shape {
    Square() {}
public:
    void draw() {cout << "Square::draw" << endl;}
    void erase() {cout << "Square::erase" << endl;}
    ~Square() {cout << "Square::~Square" << endl;}
    class Factory;
    friend class Factory;
    class Factory : public ShapeFactory {
    public:
        Shape* create() { return new Square; }
    };
};

class ShapeFactoryInizializer {
    static ShapeFactoryInizializer si;
    ShapeFactoryInizializer () {
        ShapeFactory::factories["Circle"] = new Circle::Factory;
        ShapeFactory::factories["Square"] = new Square::Factory;
    }
};

ShapeFactoryInizializer ShapeFactoryInizializer::si;

//这个结尾需要加一个空的字符串，否则在遍历的时候会断
const char *shlist[] = {"Circle", "Square", ""};

int main()
{
    vector<Shape*> shapes;
    try {
        for (const char **cp = shlist; **cp; ++cp)
            shapes.push_back(ShapeFactory::createShape(*cp));
    } catch (ShapeFactory::BadShapeCreation e) {
        cout << e.what() << endl;
        return -1;
    }
    for (int i = 0; i<shapes.size(); ++i) {
        shapes[i]->draw();
        shapes[i]->erase();
    }
    purge(shapes);
    return 0;
}
