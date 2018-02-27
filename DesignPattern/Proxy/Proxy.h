

class Proxy : public Subject
{

public:
    Proxy();
    virtual ~Proxy();

    void request();

private:
    void afterRequest();
    void preRequest();  
    RealSubject *m_pRealSubject;

};
