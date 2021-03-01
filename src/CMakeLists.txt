# Add source files.
target_sources(${PROJECT_NAME} PRIVATE
        main.cpp

        Renderer/Shader.cpp
        Renderer/Camera.cpp
        Renderer/OpenGL.cpp


        Model/ObjectLoading/Mesh.cpp
        Model/ObjectLoading/Model.cpp
        Model/ModelManager.cpp


)

# Include project header files.
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})