//  Program for plane object.
//  Plane.cpp
//
//  Created by Anela Davis and Michael Zemanek on 11/30/21.
//
#include "Plane.hpp"
#include <cmath>
#include "Point.hpp"
#include "Color.hpp"
#include <vector>

// Initialize a plane
Plane:: Plane(Point norm, Point point){
    m_normal = norm.norm();
    m_point = point;
}

// calculate color of plane
Color Plane:: calculateColor(Point o, Point dir, int i, int j, float** depthBuffer, vector<Object*> objects)
{
    // set light source
    Point lightSource = Point(500.0,400.0,0.0);
    
    // check that denominator is not 0
    if (dir.dot(m_normal) != 0)
    {
        // calculate t value
        float t = ((m_point - o).dot(m_normal))/ (dir.dot(m_normal));
        // check if t is closer to previous t
        if (depthBuffer[i][j] > t){
            depthBuffer[i][j] = t;
            
            // calculate vertex on Plane
            Point vertexP = (o + (dir * t));
            
            // calculate vector from vertex on plane to light source
            Point vertexToLight = lightSource - vertexP;
            vertexToLight = vertexToLight.norm();

            // iterate through each object
            for (int v = 0; v < objects.size() - 1; v ++)
            {
                Object* objectCur = objects[v];
                int rad = objectCur->getRadius();
                Point cent = objectCur->getCenter();
                
                Point o_min_c = vertexP - cent;

                // check if vector intersects an object
                if (((vertexToLight.dot(o_min_c) * vertexToLight.dot(o_min_c)) - (vertexToLight.dot(vertexToLight)
                * ((o_min_c.dot(o_min_c) - (rad * rad))))) > 0)
                {
                    // calculate t value from vertex to light
                    float underRoot = ((vertexToLight.dot(o_min_c) * vertexToLight.dot(o_min_c)) - (vertexToLight.dot(vertexToLight)
                                        * ((o_min_c.dot(o_min_c) - (rad * rad)))));
        
                    
                    // determine the two possible t values
                    float plusT = ((-vertexToLight.dot(o_min_c) + sqrt(underRoot))/ vertexToLight.dot(dir));
                    float minusT = ((-vertexToLight.dot(o_min_c) - sqrt(underRoot))/ vertexToLight.dot(dir));
                    
                    // selects the smaller of the t value that is positive
                    float t = smaller(plusT,minusT);
                    // check that the vector intersects an object in the scene (not behind)
                    if (t < 0)
                    {
                        // color pixel in shadow
                        return Color(0.0, 0.0, 0.0);
                    }
                }
            }
                
            Point vertexCam = o - vertexP;
            vertexCam = vertexCam.norm();
            
            // calculate the lightDirection and normalize it
            Point lightDirection = Point(lightSource - vertexP);
            lightDirection = lightDirection.norm();
            
            // calculate the bisector and normalize it
            Point bisector = Point(lightDirection + vertexCam);
            bisector = bisector.norm();
            
            // clamp the diffuseTerm and specTerm between 0 and 1
            float diffuseTerm = max(lightDirection.dot(m_normal));
            float specTerm = max(pow(bisector.dot(m_normal),m_shininess));
            
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
float Plane:: max(float value){
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
float Plane:: smaller(float x, float y){
    float small = y;
    if(x < y){
        small = x;
    }
    return small;
}
