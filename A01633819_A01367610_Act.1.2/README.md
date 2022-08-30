# Activity 1.2 Implementation of the programming techniques "Dynamic programming" and "greedy algorithms"
###### Andrés Alejandro Guzmán González - A01633819
###### José Pablo Naime García - A01367610

### Algorithm functionality

This algorithm solves the **Coin Change Problem** using the *dynamic and greedy programming tecniques*. This program needs several inputs: 
    - First of all, you have to define the number of coin and bills denominations to be considerated.
    - Then you have to enter the different denominations of coins and bills, the program is going to ask for the number of denominations defined in the first input.
    - Finally 


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

- `test_1.txt` - Optimal input
- `test_2.txt` - Input with denominations in disorder 
- `test_3.txt` - Defined input size is **lower** than the total amount of values 
- `test_4.txt` - Defined input size is **higher** than the total amount of values
- `test_5.txt` - No input at all (No defined input size nor values)
- `test_6.txt` - Input with repited values
