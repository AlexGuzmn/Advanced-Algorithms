# Activity 1.2 Implementation of the programming techniques "Dynamic programming" and "greedy algorithms"
###### Andrés Alejandro Guzmán González - A01633819
###### José Pablo Naime García - A01367610

### Algorithm functionality

This algorithm solves the **Coin Change Problem** using the *dynamic and greedy programming techniques*. This program needs several inputs: 

    - First of all, you have to define the number of coin and bills denominations to be considerated.
    - Then you have to enter the different denominations of coins and bills. The program is going to ask for the number of denominations defined in the first input.
    - Finally it is required to enter 2 more numbers. The first one is the price to be paid and the second one is the amount recived to calculate the change to return.

After all the inputs are entered it is called a **MergeSort** to sort the denominations from the higher to lower values. After that the program calculates the change to return and shows the distribution of bills and coins by using the techniques previusly mentionated. There will be messages to inform if there is no change to return, if the payment is less than the price and if the algorithm can not solve the problem because of the given denominations.

### How to use it?

Open your terminal and run the following command 
```
g++ main -o outputName
```
An executable will be created and you'll be able to run it with an input file by executing (example with the first test input `inputs/test_1.txt`):
```
./outputName < inputs/test_1.txt
```

### Testing Files
For testing edge cases, you can find some files at the `inputs/` folder:

- `test_1.txt` - General expected input
- `test_2.txt` - Input with denominations in disorder 
- `test_3.txt` - Input with denominations sorted form the lowest to the higher values
- `test_4.txt` - Input without a $1 coin
- `test_5.txt` - Input with denominatios that can be only solved by dynamic programming.
