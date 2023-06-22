//  A basic 2d point class with operator overloading.
//
//  Point.hpp
//  Ray Tracer
//
//  Created by Anela Davis and Michael Zemanek
//
#ifndef Point_hpp
#define Point_hpp
#include <stdio.h>
class Point {
private:
    float m_x, m_y, m_z;
public:
    Point() : m_x(0.0), m_y(0.0), m_z(0.0) {}
    Point(float x, float y, float z) : m_x(x), m_y(y), m_z(z) {}
    Point operator+(const Point& p);
    Point operator-(const Point& p);
    Point operator*(const Point& p);
    Point operator*(const float& i);
    Point operator/(const float& i);
    float length();
    Point norm();
    float dot(const Point& p1);
    Point cross(const Point& p1);
    
    float x();
    float y();
    float z();
};
#endif /* Point_hpp */
