// Lua Manager hpp
// Vladislav Kennebury 11/03/2021
// Version 1

#pragma once

/// Dependecies
#include <lua.hpp>
#include <LuaBridge/LuaBridge.h>
#include <iostream>

/**
 * @class LuaManager
 * @brief Responsible for managing lua scripts
 */
class LuaManager
{
	public: 
        /*!
         * @brief Singleton Pattern for a single instance of the class
         * @return instance
         */
        static LuaManager &getInstance();

        /*!
         * @brief Getter for the lua state
         * @return lua_state
         */
        lua_State *getState();

        /*!
         * @brief Runs the specified lua script
         * @param string - scriptName
         */
        static void runScript(std::string scriptName);

	private:
        /*!
         * @brief Constructor
         */
        LuaManager();

        /*!
         * @brief Deconstructor
         */
        ~LuaManager();

        /// Lua state
        lua_State *L = nullptr;
};