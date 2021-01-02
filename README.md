# DeepLearning
Fully connected artificial neural network simulation project.

![alt text](github%20resource/app_main.png)

## Features

* Single/Multi layer support
* Supported methods
  * Stochastic gradient descent
  * Mini-batch gradient
  * Batch gradient descent
* Supported activation functions
  * Relu
  * Leaky relu
  * Elu
  * Tanh
  * Sigmoid
  * Bipolar sigmoid
  * Sinus (experimental)
  * None (without activation function)
* Supported optimizers
  * Momentum
* Supported normalization and standardization methods
  * Z-score normalization
* Supported output layer activation functions
  * Softmax function
* Supported loss functions
  * Cross-entropy

## Guide

### The weights

When you train the network again and again, it will continue where it left off. You can set the weights randomly and lost the information with clear weight button.

![alt text](github%20resource/app_weight.gif)

### Continuous color

You can find some visually useful stuffs in the view tab. The continuous color option is not an interpolation, it's the probability map that softmax function produce.

![alt text](github%20resource/app_color.gif)

### Animated training

There are 2 training mod, classic training and animated training. The animated mod cuts the epochs 10 equal pieces and keeps the visual output of every piece. When the training done, it will show the 10 outputs one after the other with 0.5 seconds interval.

![alt text](github%20resource/app_animation.gif)

Error (loss) is calculated as sum of the sample's errors.

![equation](http://www.sciweavers.org/tex2img.php?eq=error%3D%5Csum_%7Bi%7D%5E%7Bn%7D%20L%28x_%7Bi%7D%2C%20y_%7Bi%7D%29&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0)
