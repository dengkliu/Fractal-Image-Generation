//
//  main.cpp
//  generate a fractal PNG imag
//
//  Created by Dengke Liu on 12/10/2014.

#include "complex.h"
#include "lodepng.h"
#include "rgb.h"
#include <cstdlib>
#include <iostream>


int julia(int pixel_x, int pixel_y, int iteration_limits, complex c,int width, int height);

int main(int argc, const char *argv[])
{
    // the input of command line
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    std::string output_png = argv[3];

    // the definition for the defualt values of the complex number constant
    double real=0.75;
    double imag=1;
    complex c = complex(real,imag);

    //for users to determine the numbers of maximum iteration
    int Max_itr;
    std::cout << "Please set the maximum interation value (probably between 150 and 200)" << std::endl;
    std::cin >> Max_itr;

    // dynamic allocation for an 1D array
    const int size=width*height*4;
    unsigned char *image = new unsigned char[size];

    for (int x=0; x<width; x++){
            for (int y=0; y<height; y++){

                //call the julia function
                int m = julia(x,y,Max_itr,c, width, height);

                // assigning color to each of the pixel
                rgb color=rgb(m%256,m%256,m%256);

                image[4*(y*width+y)+0]=color.r;
                image[4*(y*width+y)+1]=color.g;
                image[4*(y*width+y)+2]=color.b;
                image[4*(y*width+y)+3]=255;
                }
    }

    // the output of the image by calling the function from the Lodepng
    lodepng::encode(output_png, image, width, height);
    delete [] image;
}

// the julia function
int julia(int pixel_x, int pixel_y, int iteration_limits, complex c,int width, int height)
{
    //the transformation of the coordinates of pixels into complex constants
    double real=1.5*(pixel_x-width/2)/(0.5*width);
    double imag=(pixel_y-height/2)/(0.5*height);
    complex z = complex(real,imag);

    // counting the number of iterations
    int n=0;
    for (;n < iteration_limits; n++){
    double magnitude = z.magnitude2();
    if(magnitude>2.0) break;
    // the esacpe time algorithm
    else z=z*z+c;}

    return n;
}
