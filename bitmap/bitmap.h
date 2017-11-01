#ifndef BITMAP_H
#define BITMAP_H

#include "stdint.h"

class MyBitmap {
public:
    MyBitmap();
    MyBitmap(int64_t data);
    MyBitmap(const MyBitmap &others);
    MyBitmap& operator=(const MyBitmap &others);
    ~MyBitmap();
    int setbitmap(int64_t data);
    int issetbitmap(int64_t data);
    int unsetbitmap(int64_t data);

private:
    uint8_t *m_bitmap;
    int64_t m_bitsize;
};

#endif
