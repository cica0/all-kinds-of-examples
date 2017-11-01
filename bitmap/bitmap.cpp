#include "bitmap.h"
#include <iostream>
#include <string.h>
#include <cstddef>

using std::cout;
using std::endl;

MyBitmap::MyBitmap() {
    m_bitmap = NULL;
    m_bitsize = 0;
}

MyBitmap::MyBitmap(int64_t data) {
    if(data > 0) {
        m_bitsize = data>>3 + 1;
        m_bitmap = new uint8_t(m_bitsize * sizeof(m_bitmap));
        if(NULL == m_bitmap)
            m_bitsize = 0;
    }
    else {
        m_bitmap = NULL;
        m_bitsize = 0;
    }
}

MyBitmap::MyBitmap(const MyBitmap &others) {
    m_bitsize = others.m_bitsize;
    if(m_bitmap != NULL) {
        m_bitmap = new uint8_t(m_bitsize * sizeof(m_bitmap));
        if(m_bitmap != NULL) 
            m_bitsize = 0;
        else 
            memcpy((void *)m_bitsize,(void *) others.m_bitsize, m_bitsize * sizeof(m_bitmap));
    }
    else {
        delete m_bitmap;
        m_bitmap = NULL;
        m_bitsize = 0;
    }
}

MyBitmap& MyBitmap::operator=(const MyBitmap &others) {
    m_bitsize = others.m_bitsize;
    if(m_bitmap != NULL) {
        m_bitmap = new uint8_t(m_bitsize * sizeof(m_bitmap));
        if(m_bitmap != NULL) 
            m_bitsize = 0;
        else 
            memcpy((void *)m_bitsize,(void *) others.m_bitsize, m_bitsize * sizeof(m_bitmap));
    }
    else {
        delete m_bitmap;
        m_bitmap = NULL;
        m_bitsize = 0;
    }
}

MyBitmap::~MyBitmap() {
    if(m_bitmap != NULL) {
        delete m_bitmap;
    }
    m_bitsize = 0;
}

int MyBitmap::setbitmap(int64_t data) {
    int index = data >> 3; 
    int offset = data & 7;
    int magic = 0x01 << (offset-1);
    m_bitmap[index] |= magic;
}

int MyBitmap::issetbitmap(int64_t data) {
    int index = data >> 3; 
    int offset = data & 7;
    int magic = 0x01 << (offset-1);
//    cout << "index is :" << index << endl;
//    cout << "offset is :" << offset << endl;
//    cout << "magic is :" << magic << endl;
    return m_bitmap[index] &= magic;
}

int MyBitmap::unsetbitmap(int64_t data) {
    int index = data >> 3; 
    int offset = data & 7;
    int magic = 0x01 << (offset-1);
    m_bitmap[index] &= ~(magic);
}
