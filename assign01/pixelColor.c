// Assignment 1 Mandelbrot: Pixel coloring functions
// pixelColor.c
//
// Completed by
// Zexin Lin (z5217017)
//
// Modified on 2018-09-01
// Elizabeth Willer (Tuesday 6pm-8pm-lab)
//
// Version 1.0.1: Fix issues with spacing and indentation.
// Version 1.0.0: Assignment released.
#include <math.h>
#include "mandelbrot.h"
#include "pixelColor.h"

// This function should take a number (of steps taken to escape the
// Mandelbrot set), and convert it to a color.
//
// You have artistic licence here, so make your Mandelbrot look amazing.
struct pixel pixelColor(int steps) {
    struct pixel color = {
        .red = steps,
        .green = steps,
        .blue = steps,
    };

    // TODO: Change the color of the pixel for different numbers of
    // steps.

    // Convert the steps which is less than 256 to different colors
    if (steps != NO_ESCAPE) {
        color.red = (int)fabs(sin(steps)) % 256;
        color.green = (int)(steps * 5) % 256;
        color.blue = (int)(steps * 3) % 256;
    }
    
    // Convert the step which is 256 to black
    else {
        color.red = 0;
        color.green = 0;
        color.blue = 0; 
    }
    return color;
}
