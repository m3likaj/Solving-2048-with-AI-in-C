//
//  Neural_Network.c
//  2048 Game
//
//  Created by MELIKA on 1/17/25.
//
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include "Neural_Network.h"
#include "Matrix_Operations.h"

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
    for(int i = 0; i<size; i++){
        result += vec_a[i] * vec_b[i];
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

double predict(int size, double* inputs, double* weights, double bias){
    double result = dot_product(size, inputs, weights);
    return result+bias;
}
//************************************************************

Layer* intialize_input_layer(double* normalized_board, int num_of_neurons){
    Layer* input_layer = (Layer*)malloc(sizeof(Layer));
    Neuron* neurons = (Neuron*) calloc(num_of_neurons, sizeof(Neuron));
    
    
    for (int i =0; i< num_of_neurons; i++) {
        neurons[i].num_of_inputs = 1;
        neurons[i].inputs = &(normalized_board[i]);
        neurons[i].output = *(neurons[i].inputs);
        neurons[i].weights = NULL;
        input_layer->outputs[i] = neurons[i].output;
    }
    input_layer->neurons = neurons;
    input_layer->number_of_neurons = num_of_neurons;
    return input_layer;
}
//************************************************************

Layer* initialize_hidden_layer(Layer* prev_layer, int num_of_neurons){
    Layer* hidden_layer = (Layer*)malloc(sizeof(Layer));
    Neuron* neurons = (Neuron*) calloc(num_of_neurons, sizeof(Neuron));
    int num_of_inputs = prev_layer->number_of_neurons;
    double bias;
    for (int i =0; i< num_of_neurons; i++) {
        bias = (rand()%100+1)/100.0;
        neurons[i].num_of_inputs = num_of_inputs;
        neurons[i].inputs = prev_layer->outputs;
        neurons[i].weights = (double*) calloc(num_of_inputs, sizeof(double));
        random_weights(&(neurons[i]), num_of_inputs);
        neurons[i].output = predict(num_of_inputs, neurons[i].inputs, neurons[i].weights, bias);
        hidden_layer->outputs[i] = neurons[i].output;
    }
    hidden_layer->neurons = neurons;
    hidden_layer->number_of_neurons = num_of_neurons;
    hidden_layer->activate = activate_relu;
    hidden_layer->activate(hidden_layer->outputs, num_of_neurons);
    return hidden_layer;
}
//************************************************************

Layer* initialize_output_layer(Layer* prev_layer, int num_of_neurons){
    Layer* output_layer = (Layer*)malloc(sizeof(Layer));
    Neuron* neurons = (Neuron*) calloc(num_of_neurons, sizeof(Neuron));
    int num_of_inputs = prev_layer->number_of_neurons;
    double bias;
    for (int i =0; i< num_of_neurons; i++) {
        bias = (rand()%100+1)/100.0;
        neurons[i].num_of_inputs = num_of_inputs;
        neurons[i].inputs = prev_layer->outputs;
        neurons[i].weights = (double*) calloc(num_of_inputs, sizeof(double));
        random_weights(&(neurons[i]), num_of_inputs);
        neurons[i].output = predict(num_of_inputs, neurons[i].inputs, neurons[i].weights, bias);
        output_layer->outputs[i] = neurons[i].output;
    }
    output_layer->neurons = neurons;
    output_layer->number_of_neurons = num_of_neurons;
    return output_layer;
}
//************************************************************

//************************************************************
//************************************************************
//************************************************************
//************************************************************
//************************************************************
//************************************************************
//************************************************************
//************************************************************
