file(GLOB_RECURSE HEADER_FILES *.h serialization/*.h)
AUX_SOURCE_DIRECTORY(. SOURCE_FILES)


if(WIN32)
elseif(UNIX)
    set(EXCLUDE_FILES ./HLSLCodeProcessing.cpp ./HLSLShaderPackFile.h)
endif()

list(REMOVE_ITEM SOURCE_FILES ${EXCLUDE_FILES})


find_package(Qt5Widgets REQUIRED)

qt5_add_resources(SHADER_LAB_RCC_SRC Resources/resources.qrc)

include_directories(../CommonSystem ../RendererAbstract/include ../PlatformAbstraction/include ../GUI_Library ../GlobalServices/include ../external_local/glslang)

add_library(ApproxShaderLab SHARED ${SOURCE_FILES} ${HEADER_FILES} ${SHADER_LAB_RCC_SRC})

set(LINK_LIBRARIES
        Qt5::Widgets
        ApproxGUILibrary
        ApproxGlobalServices
        glslang
        SPIRV
        HLSL
        OGLCompiler
        OSDependent)

if(WIN32)
    target_link_libraries(ApproxShaderLab ${LINK_LIBRARIES})
    add_definitions(-D__D3D11__)
    add_definitions(-D__VULKAN__)
elseif(UNIX)
    target_link_libraries(ApproxShaderLab ${LINK_LIBRARIES})
    add_definitions(-D__VULKAN__)
endif()