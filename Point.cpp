//
//  Point.cpp
//  A class for a 2d point (x,y)
//  Ray Tracer
//
//  Created by Peck, Tabitha on 8/15/16, modified by Anela Davis and Michael Zemanek.
//  Copyright � 2016 Davidson College. All rights reserved.
//

#include "Point.hpp"
#include <math.h>

/* Add two points together
​
 (a, b) + (c, d) = (a + c, b + d)
​
 */
Point Point::operator+(const Point& p)
{
    return Point(this->m_x + p.m_x, this->m_y + p.m_y, this->m_z + p.m_z);
}
Point Point::operator-(const Point& p)
{
    return Point(this->m_x - p.m_x, this->m_y - p.m_y, this->m_z - p.m_z);
}

Point Point::operator*(const float& i)
{
    return Point(this->m_x * i, this->m_y * i, this->m_z * i);
}
Point Point::operator/(const float& i)
{
    return Point(this->m_x / i, this->m_y / i, this->m_z / i);
}

Point Point::operator*(const Point& p)
{
    return Point(this->m_x * p.m_x, this->m_y * p.m_y, this->m_z * p.m_z);
}
float Point::length(){
    return sqrt(((m_x * m_x)+(m_y*m_y)+(m_z*m_z)));
}
Point Point::norm(){
    float normDenominator = length();
    return Point((this-> m_x)/normDenominator,(this -> m_y)/normDenominator, (this-> m_z)/normDenominator);
}
float Point::dot(const Point& p)
{
    return float((this->m_x * p.m_x) + (this->m_y * p.m_y) + (this->m_z * p.m_z));
}
Point Point::cross(const Point& p1){
        float x = this->m_y * p1.m_z - this->m_z * p1.m_y;
        float y = this->m_z * p1.m_x - this->m_x * p1.m_z;
        float z = this->m_x * p1.m_y - this->m_y * p1.m_x;
    return Point(x,y,z);
}
float Point::x() {
    return m_x;
}

float Point::y() {
    return m_y;
}
float Point::z() {
    return m_z;
}
