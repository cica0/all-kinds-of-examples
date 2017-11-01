#if !defined(EA_BD766D47_0C69_4131_B7B9_21DF78B1E80D__INCLUDED_)
#define EA_BD766D47_0C69_4131_B7B9_21DF78B1E80D__INCLUDED_

//#include "Target.h"
#include "Adaptee.h"

class Adapter : public Target
{

public:
    Adapter(Adaptee *adaptee);
    virtual ~Adapter();

    virtual void request();

private:
    Adaptee* m_pAdaptee;

};
#endif // !defined(EA_BD766D47_0C69_4131_B7B9_21DF78B1E80D__INCLUDED_)
