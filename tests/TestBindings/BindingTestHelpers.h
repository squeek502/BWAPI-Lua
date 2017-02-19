#pragma once

#include <string>
#include <sstream>

namespace BWAPI_Lua
{
	namespace TestBindings
	{
		const char pathSeparator =
#ifdef _WIN32
			'\\';
#else
			'/';
#endif

		inline std::string getLuaTestPath(const char* fileName)
		{
			char drive[FILENAME_MAX + 1];
			char dir[FILENAME_MAX + 1];
			char file[FILENAME_MAX + 1];
			_splitpath_s(fileName, drive, FILENAME_MAX, dir, FILENAME_MAX, file, FILENAME_MAX, NULL, 0);
			std::stringstream ss;
			ss << drive << dir << "Lua" << BWAPI_Lua::TestBindings::pathSeparator << file << ".lua";
			return ss.str();
		}
	}
}