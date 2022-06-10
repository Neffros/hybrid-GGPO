// hybrid_ggpo.cpp : Defines the entry point for the application.
//

#include "../headers/hybrid_ggpo.h"
#include "ggponet.h"
#include "../DALIL_DILER_GACON_ML_5A/Atlus/src/headers/core.h"

using namespace std;

void test()
{
	cout << "Hello CMake." << endl;
    uint test[2] = {1,1};
    auto model = createMlpModel(test,2);

    destroyMlpModel(model);

    ggpo_advance_frame((GGPOSession*)(void*)0);
    cout << "ended process" << endl;
}
