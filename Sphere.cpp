//  Program for sphere objects.
//  sphere.cpp
//  Ray Tracer
//
//  Created by Anela Davis and Michael Zemanek
//
#include "Sphere.hpp"
#include "Point.hpp"
#include "Color.hpp"
#include <cmath>
#include <vector>

// initialize a center and radius for a new sphere
Sphere:: Sphere(Point center, float radius){
    m_cent = center;
    m_rad = radius;
}
// gets the radius for the sphere
float Sphere::getRadius(){
    return m_rad;
}
// gets the center for the sphere
Point Sphere::getCenter(){
    return m_cent;
}
// sets the radius for a given sphere
void Sphere::setRadius(float radius){
    m_rad = radius;
}
// sets the center of the sphere
void Sphere::setCenter(float centx, float centy, float centz){
    m_cent = Point(centx,centy,centz);
}
// determines the color and lighting for a given sphere
Color Sphere:: calculateColor(Point o, Point dir, int i, int j, float** depthBuffer, vector<Object*> objects){
    Point o_min_c = o - m_cent;
    
    // calculate determinant. If true, color sphere, if false, do not color
    if (((dir.dot(o_min_c) * dir.dot(o_min_c)) - (dir.dot(dir)
    * ((o_min_c.dot(o_min_c) - (m_rad*m_rad))))) >= 0)
    {
        // center of the light source
        Point lightSource = Point(500.0,400.0,0.0);
        
        // calculate the value of the determinant
        float underRoot = (((dir.dot(o_min_c)) * (dir.dot(o_min_c))) - (dir.dot(dir) * (o_min_c.dot(o_min_c) - (m_rad * m_rad))));
        
        // determine the two possible t values
        float plusT = ((-dir.dot(o_min_c) + sqrt(underRoot))/ dir.dot(dir));
        float minusT = ((-dir.dot(o_min_c) - sqrt(underRoot))/ dir.dot(dir));
        
        // selects the smaller of the t value that is positive
        float t = smaller(plusT,minusT);
        
        // evaluate values in depth buffer
        if (depthBuffer[i][j] > t && t > 0.0){
            depthBuffer[i][j] = t;
        
        // calculate vertex of sphere
        Point vertexP = (o + (dir * t));
            
        Point vertexCam = o - vertexP;
        vertexCam = vertexCam.norm();
        
        
        // calculates the normal
        Point normal = Point((vertexP - m_cent)/m_rad);
        normal = normal.norm();
        
        // calculate the lightDirection and normalize it
        Point lightDirection = Point(lightSource - vertexP);
        lightDirection = lightDirection.norm();
        
        // calculate the bisector and normalize it
        Point bisector = Point(lightDirection + vertexCam);
        bisector = bisector.norm();
        
        // clamp the diffuseTerm and specTerm between 0 and 1
        float diffuseTerm = max(lightDirection.dot(normal));
        float specTerm = max(pow(bisector.dot(normal),m_shininess));
        
        // determine the lightColor based on the equation
        Color lightColor = m_ambient + (m_diffuseColor * diffuseTerm) + (m_specular * specTerm);
        
        // clamp the lightColor from 0 to 1
        lightColor.clamp();
        return lightColor;
        }
    // do not color pixel
    return Color(-1.0,0.0,0.0);
                
    }
    // do not color pixel
    return Color(-1.0,0.0,0.0);
    
}
// clamps a value between 0 and 1
float Sphere:: max(float value){
    int maximum = 1.0;
    int minimum = 0.0;
    // if value is between 0 and 1
    if (value > minimum && value < maximum){
        return value;
    }
    // if value is greater than 1
    else if (value > maximum){
        value = maximum;
        return value;
    }
    else{
        // if value is less than 0
        value = minimum;
        return value;
    }
}

// determine the smaller of two float integers
float Sphere:: smaller(float x, float y){
    float small = y;
    if(x < y){
        small = x;
    }
    return small;
}

