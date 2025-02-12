//
// Created by user on 2/10/2025.
//

#ifndef LAYER_H
#define LAYER_H

typedef struct neuron{
    double * inputs;
    double * weights;
    double   output;
    double   bias;
    int      num_of_inputs;
} Neuron;
//************************************************************

typedef struct layer {
    int   number_of_neurons;
    Neuron * neurons;
    double * outputs;
    void(*activate)(double*, int);
    double(*error)(double*, double*);
}Layer;
//************************************************************



Layer* initialize_input_layer(double* normalized_board, int num_of_neurons);
Layer* initialize_hidden_layers(Layer* input_layer, int* num_of_neurons, int num_of_hidden_layers);
Layer* initialize_output_layer(Layer* prev_layer, int num_of_neurons);



#endif //LAYER_H
