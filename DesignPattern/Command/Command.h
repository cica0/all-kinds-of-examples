#if !defined(DA_1AE70D53_4868_4e81_A1B8_1088DA355C23__INCLUDED_)
#define DA_1AE70D53_4868_4e81_A1B8_1088DA355C23__INCLUDED_
#include "iostream"
#include "Receiver.h"

class Command
{

public:
    Command(Receiver *pReceiver);
    Command();
    virtual ~Command() ;
    virtual void execute();
private:
//    Receiver *m_pReceiver;



};
#endif // !defined(DA_1AE70D53_4868_4e81_A1B8_1088DA355C23__INCLUDED_)
