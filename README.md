# MinRT
# Project Objective: Create a Ray Tracer

For the project completion, several goals were defined, including:

- Rendering with multiple light sources  
- Multiple geometric shapes such as spheres, planes, cylinders, triangles  
- Shadow patterns  
- Applying textures on spheres and 3D objects  
- Applying bump textures  
- Applying reflective properties to objects  

## How It Works

The functioning of a ray tracer is quite fun;

Basically, we have an object in space, like a sphere at (0,0,0),  
and we need to know if the pixel on the screen we are checking is part of the sphere.  
So we take the pixel, convert it into a point in space, add a direction,  
and trace a ray in that direction. If it hits the sphere, that means we have to paint that pixel with the sphere’s color.

Simple, I know! If you want to understand the functioning in depth, there is the book we used as reference for this project, *The Ray Tracer Challenge*, which explains how to make a ray tracer.

## What You Will Work on in This Project

> - Matrix operations  
> - Point operations in space  
> - RGB color operations  

These are the basic modules to start working on. Then we will:

> - Use the previous modules to calculate intersections with objects in space (those annoying formulas you learned in math classes)  
> - Learn what a normal is and why it is important for lighting calculations on an object  
> - Then learn how reflection works on mirrors, which basically means using the previous two modules in a loop to calculate reflection points;  
> At the end, put it all together to obtain a beautiful image (or a segfault!)

## Now Let’s See Some Pictures

