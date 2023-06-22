//
//  Color.h
//  RayTracer
//
//  Created by TCP
//

#ifndef Color_h
#define Color_h

#include <stdio.h>

class Color {
private:
    float m_color[3];
    
public:
    Color();
    Color(float, float, float);
    ~Color();
    
    Color operator+(const Color& c);
    Color operator-(const Color& c);
    Color operator*(const Color& c);
    Color operator/(const Color& c);
    Color operator*(float f);
    Color operator/(float f);
    float get_r();
    float get_g();
    float get_b();
    void clamp();
};
#endif /* Color_h */
