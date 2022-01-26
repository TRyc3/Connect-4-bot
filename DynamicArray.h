//Made by Brycen Tanaka
#ifndef _DYNAMICARRAY_
#define _DYNAMICARRAY_

#include <cstdlib>
#include <iostream>


using namespace std;

class Darr{
public:
    Darr() {
        used_ = 0;
        capacity_ = 0;
        data_ = nullptr;
    }

    void insert(int in){
        if (capacity_ == 0) {
            capacity_++;
            data_ = new int[capacity_];
        } else if (capacity_ == used_) {
            capacity_ *= 2;
            int *temp = new int[capacity_];
            for (int i = 0; i < used_; i++) {
                temp[i] = data_[i];
            }
            delete [] data_;
            data_ = temp;
        }
        data_[used_] = in;
        used_++;
    }

    bool contains (int target){
        for (int i = used_; i > 0; i++){
            if (data_[i] == target){
                return true;
            }
        }
        return false;
    }

    void undolast(){
        if(used_ > 0){
            used_--;
        }
    }

    int used(){
        return used_;
    }

    int operator [](int target){
        return data_[target];
    }    

    void operator =(Darr rhs){
        data_ = rhs.data_;
        capacity_ = rhs.capacity_;
        used_ = rhs.used_;
    }

private:
    int* data_;
    int capacity_;
    int used_;
};

class LDarr{
public:
    LDarr() {
        used_ = 0;
        capacity_ = 0;
        data_ = nullptr;
    }

    void insert(long in){
        if (capacity_ == 0) {
            capacity_++;
            data_ = new long[capacity_];
        } else if (capacity_ == used_) {
            capacity_ *= 2;
            long *temp = new long[capacity_];
            for (int i = 0; i < used_; i++) {
                temp[i] = data_[i];
            }
            delete [] data_;
            data_ = temp;
        }
        data_[used_] = in;
        used_++;
    }

    bool contains (long target){
        for (int i = used_; i > 0; i--){
            if (data_[i] == target){
                return true;
            }
        }
        return false;
    }

    bool twoinarow(long one, long two){
        for (int i = 0; i < used_ - 1; i += 2){
            if (data_[i] == one && data_[i + 1] == two){
                return true;
            }
        }
        return false;
    }

    void undolast(){
        if(used_ > 0){
            used_--;
        }
    }

    int used(){
        return used_;
    }

    int operator [](int target){
        return data_[target];
    }    

    void operator =(LDarr rhs){
        data_ = rhs.data_;
        capacity_ = rhs.capacity_;
        used_ = rhs.used_;
    }

private:
    long* data_;
    int capacity_;
    int used_;
};

#endif // _DYNAMICARRAY_