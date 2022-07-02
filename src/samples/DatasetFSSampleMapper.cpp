#include "../headers/samples/DatasetFSSampleMapper.h"

template<class T>
DatasetFSSampleMapper::DatasetFSSampleMapper(const T size): _size(size) {
    this->_data = new double[size];
}

template<class T>
void DatasetFSSampleMapper::baseAdd(const T &value) {
    this->_data[this->_index] = ((double) value);
    ++this->_index;
}

template<class T>
void DatasetFSSampleMapper::baseAddCategorical(const T &value, const std::vector<T> &possibleValues) {
    for(auto it = possibleValues.begin(); it != possibleValues.end(); ++it)
    {
        this->_data[this->_index] = (value == *it ? 1 : 0);
    }
    this->_index += possibleValues.size();
}

template<class T>
void DatasetFSSampleMapper::baseAddCategorical(const T &value, const T *possibleValues, const size_t size) {
    for(auto i = 0; i < size; ++i)
    {
        this->_data[this->_index] = (value == possibleValues[i] ? 1 : 0);

    }
    this->_index += size;
}

void DatasetFSSampleMapper::add(const int &value) {
    this->baseAdd(value);
}

void DatasetFSSampleMapper::add(const float &value) {
    this->baseAdd(value);
}

void DatasetFSSampleMapper::add(const double &value) {
    this->baseAdd(value);
}

void DatasetFSSampleMapper::add(const bool &value) {
    this->baseAdd(value);
}

void DatasetFSSampleMapper::add(const long &value) {
    this->baseAdd(value);
}

void DatasetFSSampleMapper::addCategorical(const int &value, const std::vector<int> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DatasetFSSampleMapper::addCategorical(const float &value, const std::vector<float> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DatasetFSSampleMapper::addCategorical(const double &value, const std::vector<double> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DatasetFSSampleMapper::addCategorical(const bool &value, const std::vector<bool> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DatasetFSSampleMapper::addCategorical(const long &value, const std::vector<long> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DatasetFSSampleMapper::addCategorical(const char &value, const std::vector<char> &possibleValues) {
    this->baseAddCategorical(value, possibleValues);
}

void DatasetFSSampleMapper::addCategorical(const int &value, const int *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void DatasetFSSampleMapper::addCategorical(const float &value, const float *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void DatasetFSSampleMapper::addCategorical(const double &value, const double *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void DatasetFSSampleMapper::addCategorical(const bool &value, const bool *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void DatasetFSSampleMapper::addCategorical(const long &value, const long *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void DatasetFSSampleMapper::addCategorical(const char &value, const char *possibleValues, const size_t size) {
    this->baseAddCategorical(value, possibleValues, size);
}

void DatasetFSSampleMapper::reinitData() {
    this->_index = 0;
}

void DatasetFSSampleMapper::getData(double* array) const {
    std::copy(this->_data, this->_data + this->_size, array);
}


