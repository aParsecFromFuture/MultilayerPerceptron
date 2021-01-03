#include "pch.h"
#include "neural_network.h"

activation ACTIVATION = &RELU;
activation ACTIVATION_DER = &RELU_DER;

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
) {
    int* shuffle;
    float sum, total_error, error;
    int epoch, step, swap;
    int i, j, k, l;

    float** input = new float* [layer_count];
    float** output = new float* [layer_count];
    float** error_term = new float* [layer_count];

    for (i = 0; i < layer_count; i++) {
        input[i] = new float[neuron_count[i] * batch_size];
        output[i] = new float[neuron_count[i] * batch_size];
        error_term[i] = new float[neuron_count[i] * batch_size];
    }

    float** velocity = new float* [layer_count - 1];

    for (i = 0; i < layer_count - 1; i++) {
        velocity[i] = new float[neuron_count[i + 1] * neuron_count[i]];
        for (j = 0; j < neuron_count[i + 1] * neuron_count[i]; j++)
            velocity[i][j] = 0.0f;
    }

    shuffle = new int[sample_count];
    for (i = 0; i < sample_count; i++)
        shuffle[i] = i;

    total_error = 0.0f; 

    std::ofstream record;

    if (verbose) {
        record.open("record.csv");
        record << "epoch,error\n";
    }

    for (epoch = 0; epoch < epochs; epoch++) {
        total_error = 0.0f;

        // SHUFFLE STAGE
        
        for (i = 0; i < sample_count; i++) {
            j = rand() % sample_count;
            swap = shuffle[i];
            shuffle[i] = shuffle[j];
            shuffle[j] = swap;
        }

        for (step = 0; step < (sample_count / batch_size); step++) {
            
            // FEEDFORWARD STAGE

            for(i = 0; i < neuron_count[0]; i++)
                for(j = 0; j < batch_size; j++)
                    output[0][i * batch_size + j] = dataset[shuffle[step * batch_size + j] * neuron_count[0] + i];

            // Calculation of the hidden layer inputs

            for (i = 0; i < layer_count - 2; i++) {
                for (j = 0; j < neuron_count[i + 1]; j++) {
                    for (k = 0; k < batch_size; k++) {
                        input[i + 1][j * batch_size + k] = 0.0f;
                        for (l = 0; l < neuron_count[i]; l++)
                            input[i + 1][j * batch_size + k] += weight[i][j * neuron_count[i] + l] * output[i][l * batch_size + k];
                        input[i + 1][j * batch_size + k] += bias[i][j];
                    }
                }

                // Calculation of the hidden layer outputs

                ACTIVATION(input[i + 1], output[i + 1], neuron_count[i + 1] * batch_size);
            }

            // Calculation of the output layer input

            for (i = 0; i < neuron_count[layer_count - 1]; i++) {
                for (j = 0; j < batch_size; j++) {
                    input[layer_count - 1][i * batch_size + j] = 0.0f;
                    for (k = 0; k < neuron_count[layer_count - 2]; k++)
                        input[layer_count - 1][i * batch_size + j] += weight[layer_count - 2][i * neuron_count[layer_count - 2] + k] * output[layer_count - 2][k * batch_size + j];
                    input[layer_count - 1][i * batch_size + j] += bias[layer_count - 2][i];
                }
            }

            // Calculation of the output layer output (SOFTMAX)

            for (i = 0; i < batch_size; i++) {
                sum = 0.0f;
                for (j = 0; j < neuron_count[layer_count - 1]; j++)
                    sum += pow(EULER, input[layer_count - 1][j * batch_size + i]);

                sum = 1.0f / sum;

                for (j = 0; j < neuron_count[layer_count - 1]; j++)
                    output[layer_count - 1][j * batch_size + i] = pow(EULER, input[layer_count - 1][j * batch_size + i]) * sum;
            }

            // BACKPROPAGATION STAGE
            // Reference https://en.wikipedia.org/wiki/Backpropagation

            // Calculation of error (Cross entropy loss function)
            // Reference https://stats.stackexchange.com/questions/235528/backpropagation-with-softmax-cross-entropy

            error = 0.0f;
            for (i = 0; i < neuron_count[layer_count - 1]; i++)
                for(j = 0; j < batch_size; j++)
                    error -= target[shuffle[step * batch_size + j] * neuron_count[layer_count - 1] + i] * log(output[layer_count - 1][i * batch_size + j]);

            total_error += error;

            // Calculation of the output layer error term

            for (i = 0; i < neuron_count[layer_count - 1]; i++)
                for(j = 0; j < batch_size; j++)
                    error_term[layer_count - 1][i * batch_size + j] = output[layer_count - 1][i * batch_size + j] - target[shuffle[step * batch_size + j] * neuron_count[layer_count - 1] + i];

            // Calculation of the hidden layer error terms

            for (i = layer_count - 2; i >= 1; i--) {
                for (j = 0; j < neuron_count[i]; j++) {
                    for (k = 0; k < batch_size; k++) {
                        error_term[i][j * batch_size + k] = 0.0f;

                        for (l = 0; l < neuron_count[i + 1]; l++)
                            error_term[i][j * batch_size + k] += weight[i][l * neuron_count[i] + j] * error_term[i + 1][l * batch_size + k];
                    }
                }
                ACTIVATION_DER(input[i], error_term[i], neuron_count[i] * batch_size);
            }

            // Calculation of the new output layer weight

            for (i = 0; i < neuron_count[layer_count - 1]; i++) {
                for (j = 0; j < neuron_count[layer_count - 2]; j++) {
                    sum = 0.0f;
                    for (k = 0; k < batch_size; k++)
                        sum += error_term[layer_count - 1][i * batch_size + k] * output[layer_count - 2][j * batch_size + k];
                    velocity[layer_count - 2][i * neuron_count[layer_count - 2] + j] = momentum * velocity[layer_count - 2][i * neuron_count[layer_count - 2] + j] + (1.0f - momentum) * (sum / batch_size);
                    weight[layer_count - 2][i * neuron_count[layer_count - 2] + j] -= learning_rate * velocity[layer_count - 2][i * neuron_count[layer_count - 2] + j];
                }

                sum = 0.0f;
                for(j = 0; j < batch_size; j++)
                    sum += error_term[layer_count - 1][i * batch_size + j];
                bias[layer_count - 2][i] -= learning_rate * (sum / batch_size);
            }

            // Calculation of the new hidden layer weights

            for (i = layer_count - 3; i >= 0; i--) {
                for (j = 0; j < neuron_count[i + 1]; j++) {
                    for (k = 0; k < neuron_count[i]; k++) {
                        sum = 0.0f;
                        for (l = 0; l < batch_size; l++)
                            sum += error_term[i + 1][j * batch_size + l] * output[i][k * batch_size + l];
                        velocity[i][j * neuron_count[i] + k] = momentum * velocity[i][j * neuron_count[i] + k] + (1.0f - momentum) * (sum / batch_size);
                        weight[i][j * neuron_count[i] + k] -= learning_rate * velocity[i][j * neuron_count[i] + k];
                    }
                    sum = 0.0f;
                    for(k = 0; k < batch_size; k++)
                        sum += error_term[i + 1][j * batch_size + k];
                    bias[i][j] -= learning_rate * (sum / batch_size);
                }
            }
        }

        if(verbose)
            record << epoch << "," << total_error << "\n";
    }

    if(verbose)
        record.close();
    
    for (i = 0; i < layer_count; i++) {
        delete[] input[i];
        delete[] output[i];
        delete[] error_term[i];
    }

    for (i = 0; i < layer_count - 1; i++)
        delete[] velocity[i];

    delete[] shuffle;
    delete[] input;
    delete[] output;
    delete[] error_term;
    delete[] velocity;
    return total_error;
}

void get_output(
    const int sample_count,
    const int layer_count,
    const int* neuron_count,
    const float* dataset,
    const float* const* weight,
    const float* const* bias,
    float* estimate
) {
    float** output;
    float* sample_output;
    float sum;
    int step;
    int i, j, k;

    output = new float* [layer_count];

    for (i = 0; i < layer_count; i++)
        output[i] = new float[neuron_count[i]];

    for (step = 0; step < sample_count; step++) {
        for (i = 0; i < neuron_count[0]; i++)
            output[0][i] = dataset[step * neuron_count[0] + i];
        sample_output = &estimate[step * neuron_count[layer_count - 1]];

        // Calculation of the hidden layer inputs

        for (i = 0; i < layer_count - 2; i++) {
            for (j = 0; j < neuron_count[i + 1]; j++) {
                output[i + 1][j] = 0.0f;
                for (k = 0; k < neuron_count[i]; k++)
                    output[i + 1][j] += weight[i][j * neuron_count[i] + k] * output[i][k];
                output[i + 1][j] += bias[i][j];
            }

            // Calculation of the hidden layer outputs

            ACTIVATION(output[i + 1], output[i + 1], neuron_count[i + 1]);
        }

        // Calculation of the output layer input

        for (i = 0; i < neuron_count[layer_count - 1]; i++) {
            output[layer_count - 1][i] = 0.0f;
            for (j = 0; j < neuron_count[layer_count - 2]; j++)
                output[layer_count - 1][i] += weight[layer_count - 2][i * neuron_count[layer_count - 2] + j] * output[layer_count - 2][j];
            output[layer_count - 1][i] += bias[layer_count - 2][i];
        }

        // Calculation of the output layer output (SOFTMAX)

        for (i = 0; i < neuron_count[layer_count - 1]; i++) {
            sum = 0.0f;
            for (j = 0; j < neuron_count[layer_count - 1]; j++)
                sum += pow(EULER, output[layer_count - 1][j]);
            sample_output[i] = pow(EULER, output[layer_count - 1][i]) / sum;
        }
    }

    for (i = 0; i < layer_count; i++)
        delete[] output[i];

    delete[] output;
}

float* batch_normalization_train(float* data, int sample_count, int feature_dim, float* mean, float* variance) {
    float* normalized_data = new float[sample_count * feature_dim];
    int i, j;

    for (i = 0; i < feature_dim; i++)
        mean[i] = variance[i] = 0.0f;

    for (i = 0; i < sample_count; i++)
        for (j = 0; j < feature_dim; j++)
            mean[j] += data[i * feature_dim + j];

    for (i = 0; i < feature_dim; i++)
        mean[i] /= sample_count;

    for (i = 0; i < sample_count; i++)
        for (j = 0; j < feature_dim; j++)
            variance[j] += (data[i * feature_dim + j] - mean[j]) * (data[i * feature_dim + j] - mean[j]);

    for (i = 0; i < feature_dim; i++)
        variance[i] /= sample_count;
    
    for (i = 0; i < sample_count; i++)
        for (j = 0; j < feature_dim; j++)
            normalized_data[i * feature_dim + j] = (data[i * feature_dim + j] - mean[j]) / sqrt(variance[j]);

    return normalized_data;
}

float* batch_normalization_test(float* data, int sample_count, int feature_dim, float* mean, float* variance) {
    float* normalized_data = new float[sample_count * feature_dim];
    int i, j;

    for (i = 0; i < sample_count; i++)
        for (j = 0; j < feature_dim; j++)
            normalized_data[i * feature_dim + j] = (data[i * feature_dim + j] - mean[j]) / sqrt(variance[j]);

    return normalized_data;
}

float* init_array_random(int len) {
    float* arr = new float[len];
    for (int i = 0; i < len; i++)
        arr[i] = ((float)rand() / RAND_MAX) - 0.5f;
    return arr;
}

float* init_array(int len, float val) {
    float* arr = new float[len];
    for (int i = 0; i < len; i++)
        arr[i] = val;
    return arr;
}

