#include <stdlib.h>   /* atof function    */
#include <iostream>   /* input and output */
#include <iomanip>    /* for manipulating output */
#include <fstream>    /* to operate on files */
#include <cmath>      /* math functions   */
using namespace std;

ofstream ofile; /* output file as global variable */

double f(double x){
  /*!
   * Returns the function value evaluated at point x
   */
  return atan(x);
}

double two_point(double x, double h){
  /*!
   * Computes the first derivative based on the two-point formula
   */
  double dfdx;
  dfdx = (f(x+h) - f(x))/h;

  return dfdx;
}

double three_point(double x, double h){
  /*!
   * Computes the first derivative based on the three-point formula
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
  double x = sqrt(2);
  double h;
  int h_power = -20; /*< Starting value for power of h */

  int i = 21; /*< Number of h values to test */

  /* Creating arrays for f_values for two/three-point formulas */
  double *two_array;
  two_array = new double[i];
  
  double *three_array;
  three_array = new double[i];

  for (int j = 0; j < i; j++){
    h = pow(10,h_power); /* making sure h is on form 10^i */

    two_array[j] = two_point(x,h);
    three_array[j] = three_point(x,h);
    ofile <<"h = 10^"<<setw(3)<< h_power;
    ofile <<", 2p = "<<setw(12)<<setprecision(10)<<two_array[j];
    ofile <<", 3p = "<<setw(12)<<setprecision(10)<<three_array[j]<<endl;
    
    h_power += 1;
  }  

  /* freeing memory */
  delete [] two_array;
  delete [] three_array;
  
  ofile.close();  /* close output file */
  return 0;

}
