#pragma once
#include <vector>

class DSSample {
private:
    std::vector<double> _data;

private:
    template<class T>
    void baseAdd(const T& value);

    template<class T>
    void baseAddCategorical(const T& value, const std::vector<T>& possibleValues);

    template<class T>
    void baseAddCategorical(const T& value, const T* possibleValues, size_t size);

public:
    void add(const int& value);
    void add(const float& value);
    void add(const double& value);
    void add(const bool& value);
    void add(const long& value);

    void addCategorical(const int& value, const std::vector<int>& possibleValues);
    void addCategorical(const int& value, const int* possibleValues, size_t size);

    void addCategorical(const float& value, const std::vector<float>& possibleValues);
    void addCategorical(const float& value, const float* possibleValues, size_t size);

    void addCategorical(const double& value, const std::vector<double>& possibleValues);
    void addCategorical(const double& value, const double* possibleValues, size_t size);

    void addCategorical(const bool& value, const std::vector<bool>& possibleValues);
    void addCategorical(const bool& value, const bool* possibleValues, size_t size);

    void addCategorical(const long& value, const std::vector<long>& possibleValues);
    void addCategorical(const long& value, const long* possibleValues, size_t size);

    void addCategorical(const char& value, const std::vector<char>& possibleValues);
    void addCategorical(const char& value, const char* possibleValues, size_t size);

    void reinitData();

    void getData(double* array) const;
};