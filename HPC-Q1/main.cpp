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
    
    cout<<"alpha (Diffusivity Coefficient) = ";
    double alpha;
    cin>>alpha; //alpha=1
    
    //calculate minimum input time step for Forward Euler to converge with v = or < 0.5
    double dx=L/Nx;
    double Ntmin=2*alpha*T/(pow(dx,2));
    cout<<"MINIMUM TIME STEP: "<<Ntmin<<endl;
    //Nt input
    cout<<"Nt (Number of Time Step) = ";
    double Nt;
    cin>>Nt; //Nt=5000
    
    //check that Nt is > or = Ntmax to make sure Forward Euler converges
    if (Nt<Ntmin){
        cout<<"ERROR: Input Nt is smaller than minimum time step allowed. Program Terminated."<<endl;
        terminate();
    }
    
    // INITIAL CALCULATIONS
    double dt=T/Nt;
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
