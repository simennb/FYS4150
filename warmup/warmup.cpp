#include <stdlib.h>   /* atof function    */
#include <iostream>   /* input and output */
#include <iomanip>    /* for manipulating output */
#include <fstream>    /* to operate on files */
#include <cmath>      /* math functions   */
using namespace std;

ofstream ofile; /* output file as global variable */

/* In hindsight, distinguishing between single/double should be improved */
/* we overloading functions to make sure float/double used correctly */

float f(float x){
  /*!
   * Returns the function value evaluated at point x
   * Single precision
   */
  return atan(x);
}

double f(double x){
  /*!
   * Returns the function value evaluated at point x
   * Double precision
   */
  return atan(x);
}

/* Functions for calculating f' with two point equation */

float two_point(float x, float h){
  /*!
   * Computes the first derivative based on the two-point formula
   * Single precision
   */
  float dfdx;
  dfdx = (f(x+h) - f(x))/h;

  return dfdx;
}

double two_point(double x, double h){
  /*!
   * Computes the first derivative based on the two-point formula
   * Double precision
   */
  double dfdx;
  dfdx = (f(x+h) - f(x))/h;

  return dfdx;
}

/* Three point formula for findind f' with 3 point */

float three_point(float x, float h){
  /*!
   * Computes the first derivative based on the three-point formula
   * Single precision
   */
  float dfdx;
  dfdx = (f(x+h)-f(x-h))/(2*h);

  return dfdx;
}

double three_point(double x, double h){
  /*!
   * Computes the first derivative based on the three-point formula
   * Double precision
   */
  double dfdx;
  dfdx = (f(x+h)-f(x-h))/(2*h);

  return dfdx;
}

int main (int argc, char *argv[]){
  /* Naming output file that we will write results into */
  char *outfilename;
  if (argc < 2){
    cout<<"Usage: "<<argv[0]<<" name of output file"<<endl;
    exit(1);
  }
  else{
    outfilename = argv[1];
  }
  ofile.open(outfilename); /* open output file */

  /* Defining values */
  float x_float = sqrt(2);
  double x_double = sqrt(2);

  float h_float;
  double h_double;
  int h_power = -20; /*< Starting value for power of h */

  int i = 42; /*< Number of h values to test */

  /* Creating arrays for f_values for two/three-point formulas */
  /* Single precision */
  float *two_float;
  two_float = new float[i];
  
  float *three_float;
  three_float = new float[i];

  /* Double precision */
  double *two_double;
  two_double = new double[i];
  
  double *three_double;
  three_double = new double[i];

  /* first line in output file */
  ofile << "h two_float two_double three_float three_double"<<endl;
  for (int j = 0; j < i; j++){
    h_float = pow(10,0.5*h_power); /* making sure h is on form 10^i */
    h_double = pow(10,0.5*h_power); /* making sure h is on form 10^i */

    two_float[j] = two_point(x_float,h_float);
    two_double[j] = two_point(x_double,h_double);
    
    three_float[j] = three_point(x_float,h_float);
    three_double[j] = three_point(x_double,h_double);

    //ofile <<"h = 10^"<<setw(3)<< h_power;
    //ofile <<", 2p = "<<setw(12)<<setprecision(10)<<two_float[j];
    //ofile <<", 3p = "<<setw(12)<<setprecision(10)<<three_float[j]<<endl;
    ofile<<setprecision(3)<<h_float<<" ";
    ofile<<setprecision(16)<<two_float[j]<<" ";
    ofile<<setprecision(16)<<two_double[j]<<" ";
    ofile<<setprecision(16)<<three_float[j]<<" ";
    ofile<<setprecision(16)<<three_double[j]<<endl;
    
    h_power += 1;
  }  

  /* freeing memory */
  delete [] two_float;
  delete [] two_double;
  delete [] three_float;
  delete [] three_double;
  
  ofile.close();  /* close output file */
  return 0;

}
