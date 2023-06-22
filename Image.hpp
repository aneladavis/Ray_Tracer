//
//  Image.h
//  ppmReaderWriter
//
//  Created by TCP
//
#ifndef Image_h
#define Image_h
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Color.hpp"
using namespace std;
class Image {
public:
    Image(int w, int h, int max);
    ~Image(void);
    void writeImage(const char* file_name);
    int getWidth();
    int getHeight();
    Color** getImage();
    void setColor(int, int, Color);
    void addColor(int, int, Color);
private:
    char m_magic_number[2];
    int m_width;
    int m_height;
    int m_max;
    Color** m_image;
};
#endif /* Image_h*/
