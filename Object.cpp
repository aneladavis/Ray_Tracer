//  Object.cpp
//  RayTracer
//
//  Created by Peck, Tabitha on 10/29/16, modified by Anela Davis and Michael Zemanek. 
//  Copyright © 2016 Davidson College. All rights reserved.
//
#include "Object.hpp"
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "Point.hpp"

// create an object with random diffuse color and shininess.
Object::Object(){
    m_diffuseColor = Color((float)rand()/(float)RAND_MAX, (float)rand()/(float)RAND_MAX, (float)rand()/(float)RAND_MAX);
    float threshold = 128.0;
    m_shininess = threshold*((float)rand()/(float)RAND_MAX);
    m_ambient = Color(0.1, 0.1, 0.1);
    m_specular = Color(1.0, 1.0, 1.0);
    
}
// destroy an object
Object::~Object(){

}

// calculates color of pixel
Color Object:: calculateColor(Point, Point,int, int, float**, vector<Object*>)
{
    return Color(1.0,1.0,1.0);
};
