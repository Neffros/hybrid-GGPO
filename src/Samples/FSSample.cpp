#include "../../headers/Samples/FSSample.h"

template<class T>
FSSample::FSSample(const T size): _size(size) {
    this->_data = new double[size];
}

template<class T>
void FSSample::baseAdd(const T &value) {
    this->_data[this->_index] = ((double) value);
    ++this->_index;
}

template<class T>
void FSSample::baseAddCategorical(const T &value, const std::vector<T> &possibleValues) {
    for(auto it = possibleValues.begin(); it != possibleValues.end(); ++it)
    {
        this->_data[this->_index] = (value == *it ? 1 : 0);
    }
    this->_index += possibleValues.size();
}

template<class T>
void FSSample::baseAddCategorical(const T &value, const T *possibleValues, const size_t size) {
    for(auto i = 0; i < size; ++i)
    {
        this->_data[this->_index] = (value == possibleValues[i] ? 1 : 0);

    }
    this->_index += size;
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

void FSSample::addCategorical(const int &value, const int *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void FSSample::addCategorical(const float &value, const float *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void FSSample::addCategorical(const double &value, const double *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void FSSample::addCategorical(const bool &value, const bool *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void FSSample::addCategorical(const long &value, const long *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void FSSample::addCategorical(const char &value, const char *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void FSSample::reinitData() {
    this->_index = 0;
}

void FSSample::getData(double* array) const {
    std::copy(this->_data, this->_data + this->_size, array);
}

