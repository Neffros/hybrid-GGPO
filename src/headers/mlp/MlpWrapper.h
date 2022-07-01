#pragma once

#include "../../../DALIL_DILER_GACON_ML_5A/Atlus/src/headers/core.h"

#include <vector>
#include <iterator>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

struct MLPHandler
{
public:
    static double* flatSamples(m2 samples);

    MLPData* model;
    uint outputDim;

    explicit MLPHandler(const char* path);

    explicit MLPHandler(std::vector<uint> npl);

    ~MLPHandler()
    {
        destroyMlpModel(this->model);
    }

    double evaluateClassification(m2 inputs, m2 outputs) const;

    double evaluateRegression(m2 inputs, m2 outputs);

    m1 predictClassification(m1 input) const;

    m1 predictRegression(m1 input) const;

    void save(std::string path) const;

    void trainClassification(m2 inputs, m2 outputs, double alpha, uint epochs) const;

    void trainRegression(m2 inputs, m2 outputs, double alpha, uint epochs) const;
};