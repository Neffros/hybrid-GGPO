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

        include(ggpo/src/cmake/properties.cmake)
        include(ggpo/src/cmake/helper_methods.cmake)

        if(WIN32)
            ## Prevent the CMake trying to install GGPO in Program Files on Windows
            if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
                set (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed" CACHE PATH "Default install path" FORCE)
            endif()
        endif()

        # What do we want to build?
        option(GGPO_BUILD_SDK "Enable the build of the GGPO SDK" ON)
        option(BUILD_SHARED_LIBS "Enable the build of shared libraries (.dll/.so) instead of static ones (.lib/.a)" ON)

        if(GGPO_BUILD_SDK)
            add_subdirectory(src)
        endif()

        if (CMAKE_VERSION VERSION_GREATER 3.12)
            set_property(TARGET HybridGGPO PROPERTY CXX_STANDARD 20)
        endif()

    endif()
endif()

