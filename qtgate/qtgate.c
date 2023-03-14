#include "qtgate.h"
#include "wrapper.h"

#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
    #define DLL_PUBLIC __declspec(dllexport)
#else
    #define DLL_PUBLIC
#endif

static int init(lua_State *L)
{    
    struct CustomQtLib* ab = newInstance();
    CustomQtLib_init(ab);
    lua_pushlightuserdata(L, (void *)ab);
    return 1;
}

static int get_qt_version(lua_State *L) {
      CustomQtLib* ab = (CustomQtLib *)lua_touserdata(L, 1);
      lua_pushstring(L, CustomQtLib_get_version(ab));
      return 1;
}

static int get_meta_info(lua_State *L) {
      CustomQtLib* ab = (CustomQtLib *)lua_touserdata(L, 1);
      MetaInfoContainer meta_info = CustomQtLib_get_meta_info(ab);

      lua_createtable(L, 0, 2);

      lua_pushinteger(L, meta_info.db_version);
      lua_setfield(L, -2, "db_v");

      lua_pushstring(L, meta_info.description);
      lua_setfield(L, -2, "desc");

      return 1;
}

DLL_PUBLIC int luaopen_qtgate(lua_State *L)
{
    static const luaL_reg Map [] = {{"init", init},
                                    {"get_qt_version", get_qt_version},
                                    {"get_meta_info", get_meta_info},
                                    {NULL,NULL}};
    luaL_register(L, "qtgate", Map);
    return 1;
}
