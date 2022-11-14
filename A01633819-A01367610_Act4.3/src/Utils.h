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

void Utils::makeDataVec (vector<int> &vec, string val){
    stringstream sstr(val);
    while(sstr.good()){
        string number;
        getline(sstr, number, ',');
        vec.push_back(stoi(number));
    }
}

void Utils::printVec(vector<int> vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

int Utils::createRandPiv(int beg, int end){
    srand(time(NULL));
    return (beg + rand() % (end - beg+1));
}


int Utils::BinarySearch(vector<int> vec, int num, int beg, int end){
    if (beg <= end){
        int piv = createRandPiv(beg, end);
        if (vec[piv] == num){
            return piv;
        }
        else if (vec[piv] > num){
            return BinarySearch(vec, num, beg, piv-1);
        }
        else{
            return BinarySearch(vec, num, piv+1, end);
        }
    }
    return -1;

    // while (beg <= end){
    //     int piv = createRandPiv(beg, end);

    //     if (vec[piv] == num){
    //         return piv;
    //     }
    //     else if (vec[piv] > num){
    //         end = piv - 1;
    //     }
    //     else{
    //         beg = piv + 1;
    //     }
    // }
    // return -1;
}

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