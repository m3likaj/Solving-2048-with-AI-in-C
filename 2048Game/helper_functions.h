//
// Created by user on 2/10/2025.
//

#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include "layer.h"

void random_weights(Neuron* neuron, int size);
double sigmoid (double z);
double relu (double z);
void activate_relu(double* outputs, int size);
double dot_product(int size, double* vec_a, double* vec_b);
double* add_vectors(int size,int n, ...);
double* subtract_vectors(int size,int n,...);
double* vec_sca_mul(int size, double * vector, double scalar);
double get_z(int size, double* inputs, double* weights, double bias);

//************************************************************
#endif //HELPER_FUNCTIONS_H
