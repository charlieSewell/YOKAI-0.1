//
// Created by charl on 5/04/2021.
//

#ifndef ICT397_GAME_ENGINE_LUATYPES_HPP
#define ICT397_GAME_ENGINE_LUATYPES_HPP
#include "Controller/LuaManager.hpp"
#include "Model/GameObjects/GameObject.hpp"
namespace LuaTypes {
    GameObjectType getNPCType();
    GameObjectType getStaticType();
    GameObjectType getPlayerType();
};
//Wrapper found online to make Enums work in Lua
//https://github.com/vinniefalco/LuaBridge/blob/baba8b6a95a7aa92996e86a0846750aac9a57274/Tests/Source/IssueTests.cpp#L147
template <typename T>
struct EnumWrapper
{
    static typename std::enable_if<std::is_enum<T>::value, void>::type push(lua_State* L, T value)
    {
        lua_pushnumber (L, static_cast<std::size_t> (value));
    }

    static typename std::enable_if<std::is_enum<T>::value, T>::type get(lua_State* L, int index)
    {
        return static_cast <T> (lua_tointeger (L, index));
    }
};

namespace luabridge {

    template <>
    struct luabridge::Stack <GameObjectType> : EnumWrapper <GameObjectType>
    {

    };
}
#endif // ICT397_GAME_ENGINE_LUATYPES_HPP
