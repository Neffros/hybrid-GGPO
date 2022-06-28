#pragma once
#include <vector>

class FSSample
{
private:
    const size_t SIZE;
    double* data;
    unsigned int index = 0;
    template<class T>
    void baseAdd(const T& value);

    template<class T>
    void baseAddCategorical(const T& value, const std::vector<T>& possibleValues);

    template<class T>
    void baseAddCategorical(const T& value, const T* possibleValues);
public:
    explicit FSSample(long SIZE);

    void add(const int& value);
    void add(const float& value);
    void add(const double& value);
    void add(const bool& value);
    void add(const long& value);

    void addCategorical(const int& value, const std::vector<int>& possibleValues);
    void addCategorical(const int& value, const int* possibleValues);

    void addCategorical(const float& value, const std::vector<float>& possibleValues);
    void addCategorical(const float& value, const float* possibleValues);

    void addCategorical(const double& value, const std::vector<double>& possibleValues);
    void addCategorical(const double& value, const double* possibleValues);

    void addCategorical(const bool& value, const std::vector<bool>& possibleValues);
    void addCategorical(const bool& value, const bool* possibleValues);

    void addCategorical(const long& value, const std::vector<long>& possibleValues);
    void addCategorical(const long& value, const long* possibleValues);

    void addCategorical(const char& value, const std::vector<char>& possibleValues);
    void addCategorical(const char& value, const char* possibleValues);


    void reinitData();

    double* getData();
};