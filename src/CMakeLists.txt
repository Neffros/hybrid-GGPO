include(CMakeSources.cmake)

add_library(HybridGGPO
        ${HYBRID_GGPO_LIB_SRC}
        )

add_common_flags(HybridGGPO)

target_include_directories(HybridGGPO PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/headers>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../ggpo/src/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../ggpo/src/lib/ggpo>
        )

if(WIN32)
    target_compile_options(HybridGGPO PRIVATE "/W4" "/WX")
    if(BUILD_SHARED_LIBS)
        # Link to Multimedia API and Winsocks during a shared build.
        target_link_libraries(HybridGGPO PUBLIC winmm.lib ws2_32.lib)
        add_definitions(-DGGPO_SHARED_LIB)
        add_definitions(-DGGPO_SDK_EXPORT)
    endif()
endif()

#set_target_properties(HybridGGPO PROPERTIES VERSION ${PROJECT_VERSION})

# Install
install(
        DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include
        DESTINATION ./
        FILES_MATCHING
        PATTERN "*.h"
        PATTERN "*.hpp"
)

install(
        DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../ggpo/src/include
        DESTINATION ./
        FILES_MATCHING
        PATTERN "*.h"
        PATTERN "*.hpp"
)

install(
        TARGETS HybridGGPO
        EXPORT hybrid_ggpo
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)

if(MSVC)
    if(BUILD_SHARED_LIBS)
        install(
                FILES $<TARGET_PDB_FILE:HybridGGPO>
                DESTINATION lib
                OPTIONAL
        )
    else()
        ## NOTE: This is rather hacky, since CMake doesn't allow to install the PDB files for
        ##	     static libraries, so we get the debug PDB file and copy it there.
        install(
                FILES "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG}/HybridGGPO.pdb"
                DESTINATION lib
                OPTIONAL
        )
    endif()
else()
    ## TODO place the symbols install when GGPO became cross-platform
endif()