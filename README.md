# DeepLearning
Fully connected artificial neural network simulation project.

I highly recommend you to take a look at the [flowchart](github%20resource/app_flowchart.png) before use the program.

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
* Supported preprocessing operations
  * Data shuffling
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

There are 2 training mod, classical training and animated training. The animated training cuts the epochs into 10 equal pieces and keeps the visual output of every piece. When the training is done, it will show the 10 outputs one after the other with 0.25 seconds interval.

![alt text](github%20resource/app_animation.gif)

### Verbose

It saves training information in a csv file named as "record.csv". The file has two columns named as "epoch" and "error". The csv file can be examined via external sources like pandas, plotly etc.

![alt text](github%20resource/app_verbose.gif)

## Report

### Data shuffling

When i implemented the data shuffling at first, the algorithm was like below. One day i realised that calling the training function 10 times with n epochs was not same as calling the training function 1 time with 10n epochs. There was a huge performance gap between them and the problem was in the shuffling phase. In fact the shuffling algorithm does not affect the original data and if you try to slice training phase into multi function calls, the shuffling algorithm start all over again for every call. The performance gap means that the algorithm is not shuffling enough and there are some unshuffled data remain.

#### Old algorithm
```
for i in sample count
 pick random sample A
 pick random sample B
 swap A and B
end
```

Then i upgraded the algorithm:

#### New algorithm

```
for i in sample count
 pick ith sample A
 pick random sample B
 swap A and B
end
```

Let's consider a sample from the dataset. What is the probability that the data remain unshuffled after the shuffling phase?

For the old algorithm:

![alt text](github%20resource/app_random_shuffle.svg)

For the new algorithm:

![alt text](github%20resource/app_iterative_shuffle.svg)


As you see the new algorithm is far better.

![alt text](github%20resource/app_graph_shuffle.png)

### Momentum optimization

The momentum is a method for optimize the training phase. It has one parameter called "beta". I found that the best value for the beta parameter is 0.99 for my neural network. You can see my tests below. Every line represents mean of 10 tests.

![alt text](github%20resource/app_graph_momentum.png)

### Activation functions

I added sinus function just for curiosity. I wasn't expecting even the neural network trained some way. Ironically it did one of the best scores. The error values are the sum of the errors per epoch.

##### For 2 hidden layers [64, 32]

![alt text](github%20resource/app_graph_activation.png)

![alt text](github%20resource/app_graph_activation_time.png)

##### For 3 hidden layers [128, 64, 32]

![alt text](github%20resource/app_graph_activation2.png)

![alt text](github%20resource/app_graph_activation_time2.png)

