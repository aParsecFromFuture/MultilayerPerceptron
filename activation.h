#pragma once
#include <cmath>

typedef void (*activation)(const float*, float*, int);
static const float EULER = 2.71828f;

inline void RELU(const float *x, float *y, int len) {
    for(int i = 0; i < len; i++)
        y[i] = (x[i] > 0.0f) ? x[i] : 0.0f;
}

inline void RELU_DER(const float *x, float*y, int len) {
    for (int i = 0; i < len; i++)
        y[i] *= (x[i] > 0.0f) ? 1.0f : 0.0f;
}

inline void LEAKY_RELU(const float* x, float* y, int len) {
    for (int i = 0; i < len; i++)
        y[i] = (x[i] > 0.0f) ? x[i] : (0.01f * x[i]);
}

inline void LEAKY_RELU_DER(const float* x, float* y, int len) {
    for (int i = 0; i < len; i++)
        y[i] *= (x[i] > 0.0f) ? 1.0f : 0.01f;
}

inline void ELU(const float* x, float* y, int len) {
    for (int i = 0; i < len; i++)
        y[i] = (x[i] > 0.0f) ? x[i] : (pow(EULER, x[i]) - 1.0f);
}

inline void ELU_DER(const float* x, float* y, int len) {
    for (int i = 0; i < len; i++)
        y[i] *= (x[i] > 0.0f) ? 1.0f : pow(EULER, x[i]);
}

inline void TANH(const float* x, float* y, int len) {
    for (int i = 0; i < len; i++)
        y[i] = 2.0f / (1.0f + pow(EULER, -2.0f * x[i])) - 1.0f;
}

inline void TANH_DER(const float* x, float* y, int len) {
    float tanh;
    for (int i = 0; i < len; i++) {
        tanh = 2.0f / (1.0f + pow(EULER, -2.0f * x[i])) - 1.0f;
        y[i] *=  1.0f - tanh * tanh;
    }
}

inline void SIGMOID(const float* x, float* y, int len) {
    for (int i = 0; i < len; i++)
        y[i] = 1.0f / (1.0f + pow(EULER, -x[i]));
}

inline void SIGMOID_DER(const float* x, float* y, int len) {
    float sigmoid;
    for (int i = 0; i < len; i++) {
        sigmoid = 1.0f / (1.0f + pow(EULER, -x[i]));
        y[i] *= sigmoid * (1.0f - sigmoid);
    }
}

inline void BIPOLAR_SIGMOID(const float* x, float* y, int len) {
    for (int i = 0; i < len; i++)
        y[i] = (1.0f - pow(EULER, -x[i])) / (1.0f + pow(EULER, -x[i]));
}

inline void BIPOLAR_SIGMOID_DER(const float* x, float* y, int len) {
    float bsigmoid;
    for (int i = 0; i < len; i++) {
        bsigmoid = (1.0f - pow(EULER, -x[i])) / (1.0f + pow(EULER, -x[i]));
        y[i] *= (1.0f + bsigmoid) * (1.0f - bsigmoid) * 0.5f;
    }
}

inline void SINUS(const float* x, float* y, int len) {
    for (int i = 0; i < len; i++)
        y[i] = sin(x[i]);
}

inline void SINUS_DER(const float* x, float* y, int len) {
    for (int i = 0; i < len; i++)
        y[i] *= cos(x[i]);
}

inline void NONE(const float* x, float* y, int len) {
    for (int i = 0; i < len; i++)
        y[i] = x[i];
}

inline void NONE_DER(const float* x, float* y, int len) {

}
