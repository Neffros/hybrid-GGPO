#pragma once
#include <vector>

class DSSample {
private:
    std::vector<double> data;
public:
    void add(const int& value);
    void add(const float& value);
    void add(const double& value);
    void add(const bool& value);
    void add(const long& value);

    void addOneHot(const int& value, const std::vector<int>& possibleValues);
    void addOneHot(const float& value, const std::vector<float>& possibleValues);
    void addOneHot(const double& value, const std::vector<double>& possibleValues);
    void addOneHot(const bool& value, const std::vector<bool>& possibleValues);
    void addOneHot(const long& value, const std::vector<long>& possibleValues);
    void addOneHot(const char& value, const std::vector<char>& possibleValues);
    void addOneHot(const char* value, const std::vector<char*>& possibleValues);

    void reinitData();

    std::vector<double> getData();
};