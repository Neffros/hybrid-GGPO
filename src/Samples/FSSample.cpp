#include "../../headers/Samples/FSSample.h"

FSSample::FSSample(const long SIZE): SIZE(SIZE) {
    this->data = new double[SIZE];
}

template<class T>
void FSSample::baseAdd(const T &value) {
    this->data[this->index] = ((double) value);
    ++this->index;
}

template<class T>
void FSSample::baseAddCategorical(const T &value, const std::vector<T> &possibleValues) {
    for(auto it = possibleValues.begin(); it != possibleValues.end(); ++it)
    {
        if(*it == value)
            this->data[this->index] =(double) 1;
        else
            this->data[this->index] =(double) 0;
        ++this->index;
    }
}

template<class T>
void FSSample::baseAddCategorical(const T &value, const T *possibleValues) {
    for(auto i = 0; i < sizeof(possibleValues); ++i)
    {
        if(possibleValues[i] == value)            
            this->data[this->index] =(double) 1;
        else
            this->data[this->index] =(double) 0;
        ++this->index;
    }
}

void FSSample::add(const int &value) {
    this->baseAdd(value);
}

void FSSample::add(const float &value) {
    this->baseAdd(value);
}

void FSSample::add(const double &value) {
    this->baseAdd(value);
}

void FSSample::add(const bool &value) {
    this->baseAdd(value);
}

void FSSample::add(const long &value) {
    this->baseAdd(value);
}

void FSSample::addCategorical(const int &value, const std::vector<int> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void FSSample::addCategorical(const float &value, const std::vector<float> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void FSSample::addCategorical(const double &value, const std::vector<double> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void FSSample::addCategorical(const bool &value, const std::vector<bool> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void FSSample::addCategorical(const long &value, const std::vector<long> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void FSSample::addCategorical(const char &value, const std::vector<char> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void FSSample::addCategorical(const int &value, const int *possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void FSSample::addCategorical(const float &value, const float *possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void FSSample::addCategorical(const double &value, const double *possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void FSSample::addCategorical(const bool &value, const bool *possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void FSSample::addCategorical(const long &value, const long *possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void FSSample::addCategorical(const char &value, const char *possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void FSSample::reinitData() {
    std::fill_n(this->data, sizeof(this->data), 0);
    this->index = 0;
}

double *FSSample::getData() {
    return this->data;
}

