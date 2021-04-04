# Add source files.
target_sources(${PROJECT_NAME} PRIVATE
        main.cpp

		Model/ObjectLoading/ModelLoader.cpp
		Model/Mesh.cpp
        Model/Model.cpp
        Model/Chunk.cpp
		Model/GameObject.cpp
		Model/PlayerControlledMotion.cpp
		Model/Player.cpp
        Model/StaticObject.cpp
        Model/NPC.cpp

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
		Controller/LuaManager.cpp
		Controller/EventManager.cpp
		Controller/InputManagerGLFW.cpp
		Controller/Layer.cpp
		Controller/GameStack.cpp
        Controller/Factory/GameAssetFactory.cpp
        )

# Include project header files.
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
