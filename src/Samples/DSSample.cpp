#include "../../headers/Samples/DSSample.h"

void DSSample::add(const int &value) {
    this->baseAdd(value);
}

void DSSample::add(const float &value) {
    this->baseAdd(value);
}

void DSSample::add(const double &value) {
    this->baseAdd(value);
}

void DSSample::add(const bool &value) {
    this->baseAdd(value);
}

void DSSample::add(const long &value) {
    this->baseAdd(value);
}

void DSSample::addCategorical(const int &value, const std::vector<int> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DSSample::addCategorical(const float &value, const std::vector<float> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DSSample::addCategorical(const double &value, const std::vector<double> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DSSample::addCategorical(const bool &value, const std::vector<bool> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DSSample::addCategorical(const long &value, const std::vector<long> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DSSample::addCategorical(const char &value, const std::vector<char> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DSSample::reinitData() {
    this->data.clear();
}

double* DSSample::getData() {
    return &this->data[0];
}

template<class T>
void DSSample::baseAdd(const T &value) {
    this->data.emplace_back((double) value);
}

template<class T>
void DSSample::baseAddCategorical(const T &value, const std::vector<T> &possibleValues) {
    for(auto it = possibleValues.begin(); it != possibleValues.end(); ++it)
    {
        if(*it == value)
            this->data.emplace_back((double) 1);
        else
            this->data.emplace_back((double) 0);
    }
}

template<class T>
void DSSample::baseAddCategorical(const T &value, const T *possibleValues) {
    for(auto i = 0; i < sizeof(possibleValues); ++i)
    {
        if(possibleValues[i] == value)
            this->data.emplace_back((double) 1);
        else
            this->data.emplace_back((double) 0);
    }
}

void DSSample::addCategorical(const int &value, const int *possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DSSample::addCategorical(const float &value, const float *possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DSSample::addCategorical(const double &value, const double *possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DSSample::addCategorical(const bool &value, const bool *possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DSSample::addCategorical(const long &value, const long *possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DSSample::addCategorical(const char &value, const char *possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}
