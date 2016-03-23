//
//  main.cpp
//  HPC-Q1
//
//  Created by hyo13 on 22/3/16.
//  Copyright (c) 2016 hyo13. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include "TriMatrix.h"
using namespace std;

//
vector <double> vec(double a, double b, double c){
    vector <double> x((c-a)/b+1);
    for (int i=0;i<(c-a)/b+1;i++){
        x[i]=a+i*b;
    }
    return x;
}

int main() {
    
    // INPUT
    double L=1;
    double Nx=20;
    double T=5;
    double Nt=5000;
    double alpha=1;
    
    // INITIAL CALCULATIONS
    double dt=T/Nt;
    double dx=L/Nx;
    double v=alpha*dt/pow(dx,2);
    
    // X-POSIION VECTOR
    vector <double> x=vec(0,L/Nx,L);
    
    //INITIAL CONDITION
    vector <double> u0(x.size());
    u0[1]=0;
    u0[x.size()]=0;
    for (int i=1;i<x.size()-1;i++){
        u0[i]=x[i]/(1-x[i]);
    }
    
    return 0;
}
