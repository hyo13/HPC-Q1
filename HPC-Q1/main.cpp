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

int main() {
    
    // INPUTS
    cout<<"L (Length of Bar) = ";
    double L;
    cin>>L; //L=1
    
    cout<<"Nx (Number of X Increments) = ";
    double Nx;
    cin>>Nx; //Nx=20
    
    cout<<"T (Total Run Time) = ";
    double T;
    cin>>T; //T=5
    
    cout<<"Nt (Number of Time Step) = ";
    double Nt;
    cin>>Nt; //Nt=5000
    
    cout<<"alpha (Diffusivity Coefficient) = ";
    double alpha;
    cin>>alpha; //alpha=1
    
    // INITIAL CALCULATIONS
    double dt=T/Nt;
    double dx=L/Nx;
    double v=alpha*dt/pow(dx,2);
    
    // X-POSIION VECTOR
    vector <double> x(Nx+1);
    for (int i=0;i<Nx+1;i++){
        x[i]=0+i*dx;
    }
    
    //INITIAL CONDITION
    vector <double> u0(x.size());
    u0[1]=0;
    u0[x.size()]=0;
    for (int i=1;i<x.size()-1;i++){
        u0[i]=x[i]*(1-x[i]);
    }
    
    //FORWARD EULER TIME INTEGRATION
    vector <double> u0new(x.size());
    TriMatrix M(v,x.size());
    for (int i=0;i<Nt;i++){
        u0new=M*u0;
        u0=u0new;
    }
    
    //OUTPUT RESULTS
    for (int i=0;i<x.size();i++){
        cout<<u0new[i]<<endl;
    }
    
    return 0;
}
