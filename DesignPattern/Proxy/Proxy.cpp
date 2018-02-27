#include <iostream>
#include "Proxy.h"

using namespace std;

Proxy::Proxy() {
    m_pRealSubject = new RealSubject();
}

Proxy::~Proxy() {
    delete m_pRealSubject;
}

void Proxy::afterRequest() {
    cout << "Proxy::afterRequest" << endl;
}

void Proxy::preRequest() {
    cout << "Proxy::preRequest" << endl;
}

void Proxy::request() {
    preRequest();
    m_pRealSubject->request();
    afterRequest();
}
