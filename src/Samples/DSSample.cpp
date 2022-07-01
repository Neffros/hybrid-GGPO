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
    this->_data.clear();
}

template<class T>
void DSSample::baseAdd(const T &value) {
    this->_data.push_back((double) value);
}

template<class T>
void DSSample::baseAddCategorical(const T &value, const std::vector<T> &possibleValues) {
    for(auto it = possibleValues.begin(); it != possibleValues.end(); ++it)
    {
        this->_data.push_back(value == *it? 0 : 1);
    }
}

template<class T>
void DSSample::baseAddCategorical(const T &value, const T *possibleValues, const size_t size) {
    for(auto i = 0; i < size; ++i)
    {
        this->_data.push_back(value == possibleValues[i]? 0 : 1);
    }
}

void DSSample::addCategorical(const int &value, const int *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void DSSample::addCategorical(const float &value, const float *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void DSSample::addCategorical(const double &value, const double *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void DSSample::addCategorical(const bool &value, const bool *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void DSSample::addCategorical(const long &value, const long *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void DSSample::addCategorical(const char &value, const char *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void DSSample::getData(double* array) const {
    std::copy(this->_data.begin(), this->_data.end(), array);
}

