# Add source files.
target_sources(${PROJECT_NAME} PRIVATE
        main.cpp
		    Model/ObjectLoading/ModelLoader.cpp
	     	Model/Mesh.cpp
        Model/Model.cpp
        Model/Chunk.cpp
		Model/GameObjects/GameObject.cpp
        Model/Components/PlayerControlledMotion.cpp
		    Model/Player.cpp
		Model/GameObjects/StaticObject.cpp
		Model/GameObjects/NPC.cpp

        View/Renderer/AssimpMaths.cpp
        View/Renderer/Shader.cpp
        View/Renderer/DataTypes.cpp
        View/Renderer/Renderer.cpp
        View/Renderer/RenderAPI.cpp
        View/Renderer/OpenGL/OpenGLRenderer.cpp
        View/Renderer/OpenGL/OpenGLDataTypes.cpp
		Model/Components/Camera.cpp
        View/Renderer/OpenGL/FileIO.cpp
		View/Window.cpp
        Controller/Yokai.cpp
        Controller/ModelManager.cpp
        Controller/TerrainManager.cpp
        	Controller/Factory/TerrainFactory.cpp
		    Controller/LuaManager.cpp
		    Controller/EventManager.cpp
		    Controller/InputManagerGLFW.cpp
		    Controller/Layer.cpp
        Controller/Physics/PhysicsManager.cpp
		Model/Components/PhysicsComponent.cpp
		    Controller/Physics/AABB.cpp
        Controller/Factory/GameAssetFactory.cpp
		    Controller/DemoScene.cpp
        Controller/GameObjectManager.cpp
		Controller/LuaTypes.cpp
        )

# Include project header files.
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
