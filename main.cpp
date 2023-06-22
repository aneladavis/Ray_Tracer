// Program sets up and displays scene of objects.

// main.cpp
// RayTracer
//
// Created by Anela Davis and Michael Zemanek and TCP
//
#include <iostream>
#include <cmath>
#include "Image.hpp"
#include "Point.hpp"
#include "Sphere.hpp"
#include <algorithm>
#include <stdio.h>
#include <vector>
#include "Plane.hpp"
vector<Object*> objects;


int main(int argc, const char* argv[]) {
    
    // Creates an Image that is 1025 X 1025 pixels
    int pixx = 1025;
    int pixy = 1025;
    Image image = Image(pixx, pixy, 255);
    
    // camera location
    Point camLocation = Point(512.5,512.5,500);
    
    // origin of ray
    Point o = camLocation;
    
    // create depth buffer
    float** depthBuffer = new float * [pixx];
    for (int m = 0; m < pixy; m++) {
        depthBuffer[m] = new float [pixy];
        for (int n = 0; n < pixy; n++) {
            depthBuffer[m][n] = 10000000000000;
        }
    }
    
    // objects of the scene
    Point cent1 = Point(450,760,-80);
    float rad1 = 40.0;
    Object* s1 = new Sphere(cent1, rad1);
    s1->setRadius(rad1);
    s1->setCenter(cent1);
    objects.push_back(s1);
    
    Point cent2 = Point(500,740,-150);
    float rad2 = 60.0;
    Object* s2 = new Sphere(cent2, rad2);
    s2->setRadius(rad2);
    s2->setCenter(cent2);
    objects.push_back(s2);
    
    Point cent3 = Point(630,720,-150);
    float rad3 = 80.0;
    Object* s3 = new Sphere(cent3, rad3);
    s3->setRadius(rad3);
    s3->setCenter(cent3);
    objects.push_back(s3);
    
    Object* p1 = new Plane(Point(0.0,-1.0,0.0), Point(1000.0,800.0,1000.0));
    p1->setRadius(0.0);
    p1->setCenter(Point(0.0,0.0,0.0));
    objects.push_back(p1);
    
    // go through each pixel and set color
    for (int i = 0; i < pixx; i ++){
        for (int j = 0; j < pixy; j ++){
            Point v_dir = Point(i,j,0) - o;
            v_dir = v_dir.norm();
            
            // create plane on the bottom half of the screen
            if (j > 512.5)
           {
                Color groundPlane = p1->calculateColor(o, v_dir, i, j, depthBuffer, objects);
               // check if the plane should be colored or not
                if (groundPlane.get_r() != -1.0){
                    image.setColor(i, j, groundPlane);
                }
            }
            // color first sphere
            Color lightColor1 = s1->calculateColor(o,v_dir, i, j, depthBuffer, objects);
            // check if the sphere should be colored or not
            if (lightColor1.get_r() != -1.0){
                image.setColor(i, j, lightColor1);
            }

            // color second sphere
            Color lightColor2 = s2->calculateColor(o,v_dir, i, j, depthBuffer, objects);
            // check if the sphere should be colored or not
            if (lightColor2.get_r() != -1.0){
                image.setColor(i, j, lightColor2);
            }

            // color third sphere
            Color lightColor3 = s3->calculateColor(o,v_dir, i, j, depthBuffer, objects);
            // check if the sphere should be colored or not
            if (lightColor3.get_r() != -1.0){
                image.setColor(i, j, lightColor3);
            }
        }
    }

        
    
    //create the image to this address
    image.writeImage("/Users/aneladavis/desktop/raytracer.ppm");
    return 0;
}
