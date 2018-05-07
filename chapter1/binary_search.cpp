#include <iostream>
using namespace std;

/*
*array: the array that will be use to search for
*target: the number you want to find
*length: the length of the array or the range you want to use

*description: In c++, I have no ideal about how to count the array length simply.
              You may want to use "sizeof(array)/sizeof(array[0])", but what if you
              use "array = new int[number]" to initialize the array? So the length
              paramet is necessary.Or you can use the std::vector<int> to replace
              the array, so that we can use the vector.size() function to get the length
*/
int  binary_search(int  *array,  int  target,  int  length){

    // initialize some variables
    int  low   = 0;
    int  hight = length - 1;

    // the main loop
    while (low <= hight){
        // get the middle point of the array[low:hight]
        int   mid = (low + hight) / 2;

        // test if the array[mid] equal to target
        if (array[mid] == target){
            // find out the result, just return the index
            return mid;
        }
        else {
            // if array[mid] is less than target, it is betweeb the array[mid] and array[hight]
            // otherwise it is between array[low] and array[mid]
            if (array[mid] < target)  low = mid + 1;
            else  hight = mid - 1;
        }
    }

    // finally if we can't find the target,
    // return -1
    return -1;
}


// test function

int main(){
    int *a = new int[10];
    for (int i = 0; i < 10; i++){
        a[i] = i + 1;
    }

    // some tese
    cout << binary_search(a, 1, 10) << endl;
    cout << binary_search(a, 5, 10) << endl;
    cout << binary_search(a, 3, 10) << endl;
    cout << binary_search(a, 7, 10) << endl;
    cout << binary_search(a, 10, 10) << endl;
    cout << binary_search(a, -1, 10) << endl;
    cout << binary_search(a, 11, 10) << endl;

    return 0;
}
