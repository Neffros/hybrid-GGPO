#include <algorithm>
#include "../../headers/Samples/DSSample.h"

void DSSample::add(const int &value) {
    this->data.emplace_back((double) value);
}

void DSSample::add(const float &value) {
    this->data.emplace_back((double) value);
}

void DSSample::add(const double &value) {
    this->data.emplace_back(value);
}

void DSSample::add(const bool &value) {
    this->data.emplace_back((double) value*1);
}

void DSSample::add(const long &value) {
    this->data.emplace_back((double) value);
}

void DSSample::addOneHot(const int &value, const std::vector<int> &possibleValues) {
    for(auto it = possibleValues.begin(); it != possibleValues.end(); ++it)
    {
        if(*it == value)
            this->data.emplace_back((double) 1);
        else
            this->data.emplace_back((double) 0);
    }
}

void DSSample::addOneHot(const float &value, const std::vector<float> &possibleValues) {
    for(auto it = possibleValues.begin(); it != possibleValues.end(); ++it)
    {
        if(*it == value)
            this->data.emplace_back((double) 1);
        else
            this->data.emplace_back((double) 0);
    }
}

void DSSample::addOneHot(const double &value, const std::vector<double> &possibleValues) {
    for(auto it = possibleValues.begin(); it != possibleValues.end(); ++it)
    {
        if(*it == value)
            this->data.emplace_back((double) 1);
        else
            this->data.emplace_back((double) 0);
    }
}

void DSSample::addOneHot(const bool &value, const std::vector<bool> &possibleValues) {
    for(auto it = possibleValues.begin(); it != possibleValues.end(); ++it)
    {
        if(*it == value)
            this->data.emplace_back((double) 1);
        else
            this->data.emplace_back((double) 0);
    }
}

void DSSample::addOneHot(const long &value, const std::vector<long> &possibleValues) {
    for(auto it = possibleValues.begin(); it != possibleValues.end(); ++it)
    {
        if(*it == value)
            this->data.emplace_back((double) 1);
        else
            this->data.emplace_back((double) 0);
    }
}

void DSSample::addOneHot(const char &value, const std::vector<char> &possibleValues) {
    for(auto it = possibleValues.begin(); it != possibleValues.end(); ++it)
    {
        if(*it == value)
            this->data.emplace_back((double) 1);
        else
            this->data.emplace_back((double) 0);
    }
}

void DSSample::addOneHot(const char *value, const std::vector<char *>& possibleValues) {
    for(auto it = possibleValues.begin(); it != possibleValues.end(); ++it)
    {
        if(*it == value)
            this->data.emplace_back((double) 1);
        else
            this->data.emplace_back((double) 0);
    }
}

void DSSample::reinitData() {
    this->data.clear();
}

std::vector<double> DSSample::getData() {
    return this->data;
}
