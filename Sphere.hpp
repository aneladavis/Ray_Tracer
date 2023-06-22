//
//  sphere.hpp
//  Ray Tracer
//
//  Created by Anela Davis and Michael Zemanek
//
#include "Point.hpp"
#include "Color.hpp"
#include "Object.hpp"
#ifndef sphere_hpp
#define sphere_hpp
#include <stdio.h>
#include <vector>

class Sphere: public Object
{
    private:
        float m_rad;
        Point m_cent;
    
    public:
        Sphere(Point center, float radius);
        float getRadius();
        Point getCenter();
        void setRadius(float radius);
        void setCenter(float centx, float centy, float centz);
        Color calculateColor(Point o, Point dir, int i, int j, float** depthBuffer, vector<Object*> objects);
        float max(float vector);
        float smaller(float x, float y);
};
#endif /* sphere_hpp */
