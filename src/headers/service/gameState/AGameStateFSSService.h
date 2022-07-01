#pragma once

#include "IGameStateService.h"
#include "../../samples/DatasetFSSampleMapper.h"

class AGameStateFSSService : public IGameStateService {
private:
    DatasetFSSampleMapper _datasetFSSampleMapper;
public:
    AGameStateFSSService(size_t size);
    double* ConvertGameStateToDataset(char* gameState);
};