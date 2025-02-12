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

double get_z(int size, double* inputs, double* weights, double bias){
    double result = dot_product(size, inputs, weights);
    return result+bias;
}
//************************************************************

Layer* initialize_input_layer(double* normalized_board, int num_of_neurons){
    Layer* input_layer = (Layer*)malloc(sizeof(Layer));
    Neuron* neurons = (Neuron*) calloc(num_of_neurons, sizeof(Neuron));

    for (int i =0; i< num_of_neurons; i++) {
        neurons[i].num_of_inputs = 1;
        neurons[i].inputs = &(normalized_board[i]);
        neurons[i].output = *(neurons[i].inputs);
        neurons[i].weights = NULL;
        neurons[i].bias = 0;
        input_layer->outputs[i] = neurons[i].output;
    }
    input_layer->neurons = neurons;
    input_layer->number_of_neurons = num_of_neurons;
    return input_layer;
}
//************************************************************

Layer* initialize_hidden_layers(Layer* input_layer, int* num_of_neurons, int num_of_hidden_layers){
    Layer* hidden_layers = (Layer*)malloc(sizeof(Layer) * num_of_hidden_layers);
    int num_of_inputs;
    Layer* prev_layer;
    Neuron* neurons;
    for (int i = 0; i<num_of_hidden_layers; i++) {
        neurons = (Neuron*) calloc(num_of_neurons[i], sizeof(Neuron));
        prev_layer = (i==0) ? input_layer : hidden_layers+i-1;
        num_of_inputs = prev_layer->number_of_neurons;
        for (int j =0; j< num_of_neurons[i]; j++) {
            neurons[j].bias = (rand()%100+1)/100.0;
            neurons[j].num_of_inputs = num_of_inputs;
            neurons[j].inputs = prev_layer->outputs;
            neurons[j].weights = (double*) calloc(num_of_inputs, sizeof(double));
            random_weights(&(neurons[j]), num_of_inputs);
            neurons[j].output = get_z(num_of_inputs, neurons[j].inputs, neurons[j].weights, neurons[j].bias);
            hidden_layers[i].outputs[j] = neurons[j].output;
        }
        hidden_layers[i].neurons = neurons;
        hidden_layers[i].number_of_neurons = num_of_neurons[i];
        hidden_layers[i].activate = activate_relu;
        hidden_layers[i].activate(hidden_layers[i].outputs, num_of_neurons[i]);
    }

    return hidden_layers;
}
//************************************************************

Layer* initialize_output_layer(Layer* prev_layer, int num_of_neurons){
    Layer* output_layer = (Layer*)malloc(sizeof(Layer));
    Neuron* neurons = (Neuron*) calloc(num_of_neurons, sizeof(Neuron));
    int num_of_inputs = prev_layer->number_of_neurons;
    double bias;
    for (int i =0; i< num_of_neurons; i++) {
        neurons[i].bias = (rand()%100+1)/100.0;
        neurons[i].num_of_inputs = num_of_inputs;
        neurons[i].inputs = prev_layer->outputs;
        neurons[i].weights = (double*) calloc(num_of_inputs, sizeof(double));
        random_weights(&(neurons[i]), num_of_inputs);
        neurons[i].output = get_z(num_of_inputs, neurons[i].inputs, neurons[i].weights, neurons[i].bias);
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
