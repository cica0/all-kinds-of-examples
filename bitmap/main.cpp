#include <iostream>

#include "bitmap.h"

using std::endl;

int main()
{
    MyBitmap bitmap(64);
    bitmap.setbitmap(1);
    std::cout << "bitmap isset return:" << bitmap.issetbitmap(1) << endl;
    bitmap.unsetbitmap(1);
    std::cout << "bitmap isset return:" << bitmap.issetbitmap(1) << endl;
    return 0;
}
