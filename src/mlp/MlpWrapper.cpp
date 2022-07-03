#include "../headers/mlp/MlpWrapper.h"

double *MLPHandler::flatSamples(m2 samples) {
        uint sampleCount = samples.size();
        uint sampleDim = samples[0].size();
        auto* data = new double[sampleCount * sampleDim];

        for (uint i = 0; i < sampleCount; ++i)
            std::copy(samples[i].begin(), samples[i].end(), data + sampleDim * i);

        return data;
}

MLPHandler::MLPHandler(const char *path) {
    std::ifstream file(path);
    std::stringstream buffer;

    buffer << file.rdbuf();

    file.close();

    this->model = deserializeModel(buffer.str().c_str());
    this->outputDim = this->model->npl[this->model->L];
}

MLPHandler::MLPHandler(std::vector<uint> npl) {
    const uint size = npl.size();
    this->model = createMlpModel(npl.data(), size);
    this->outputDim = npl[size - 1];
}

double MLPHandler::evaluateClassification(m2 inputs, m2 outputs) const {
    const double* inputArr = flatSamples(inputs);
    const double* outputArr = flatSamples(outputs);

    const double result = evaluateModelAccuracyClassification(this->model, inputArr, outputArr, inputs.size(), inputs[0].size(), outputs[0].size()) * 100;

    delete[] inputArr;
    delete[] outputArr;

    std::cout << "Accuracy : " << result << "%" << std::endl;

    return result;
}

m1 MLPHandler::predictClassification(m1 input) const {
    const double* resultArr = predictMlpModelClassification(this->model, input.data());
    m1 result;

    result.reserve(this->outputDim);

    std::copy(resultArr, resultArr + this->outputDim, std::back_inserter(result));

    destroyMlpResult(resultArr);

    return result;
}

m1 MLPHandler::predictRegression(m1 input) const {
    const double* resultArr = predictMlpModelClassification(this->model, input.data());
    m1 result;

    result.reserve(this->outputDim);

    std::copy(resultArr, resultArr + this->outputDim, std::back_inserter(result));

    destroyMlpResult(resultArr);

    return result;
}

void MLPHandler::save(std::string path) const {
    std::ofstream file(path);

    const char* data = serializeModel(this->model);

    file << data;

    destroyMlpSerializedData(data);

    file.close();
}

void MLPHandler::trainClassification(m2 inputs, m2 outputs, double alpha, uint epochs) const {
    const double* inputArr = flatSamples(inputs);
    const double* outputArr = flatSamples(outputs);

    trainMlpModelClassification(this->model, inputArr, outputArr, inputs.size(), inputs[0].size(), outputs[0].size(), alpha, epochs);

    delete[] inputArr;
    delete[] outputArr;
}

void MLPHandler::trainRegression(m2 inputs, m2 outputs, double alpha, uint epochs) const {
    const double* inputArr = flatSamples(inputs);
    const double* outputArr = flatSamples(outputs);

    trainMlpModelRegression(this->model, inputArr, outputArr, inputs.size(), inputs[0].size(), outputs[0].size(), alpha, epochs);

    delete[] inputArr;
    delete[] outputArr;
}