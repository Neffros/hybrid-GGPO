#include "../headers/samples/DatasetDSSampleMapper.h"

void DatasetDSSampleMapper::add(const int &value) {
    this->baseAdd(value);
}

void DatasetDSSampleMapper::add(const float &value) {
    this->baseAdd(value);
}

void DatasetDSSampleMapper::add(const double &value) {
    this->baseAdd(value);
}

void DatasetDSSampleMapper::add(const bool &value) {
    this->baseAdd(value);
}

void DatasetDSSampleMapper::add(const long &value) {
    this->baseAdd(value);
}

void DatasetDSSampleMapper::addCategorical(const int &value, const std::vector<int> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DatasetDSSampleMapper::addCategorical(const float &value, const std::vector<float> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DatasetDSSampleMapper::addCategorical(const double &value, const std::vector<double> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DatasetDSSampleMapper::addCategorical(const bool &value, const std::vector<bool> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DatasetDSSampleMapper::addCategorical(const long &value, const std::vector<long> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DatasetDSSampleMapper::addCategorical(const char &value, const std::vector<char> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DatasetDSSampleMapper::reinitData() {
    this->_data.clear();
}

template<class T>
void DatasetDSSampleMapper::baseAdd(const T &value) {
    this->_data.push_back((double) value);
}

template<class T>
void DatasetDSSampleMapper::baseAddCategorical(const T &value, const std::vector<T> &possibleValues) {
    for(auto it = possibleValues.begin(); it != possibleValues.end(); ++it)
    {
        this->_data.push_back(value == *it ? 1 : 0);
    }
}

template<class T>
void DatasetDSSampleMapper::baseAddCategorical(const T &value, const T *possibleValues, const size_t size) {
    for(auto i = 0; i < size; ++i)
    {
        this->_data.push_back(value == possibleValues[i] ? 1 : 0);
    }
}

void DatasetDSSampleMapper::addCategorical(const int &value, const int *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void DatasetDSSampleMapper::addCategorical(const float &value, const float *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void DatasetDSSampleMapper::addCategorical(const double &value, const double *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void DatasetDSSampleMapper::addCategorical(const bool &value, const bool *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void DatasetDSSampleMapper::addCategorical(const long &value, const long *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void DatasetDSSampleMapper::addCategorical(const char &value, const char *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void DatasetDSSampleMapper::getData(double* array, size_t& size) const {
    auto dataBegin = this->_data.begin();
    auto dataEnd = this->_data.end();
    size = dataEnd - dataBegin;
    std::copy(dataBegin, dataEnd, array);
}

DatasetDSSampleMapper::DatasetDSSampleMapper() = default;

