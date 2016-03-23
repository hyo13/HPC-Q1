//
//  TriMatrix.h
//  HPC-Q1
//
//  Created by hyo13 on 22/3/16.
//  Copyright (c) 2016 hyo13. All rights reserved.
//

#ifndef CLASS_TriMatrix
#define CLASS_TriMatrix

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class TriMatrix{
    
private:
    vector <double> *diagm, *diagu, *diagl;
    
public:
    TriMatrix(double v,double size){
        diagm = new vector <double> (size);
        diagu = new vector <double> (size-1);
        diagl = new vector <double> (size-1);
        
        //create diagm vector
        (*diagm)[0]=1;
        (*diagm)[size-1]=1;
        for (int i=1;i<size-1;i++){
            (*diagm)[i]=1-2*v;
        }
        
        //create diagu vector
        (*diagu)[0]=0;
        for (int i=1;i<size-1;i++){
            (*diagu)[i]=v;
        }
        
        //create diagl vector
        (*diagl)[size-2]=0;
        for (int i=0;i<size-2;i++){
            (*diagl)[i]=v;
        }
        
    }
    
    vector<double> operator* (vector<double> X){
        int size=X.size();
        
        //diagm multiply X
        vector<double> Am(size);
        for (int i=0;i<size;i++){
            Am[i]=(*diagm)[i]*X[i];
        }
        
        //diagu multiply X
        vector<double> Au(size);
        Au[0]=0;
        for (int i=1;i<size;i++){
            Au[i]=(*diagu)[i-1]*X[i];
        }
        
        //diagl multiply X
        vector<double> Al(size);
        for (int i=0;i<size-1;i++){
            Al[i]=(*diagl)[i]*X[i];
        }
        Al[size-1]=0;

        //Superposition of results
        vector<double> B(size);
        for (int i=0;i<size;i++){
            B[i]=Am[i]+Au[i]+Al[i];
        }
        return B;
    }
};


#endif /* defined(__HPC_Q1__TriMatrix__) */
