# Purpose
This project barrows some code from the "bare bones" level 01 implementation of the FFT and uses them to implement the FFT for a matrix. 
For the following inputs:
```
4
0 1 2 3
4 5 6 7
8 9 10 11
12 13 14 15
```
expect:
```
DiscreteLimit[
(30 + 0 i | -2 - 2 i | -2 + 0 i | -2 + 2 i
-8 - 8 i | 0 i | 0 i | 0 i
-8 + 0 i | 0 i | 0 i | 0 i
-8 + 8 i | 0 i | 0 i | 0 i)]
```
For: 
```
2
1 2
2 1
```
expect:
```
DiscreteLimit[
(3 | 0
0 | -1)]
```
The examples are according to WolframAlpha.
This is how the example will be introduced: discrete fourier of [[1, 2], [2, 1]]
