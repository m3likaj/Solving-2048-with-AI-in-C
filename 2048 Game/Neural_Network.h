//
//  Neural_Network.h
//  2048 Game
//
//  Created by MELIKA on 1/17/25.
//

#ifndef Neural_Network_h
#define Neural_Network_h


typedef struct neuron{
    double * inputs;
    double * weights;
    double   output;
       int   num_of_inputs;
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


double dot_product(int size, double* vec_a, double* vec_b);
void random_parameters(Neuron* N, int size);



#endif /* Neural_Network_h */
