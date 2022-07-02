#pragma once

#include "IGameStateService.h"
#include "../../samples/DatasetDSSampleMapper.h"

class AGameStateDSSService : public IGameStateService {
private:
    DatasetDSSampleMapper _datasetDSSampleMapper;
public:
    AGameStateDSSService();
    double* ConvertGameStateToDataset(char* gameState) override;
};