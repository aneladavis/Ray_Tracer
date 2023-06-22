//
//  Plane.hpp
//
//  Created by Anela Davis and Michael Zemanek on 11/30/21.
//
#ifndef Plane_hpp
#define Plane_hpp
#include <stdio.h>
#include "Point.hpp"
#include "Color.hpp"
#include "Object.hpp"
#include "Sphere.hpp"
#include <vector>

class Plane: public Object{
    private:
        Point m_normal;
        Point m_point;
    
    public:
        Plane(Point norm, Point point);
        Color calculateColor(Point o, Point dir, int i, int j, float** depthBuffer, vector<Object*> objects);
        float max(float vector);
        float smaller(float x, float y);
};
#endif /* Plane_hpp */
