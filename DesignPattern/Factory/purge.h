#ifndef PURGE_H
#define PURGE_H
#include <iostream>

template <class Seq>
void purge(Seq& c) {
    typename Seq::iterator i;
    for (i=c.begin(); i!=c.end(); ++i) {
        std::cout << "delete " << std::endl;
        delete *i ;
        *i = 0;
    }

}



#endif
