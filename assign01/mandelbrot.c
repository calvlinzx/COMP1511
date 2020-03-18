// Assignment 1 Mandelbrot: Mandelbrot generation functions
// mandelbrot.c
//
// Completed by
// Zexin Lin (z5217017)
//
// Modified on 2018-08-26
// Elizabeth Willer (Tuesday 6pm-8pm-lab)
//
// Version 1.0.2: Fix minor typos in comments.
// Version 1.0.1: Fix issues with spacing and indentation.
// Version 1.0.0: Assignment released.

#include <stdio.h>
#include <math.h>
// Add your own #includes here

#include "mandelbrot.h"
#include "pixelColor.h"

// Add your own #defines here

// Add your own function prototypes here


// Take a pixel grid and and the path from the web browser used to
// request the 'tile'.
//
// The requestPath will be in the form "/mandelbrot/2/{zoom}/{x}/{y}.bmp".
// In the query, 'x' and 'y' are decimals and describe the 'center' of the
// tile and need to be converted into a complex number.
// 'zoom' is an integer representing the zoom level for the tile.
void serveMandelbrot(
    struct pixel pixels[TILE_SIZE][TILE_SIZE],
    char *requestPath
) {
    struct complex center = {0.0, 0.0};
    int z = 7;

    sscanf(
        requestPath,
        "/mandelbrot/2/%d/%lf/%lf.bmp",
        &z, &center.re, &center.im
    );

    // Use drawMandelbrot to draw the image.
    drawMandelbrot(pixels, center, z);
}

// Draw a single Mandelbrot tile, by calculating and colouring each of
// the pixels in the tile.
//
// Your function "returns" this tile by filling in the `pixels` 2D array
// that is passed in to your function.
//
// The `pixels` array is TILE_SIZE high and TILE_SIZE wide.
// The bottom left corner of the image is pixels[0][0].
//
// `center` is a complex number, representing the center of the tile.
// `z` is used to calculate the distance between each pixel in the image.
// Each pixel is 2^(-z) apart from each other.
void drawMandelbrot(
    struct pixel pixels[TILE_SIZE][TILE_SIZE],
    struct complex center,
    int z
) {
    // TODO: COMPLETE THIS FUNCTION
    struct complex r;
    
    int i = 0;
    while (i < TILE_SIZE) {
    
        // Convert pixel y-coordinats to complex number y-coordinates
        r.im = (i - TILE_SIZE / 2) * pow(2, -z) + center.im;
        
        int j = 0;
        while (j < TILE_SIZE) {
        
            // Convert pixel x-coordinats to complex number x-coordinates
            r.re = (j - TILE_SIZE / 2) * pow(2, -z) + center.re;
            // Call pixelColor function to give color 
            pixels[i][j] = pixelColor(escapeSteps(r));
            j++;
        }
        i++;
    }   
         
}

// Determine the number of steps required to escape the Mandelbrot set,
// for the given complex number `c`.
int escapeSteps(struct complex c) {
    int steps = 0;

    // TODO: COMPLETE THIS FUNCTION
    struct complex w;
    struct complex wSquare;
    w.re = 0;
    w.im = 0;
    wSquare.re = 0;
    wSquare.im = 0;
    
    // Modulus of a complex number a+b*I is square root(a^2+b*2)
    // Loop ends if steps is 256 or modulus of w is greater than 2
    while (steps < MAX_STEPS && (w.re * w.re + w.im * w.im) < 4) {
        
        // (a+b*I)*(a+b*I) = (a^2-b^2)+2ab*I
        // Square the real and imagianry of w seperately
        wSquare.re = w.re * w.re - w.im * w.im;
        wSquare.im = 2 * w.re * w.im;
        
        // Add the testing complex number c to w seperately
        w.re = wSquare.re + c.re;
        w.im = wSquare.im + c.im;
        steps++;        
    }
    
    // Return NO_ESCAPE if steps is equal to 265
    if (steps == MAX_STEPS) {
        steps = NO_ESCAPE;
    }
   
    return steps;
}


// Add your own functions here.
// Remember to make them static.

