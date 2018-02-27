#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

class Gladiolus;//剑兰
class Renuculus;
class Chrysanthemum;

class Visitor {
public:
    virtual void visit(Gladiolus* f) = 0;
    virtual void visit(Renuculus* f) = 0;
    virtual void visit(Chrysanthemum* f) = 0;
    virtual ~Visitor(){}
};

class Flower {
public:
    virtual void accept(Visitor &) = 0;
    virtual ~Flower(){}
};

class Gladiolus : public Flower {
public:
    virtual void accept(Visitor &v) {
        v.visit(this);
    }
};

class Renuculus : public Flower {
public:
    virtual void accept(Visitor &v) {
        v.visit(this);
    }
};

class Chrysanthemum : public Flower {
public:
    virtual void accept(Visitor &v) {
        v.visit(this);
    }
};

class StringVal : public Visitor {
    string s;
public:
    operator const string&() {return s;}
    virtual void visit(Gladiolus* f) {
        s = "Gladiolus" ;
    }
    virtual void visit(Renuculus* f) {
        s = "Renuculus";
    }
    virtual void visit(Chrysanthemum* f) {
        s = "Chrysanthemum";
    }
};

class Bee : public Visitor {
public:
    virtual void visit(Gladiolus* f) {
        cout << "Bee and Gladiolus" ;
    }
    virtual void visit(Renuculus* f) {
        cout << "Bee and Renuculus" ;
    }
    virtual void visit(Chrysanthemum* f) {
        cout << "Bee and Chrysanthemum" ;
    }
};

struct FlowerGen {
    FlowerGen() {srand(time(0));}
    Flower *operator()() {
        switch(rand()%3) {
            default:
            case 0:return new Gladiolus;
            case 1:return new Renuculus;
            case 2:return new Chrysanthemum;
        }
    }
};

int main()
{
    vector<Flower*> v(10);
    generate(v.begin(), v.end(), FlowerGen());
    vector<Flower*>::iterator it;
    StringVal sval;
    for(it = v.begin(); it!=v.end(); ++it) {
        (*it)->accept(sval);
        cout << string(sval) << endl;
    }
    Bee bee;
    for(it = v.begin(); it!=v.end(); ++it) {
        (*it)->accept(bee);
        cout << endl;
    }
    return 0;
}
