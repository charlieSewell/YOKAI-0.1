# Add source files.
target_sources(${PROJECT_NAME} PRIVATE
        main.cpp

        ECS/EntityManager.cpp

        Renderer/Shader.cpp
        ObjectLoading/Mesh.cpp
        ObjectLoading/Model.cpp
        ObjectLoading/ModelManager.cpp

)

# Include project header files.
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})