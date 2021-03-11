// Lua Manager hpp
// Vladislav Kennebury 11/03/2021
// Version 1

#include <lua.hpp>
#include <iostream>

class LuaManager
{
	public: 
        static LuaManager &getInstance()
        {
            static LuaManager instance;
            return instance;
        }

        lua_State *getState();
        static void runScript(std::string &scriptName);

	private:
        LuaManager();
        ~LuaManager();
        lua_State *L = nullptr;
};