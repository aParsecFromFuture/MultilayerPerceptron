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

There are 2 training mod, classical training and animated training. The animated training cuts the epochs into 10 equal pieces and keeps the visual output of every piece. When the training done, it will show the 10 outputs one after the other with 0.5 seconds interval.

![alt text](github%20resource/app_animation.gif)

### Verbose

It saves training information in a csv file named as "record.csv". The file has two columns named as "epoch" and "error". The csv file can be examined via external sources like pandas, plotly etc.

![alt text](github%20resource/app_verbose.gif)

Error (loss) is calculated as sum of the sample's errors.

![equation](http://www.sciweavers.org/tex2img.php?eq=error%3D%5Csum_%7Bi%7D%5E%7Bn%7D%20L%28x_%7Bi%7D%2C%20y_%7Bi%7D%29&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0)

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

Let's consider a sample from the dataset. What is the probability that the data remain unshuffled after the shuffling phase.

For old algorithm
