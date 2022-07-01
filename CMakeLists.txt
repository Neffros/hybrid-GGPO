cmake_minimum_required (VERSION 3.8)

project (HybridGGPO)

find_package(Git QUIET)

if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    message("FOUND GIT")

    option(GIT_SUBMODULE "Check submodules during build" ON)

    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")

        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                RESULT_VARIABLE GIT_SUBMOD_RESULT)


        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()

        # Remove RelWithDebInfo and MinSizeRelease build types to match the original Visual Studio Project. 
        set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)

        add_subdirectory(ggpo)
        add_subdirectory(DALIL_DILER_GACON_ML_5A/Atlus)

        add_library(HybridGGPO
                "src/main.cpp" "hybrid_ggpo.h"
                "src/headers/samples/DSSample.h" "src/Samples/DSSample.cpp"
                "src/headers/samples/FSSample.h" "src/Samples/FSSample.cpp"
                "src/headers/samples/DatasetSampleMapper.h"
                "src/headers/mlp/MlpWrapper.h" "src/mlp/MlpWrapper.cpp"
                "src/headers/strategy/IInputPredictionStrategyService.h"
                "src/headers/strategy/ARandomInputPredictionStrategyService.h"
                "src/headers/GameStateService.h" "src/GameStateService.cpp"
                "src/headers/HybridGGPOServiceProvider.h" "src/HybridGGPOServiceProvider.cpp"
                "src/headers/synchronisation/HybridSync.h" "src/synchronisation/HybridSync.cpp"
                "src/session/HybridP2PSession.cpp"
                "src/synchronisation/HybridInputQueue.cpp"
                "src/synchronisation/HybridSync.cpp"
        )

        target_link_libraries(HybridGGPO Atlus)
        target_link_libraries(HybridGGPO GGPO)

        if (CMAKE_VERSION VERSION_GREATER 3.12)
            set_property(TARGET HybridGGPO PROPERTY CXX_STANDARD 20)
        endif()
    endif()
endif()

