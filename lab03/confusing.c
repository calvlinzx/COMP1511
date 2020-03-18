//
// Test if a point is inside a triangle.
// Julian Saknussemm
// Modified by Zexin Lin (z5217017) / Phan Nguyen
// Given Three points of a triangle, and another arbitrary point this program determines if that point lies inside
// the triangle.
 
// This is determined by satisfying the following rule:
// A point P(x,y) is inside triangle A(x0,y0), B(x1,y1), C(x2,y2)
// iff
// P is on the same side of the line AB as C
// P is on the same side of the line BC as A
// and
// P is on the same side of the line AC as B
 
// A special case exits for a vertical line (inf gradient) when testing the side of the line
//
 
#include <stdio.h>
 
int comparePointAndLine(double pointX, double pointY, 
                        double lineGradient, double lineIntercept) {

    double lineY = lineGradient * pointX + lineIntercept;
    if( pointY < lineY) {
        return -1; // point is under line
    }
    else if ( pointY == lineY) {
        return 0;
    } 
    else {
        return 1; // over
    }
}
 
// two points lie on the same side of a line





int determinePointInsideEdge(double pointX, double pointY,
                             double edgeX1, double edgeY1,
                             double edgeX2, double edgeY2,
                             double oppX, double oppY ) {
    
    int pSide, oppSide;
    
    
    if (edgeX2 == edgeX1) {
        pSide = (pointX <= edgeX1);
        oppSide = (oppX <= edgeX1);
    }
    else {
    
        double gradient = (edgeY2 - edgeY1) / (edgeX2 - edgeX1);
        double intercept = gradient * -edgeX2 + edgeY2;
        
        pSide = comparePointAndLine(pointX, pointY,
                                    gradient, intercept);
        oppSide = comparePointAndLine(oppX, oppY,
                                      gradient, intercept);
    }
    
    return (pSide == oppSide);
}


// Determine whether point p is within triangle defined by a, b ,c.
int determinePointInsideTriangle(double ax, double ay,
                                 double bx, double by,
                                 double cx, double cy,
                                 double px, double py ) {
    
    // determine if point is inside for each edge
    int pointInsideAB = determinePointInsideEdge(
            px, py, ax, ay, bx, by, cx, cy);
    int pointInsideBC = determinePointInsideEdge(
            px, py, bx, by, ax, ay, cx, cy);
    int pointInsideAC = determinePointInsideEdge(
            px, py, ax, ay, cx, cy, bx, by);
            
    return pointInsideAB && pointInsideBC && pointInsideAC;
 }   
int main(int argc, char* argv[]) {
    double x0,y0;
    double x1,y1;
    double x2,y2;
    double px,py;
 
    int scanfsReturn = 0;
 
// get input
        printf("Triangle Vertex A (x,y): "); 
        scanfsReturn += scanf("%lf,%lf", &x0,&y0);
        printf("Triangle Vertex B (x,y): "); 
        scanfsReturn += scanf("%lf,%lf", &x1,&y1);
        printf("Triangle Vertex C (x,y): "); 
        scanfsReturn += scanf("%lf,%lf", &x2,&y2);
        printf("Test Point (x,y): ");
        scanfsReturn += scanf("%lf,%lf", &px,&py);
 
// print error
        if( scanfsReturn != 8 ) {
            printf("Please put in the right inputs.\n");
            return 1;
        }
       
// calculate whether the specified point is inside
        int pointWasInside = determinePointInsideTriangle(
            x0, y0, x1, y1, x2, y2, px, py);
 
// print answer
        printf("Point (%.2lf,%.2lf) is ", px,py);
        if (pointWasInside) {
            printf("inside");
        }
        else {
            printf("outside");
        }
        printf(" the Triangel\n");
 
// return 0
    return 0;
}



// Between any pair of braces, the indentation level should increase by 
// 4 spaces
// Renamed some variable names 
// Output like "You're stupid and didn't put in the right inputs!" is 
// making people feel uncomfortable
// Fixed the vertical line check(while two points of the triangle have
// the same x-axis coordinates )
// Introduced some new functions and replaced the old ones
//
