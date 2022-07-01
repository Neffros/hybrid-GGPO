#pragma once
#include "IInputPredictionStrategyService.h"

// Main strategy which uses hybrid prediction
class AHybridInputPredictionStrategy : public IInputPredictionStrategyService
{

public:
    virtual void onFrameAdvanced(int frame, char const* buffer, GameInput* input) override
    {
        // On remplit le sample avec les infos de l'état de jeu
        //this->fillSampleWithGameStateData(buffer);

        // On emmagasine dans une liste de samples ou autre
        // en s'assurant que la frame est bien celle qui suit la dernière frame fournie
        // (gestion à voir plus tard)
    }
    virtual void requestPrediction(int requestedFrame, char const* buffer, GameInput* input) override
    {
        // On récupère les X derniers samples pour faire la prediction
        // en s'assurant qu'on en a assez à partir de la frame requise

        // On utilise notre module custom de ML pour faire la prédiction
        // et on remplit l'input fourni en paramètre
    }
};