# Activity 1.1 Implmentation of the tecnic divide and conquer - MergeSort
###### Andrés Alejandro Guzmán González - A01633819
###### José Pablo Naime García - A01367610

### Algorithm functionality

The algorithm sorts a set of numbers in a descendent way using the "MergeSort Algorithm". The program needs 2 types of inputs; the first one is the number of data to be stored in the vector, followed by every single value to be saved. After that, the program is going to show all the stored values and the vector size. Finally and after the sort is done, it is expected to show the values in order.

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
- `test_2.txt` - Input with Integers and Double values
- `test_3.txt` - Defined input size is **lower** than the total amount of values 
- `test_4.txt` - Defined input size is **higher** than the total amount of values
- `test_5.txt` - No input at all (No defined input size nor values)
- `test_6.txt` - Input with repited values
