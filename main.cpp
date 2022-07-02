#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Bogosort{
    private:
        int size; 
        int *array;
    public: Bogosort(int size){
        this->size = size; 
        this->array = new int[this->size];
        this->initArray();
    }
    int generateRandomNumber(int lowerLimit, int upperLimit){
        return (rand() % upperLimit) + lowerLimit;
    }
    void initArray(){
        srand((unsigned)time(0));
        for(int i = 0; i < this->size; i++){
            this->array[i] = this->generateRandomNumber( 10, 20 ); //[10...20]
        }
    }
    bool isOrdenate(){
        bool result;
        int counter = 0;
        for (int i = 0; i < this->size ; i++){   //Sea Z = [10,.., 20], i E Z | i < Z - 1
            if (this->array[i] <= this->array[i + 1]){
                counter++;
                result = ( counter == this->size - 1 ) ? true : false;
            }
        }
        return result;
    }
    void ordenate(){
        srand((unsigned)time(0));
        int tmp = 0;
        while( this->isOrdenate() == false ){
            int i = this->generateRandomNumber(0, this->size);
            int j = this->generateRandomNumber(0, this->size);
            tmp = this->array[i];
            this->array[i] = this->array[j];
            this->array[j] = tmp;
            this->printArray();
            cout<<endl<<endl;
        }
        if( this->isOrdenate() ){
            cout << "Array ordered: ";
            this->printArray();
            delete[] this->array; //Deallocate array
        }
    }
    void printArray(){
        for (int i = 0; i < this->size; i++){
            cout<< this->array[i] << " ";
        }
    }
};
//MAIN
int main(){
    Bogosort bgsrt = Bogosort(5);
    //Get starting timepoint
    auto start = high_resolution_clock::now();
    bgsrt.ordenate();
    //Get ending timepoint
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by function: "<< duration.count() << " milliseconds" << endl;
    cin.get();
}