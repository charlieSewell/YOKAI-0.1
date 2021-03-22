# Add source files.
target_sources(${PROJECT_NAME} PRIVATE
        main.cpp

        Model/ObjectLoading/Mesh.cpp
        Model/ObjectLoading/Model.cpp
        Model/Chunk.cpp

        View/Renderer/AssimpMaths.cpp
        View/Renderer/Shader.cpp
        View/Renderer/DataTypes.cpp
        View/Renderer/Renderer.cpp
        View/Renderer/RenderAPI.cpp
        View/Renderer/OpenGL/OpenGLRenderer.cpp
        View/Renderer/OpenGL/OpenGLDataTypes.cpp
        View/Camera.cpp
        View/Renderer/OpenGL/FileIO.cpp

        Controller/Yokai.cpp
        Controller/ModelManager.cpp
        Controller/TerrainManager.cpp
        Controller/Factory/TerrainFactory.cpp
        Controller/Physics/PhysicsManager.cpp
        )

# Include project header files.
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
