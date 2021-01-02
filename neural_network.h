#pragma once

#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <fstream>
#include "activation.h"

extern activation ACTIVATION;
extern activation ACTIVATION_DER;

float train(
    const int sample_count,
    const int layer_count,
    const int* neuron_count,
    const float* dataset,
    const float* target,
    float** weight,
    float** bias,
    const float learning_rate,
    const float momentum,
    const int epochs,
    const int batch_size,
    const bool verbose
);

void get_output(
    const int sample_count,
    const int layer_count,
    const int* neuron_count,
    const float* dataset,
    const float* const* weight,
    const float* const* bias,
    float* estimate
);

float* batch_normalization_train(float* arr, int sample_count, int feature_dim, float* mean, float* variance);
float* batch_normalization_test(float* arr, int sample_count, int feature_dim, float* mean, float* variance);
float* init_array_random(int len);
float* init_array(int len, float set);

#endif
