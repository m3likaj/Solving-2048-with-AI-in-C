//
//  neural_network.h
//  2048 Game
//
//  Created by MELIKA on 1/17/25.
//

#ifndef neural_network_h
#define neural_network_h
#include "layer.h"

typedef struct neural_network{
    Layer* input_layer;
    Layer* hidden_layers;
    Layer* output_layer;
    int number_of_hidden_layers;
    void (*predict)(void);
}Neural_Network;

//************************************************************



#endif /* neural_network_h */
