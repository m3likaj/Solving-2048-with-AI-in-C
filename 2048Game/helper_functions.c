//
// Created by user on 2/10/2025.
//

#include "helper_functions.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include "layer.h"
#include "matrix_operations.h"

//************************************************************

void random_weights(Neuron* neuron, int size){
    for (int i = 0; i<size; i++) {
        neuron->weights[i] =(rand()%100+1)/100.0;
    }
}
//************************************************************

double sigmoid (double z){
    double g = 1.0/(1+ exp(-z));
    return g;
}
//************************************************************

double relu (double z){
    return (z>0)? z : 0;
}
//************************************************************

void activate_relu(double* outputs, int size){
    for (int i = 0; i< size; i++) {
        outputs[i] = relu(outputs[i]);
    }
}
//************************************************************

double dot_product(int size, double* vec_a, double* vec_b){
    double result = 0;
    if(size==1){
      result = (*vec_a) * (*vec_b);
    }
    else{
        for(int i = 0; i<size; i++){
            result += vec_a[i] * vec_b[i];
        }
    }
    return result;
}
//************************************************************

double* add_vectors(int size,int n, ...) {
    double* result = (double*) calloc(size, sizeof(double)) ;
    va_list list;
    for (int i = 0; i < size; i++){
        va_start(list, n);
        for(int j = 0; j<n; j++){
            result[i] += va_arg(list, double*)[i];
        }
}
    va_end(list);

    return result;
}
//************************************************************

double* subtract_vectors(int size,int n,...) {
    double* result = (double*) calloc(size, sizeof(double)) ;
    va_list list;
    for (int i = 0; i < size; i++){
        va_start(list, n);
        result[i] = va_arg(list, double*)[i];
        for(int j = 0; j<n-1; j++){
            result[i] -= va_arg(list, double*)[i];

        }
}
    va_end(list);

    return result;
}
//************************************************************

double* vec_sca_mul(int size, double * vector, double scalar){//vector scalar multiplication
    double* result = (double*) calloc(size, sizeof(double));
    for (int i = 0; i<size; i++) {
        result[i] = scalar * vector[i];
    }
    return result;
}