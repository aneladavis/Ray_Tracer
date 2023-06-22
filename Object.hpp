//
//  Object.hpp
//  RayTracer
//
//  Created by Peck, Tabitha on 10/29/16, modified by Anela Davis and Michael Zemanek.
//  Copyright © 2016 Davidson College. All rights reserved.
//
#ifndef Object_hpp
#define Object_hpp
#include <stdio.h>
#include "Color.hpp"
#include "Point.hpp"
#include "Image.hpp"
#include <vector>

using namespace std;
class Object{
protected:
    Color m_diffuseColor;
    Color m_ambient;
    Color m_specular;
    float m_shininess;
    float n_rad;
    Point n_cent;
    
public:
    Object();
    ~Object();
    void setRadius(float rad){n_rad = rad;};
    void setCenter(Point cent){n_cent = cent;};
    float getRadius(){return n_rad;};
    Point getCenter(){return n_cent;};
    virtual Color calculateColor(Point, Point,int, int, float**, vector<Object*>);
    
};
#endif /* Object_hpp */
