#ifndef _AISCRIPT_LUA_H__
#define _AISCRIPT_LUA_H__

struct lua_State;
class CNtlLuaState;
class CServerAIScript;
class CControlScriptNode;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CNtlLuaState* GetAISLuaState(void);

void	AISLua_CreateState(void);

void	AISLua_Setup(void);
void	AISLua_Release(void);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
extern CServerAIScript* s_pCurScript;
extern CControlScriptNode* s_pCurNode;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


extern "C" {


	int luabind_AIScript_Scene(lua_State *L);
	int luabind_AIScript_State(lua_State *L);
	int luabind_AIScript_Action(lua_State *L);
	int luabind_AIScript_Condition(lua_State *L);
	int luabind_AIScript_Param(lua_State *L);
	int luabind_AIScript_End(lua_State *L);



}



#endif
