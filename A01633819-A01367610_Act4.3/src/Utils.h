/*

Activity 4.3 Implementation of the Randomized Binary Search
Andrés Alejandro Guzmán González - A01633819
José Pablo Naime García - A01367610

This class contains all the auxiliar functions to solve and keep organized the implementation

*/

#ifndef UTILIS_ACT_4_3
#define UTILIS_ACT_4_3

class Utils{
    private:
        static int createRandPiv(int, int);
        static int BinarySearch(vector<int> , int, int, int);
    public:
        static void makeDataVec (vector<int> &, string);
        static void printVec(vector<int>);
        static void lasVegasBinarySearch(vector<int> &, int);
};

// makeDataVec Complexity O(n)
// Function to separate the input array bay commas
void Utils::makeDataVec (vector<int> &vec, string val){
    stringstream sstr(val);
    while(sstr.good()){
        string number;
        getline(sstr, number, ',');
        vec.push_back(stoi(number));
    }
}

// printVec Complexity O(n)
// Function to show the values of a vector
void Utils::printVec(vector<int> vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

// createRandPiv Complexity O(1)
// Function tu create a random number in between 2 numbers
int Utils::createRandPiv(int beg, int end){
    srand(time(NULL));
    return (beg + rand() % (end - beg+1));
}

// BinarySearch Complexity O(log(n))
// Recursive implementation of the Binary Search
int Utils::BinarySearch(vector<int> vec, int num, int beg, int end){
    if (beg <= end){
        int piv = createRandPiv(beg, end); // The search pivot is created

        if (vec[piv] == num){ // If the searched value is found returns the index
            return piv;
        }
        else if (vec[piv] > num){
            return BinarySearch(vec, num, beg, piv-1);
        }
        else{
            return BinarySearch(vec, num, piv+1, end);
        }
    }
    return -1; // If not found returns -1
}

// lasVegasBinarySearch Complexity O(1) - 
// Auxiliar fucntion for the search process it prints the results.
void Utils::lasVegasBinarySearch(vector<int> &vec, int num){
    int ans = BinarySearch(vec, num, 0, vec.size()-1);
    if (ans > 0){
        cout << "El elemento esta presente en el indice: " << ans << endl;
    }
    else{
        cout << "El elemento no esta presente en el arreglo " << endl;
    }
}

#endif //UTILS_ACT_4_3