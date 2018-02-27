#include <iostream>
using namespace std;

class phone {
public:
    phone(){}
    virtual ~phone(){}
    virtual void ShowDecorate(){} 
};

class iphone : public phone {
private:
    string m_name;
public:
    iphone(string name):m_name(name){}
    ~iphone(){}
    virtual void ShowDecorate() {cout << m_name << "的装饰"<<endl; }
};

class NokiaPhone: public phone {
private:
    string m_name;
public:
    NokiaPhone(string name):m_name(name){}
    ~NokiaPhone(){}
    virtual void ShowDecorate() {cout << m_name << "的装饰"<<endl; }
};

class DecoratorPhone : public phone {
private :
    phone *m_phone;
public:
    DecoratorPhone(phone *p):m_phone(p) {}
    virtual void ShowDecorate() { m_phone->ShowDecorate(); }
};

class DecoratorPhoneA : public DecoratorPhone {
public:
    DecoratorPhoneA(phone *p):DecoratorPhone(p) {}
    virtual void ShowDecorate() { DecoratorPhone::ShowDecorate(); AddDecorator(); }
    void AddDecorator() { cout << "增加挂件" << endl; }
};

class DecoratorPhoneB : public DecoratorPhone {
public:
    DecoratorPhoneB(phone *p):DecoratorPhone(p) {}
    virtual void ShowDecorate() { DecoratorPhone::ShowDecorate(); AddDecorator(); }
    void AddDecorator() { cout << "屏幕贴膜" << endl; }
};

int main()
{
    phone *new_phone = new NokiaPhone("111");
    phone *new_phone_addA = new DecoratorPhoneA(new_phone);
    phone *new_phone_addB = new DecoratorPhoneB(new_phone_addA);
    new_phone_addB->ShowDecorate();
    return 0;
}
