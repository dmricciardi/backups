#include <math.h>
#include <stdio.h>

// define a new variable type
typedef struct {
  float x;
  float y;
  float z;
} point;


point pointCreate(float x, float y, float z){

  point p;
  p.x = x;
  p.y = y;
  p.z = z;

  return p;
}

float pointDistanceFromOrigin(point p){

  float d = sqrt(p.x*p.x + p.y*p.y +  p.z*p.z);

  return d;

}

void pointZero(point p){

  // opt 1:
  (*pt_p).x = 0;
  (*pt_p).y = 0;
  (*pt_p).z = 0;

  //
  pt_p->x = 0;
  pt_p->y = 0;
  pt_p->z = 0;
}

void pointPrint(point p){
  printf("point: %f, %f 
}

int main(){

  point p = pointCreate(1.2, 2.3, 3.1);
  float d = pointDistanceFromOrigin(p);

  printf("d = %d\n");

  pointZero(p);

  pointPrint(p);

}

