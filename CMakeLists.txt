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

        add_subdirectory(ggpo)
        add_subdirectory(DALIL_DILER_GACON_ML_5A/Atlus)

        add_library(HybridGGPO
            "src/main.cpp"
            "src/session/HybridP2PSession.cpp"
            "src/synchronisation/SyncWithPredictionStrategy.cpp"
        )

        target_link_libraries(HybridGGPO Atlus)
        target_link_libraries(HybridGGPO GGPO)
    endif()
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET HybridGGPO PROPERTY CXX_STANDARD 20)
endif()
