//  neural_network.c
//  2048 Game
//
//  Created by MELIKA on 1/17/25.
//

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include "matrix_operations.h"
#include "neural_network.h"
#include "layer.h"
#include "game_logic.h"
#include "helper_functions.h"



Neural_Network* initialize_neural_network( int num_of_hidden_layers, int* num_hidden_neurons, double* normalized_board){
  int num_input_neurons = 16;
  if(num_of_hidden_layers <= 0)return NULL;
  int num_output_neurons = 4;
  Neural_Network* neural_network = (Neural_Network*)malloc(sizeof(Neural_Network));
  neural_network->number_of_hidden_layers = num_of_hidden_layers;
  neural_network->input_layer = initialize_input_layer(normalized_board, num_input_neurons);
  neural_network->hidden_layers = initialize_hidden_layers(neural_network->input_layer, num_hidden_neurons, num_of_hidden_layers);
  Layer* last_hidden_layer = (neural_network->hidden_layers) + num_of_hidden_layers-1; //the last layer in the hidden layer list
  neural_network->output_layer = initialize_output_layer(last_hidden_layer, num_output_neurons);

  return neural_network;
}
//************************************************************

void forward_propagation_input(Neural_Network* network, double* normalized_board) {
  int num_of_neurons = network->input_layer->number_of_neurons;
  Neuron* neurons = network->input_layer->neurons;
  for (int i =0; i< num_of_neurons; i++) {
    neurons[i].num_of_inputs = 1;
    neurons[i].inputs = &(normalized_board[i]);
    neurons[i].output = *(neurons[i].inputs);
    neurons[i].weights = NULL;
    network->input_layer->outputs[i] = neurons[i].output;
  }
}
//************************************************************

void forward_propagation_hidden(Neural_Network* network) {
  int num_of_inputs;
  Layer* input_layer = network->input_layer;
  Layer* hidden_layers = network->hidden_layers;
  int num_of_hidden_layers = network->number_of_hidden_layers;
  Layer* prev_layer;
  Neuron* neurons;
  int num_of_neurons;

  for (int i = 0; i<num_of_hidden_layers; i++) {
    prev_layer = (i==0) ? input_layer : network->hidden_layers+i-1;
    num_of_inputs = prev_layer->number_of_neurons;
    neurons = hidden_layers[i].neurons;
    num_of_neurons = hidden_layers[i].number_of_neurons;
    for (int j =0; j< num_of_neurons; j++) {
      neurons[j].inputs = prev_layer->outputs;
      neurons[j].output = get_z(num_of_inputs, neurons[j].inputs, neurons[j].weights, neurons[j].bias);
      hidden_layers[i].outputs[j] = neurons[j].output;
    }
    hidden_layers[i].activate(hidden_layers[i].outputs, num_of_neurons);
  }
}
//************************************************************

void forward_propagation_output(Neural_Network* network) {
  Layer* output_layer = network->output_layer;
  Layer* last_hidden_layer = network->hidden_layers + network->number_of_hidden_layers -1;
  Neuron* neurons = network->output_layer->neurons;
  int num_of_inputs = last_hidden_layer->number_of_neurons;
  for (int i =0; i< output_layer->number_of_neurons; i++) {
    neurons[i].inputs = last_hidden_layer->outputs;
    neurons[i].output = get_z(num_of_inputs, neurons[i].inputs, neurons[i].weights, neurons[i].bias);
    output_layer->outputs[i] = neurons[i].output;
  }
}
//************************************************************

void forward_propagation(Neural_Network* network, double* normalized_board) {
  forward_propagation_input(network, normalized_board);
  forward_propagation_hidden(network);
  forward_propagation_output(network);
}
//************************************************************


//************************************************************
//************************************************************