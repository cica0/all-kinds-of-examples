#if !defined(EA_3DACB62A_0813_4d11_8A82_10BF1FB00D9A__INCLUDED_)
#define EA_3DACB62A_0813_4d11_8A82_10BF1FB00D9A__INCLUDED_

#include "Command.h"

class Invoker
{

public:
    Invoker(Command * pCommand);
    virtual ~Invoker();
    void call();

private:
    Command *m_pCommand;


};
#endif // !defined(EA_3DACB62A_0813_4d11_8A82_10BF1FB00D9A__INCLUDED_)
