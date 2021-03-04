# Add source files.
target_sources(${PROJECT_NAME} PRIVATE
        main.cpp

        Model/ObjectLoading/Mesh.cpp
        Model/ObjectLoading/Model.cpp
        Model/Chunk.cpp

        View/Renderer/AssimpMaths.cpp
        View/Renderer/Shader.cpp
        View/Camera.cpp
        View/Renderer/OpenGL.cpp

        Controller/Yokai.cpp
        Controller/ModelManager.cpp
        Controller/TerrainGenerator.cpp
        Controller/Factory/TerrainFactory.cpp
        )

# Include project header files.
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})