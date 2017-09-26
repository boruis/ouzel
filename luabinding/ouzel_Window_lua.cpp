
#include "ouzel_Window_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_window(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::Window>();

	//PublicFunc
	metaTable.addFunction("close", &ouzel::Window::close);
	metaTable.addFunction("getSize", &ouzel::Window::getSize);
	metaTable.addFunction("setSize", &ouzel::Window::setSize);
	metaTable.addFunction("getResolution", &ouzel::Window::getResolution);
	metaTable.addFunction("getResizable", &ouzel::Window::getResizable);
	metaTable.addFunction("setFullscreen", &ouzel::Window::setFullscreen);
	metaTable.addFunction("isFullscreen", &ouzel::Window::isFullscreen);
	metaTable.addFunction("isExclusiveFullscreen", &ouzel::Window::isExclusiveFullscreen);
	metaTable.addFunction("getTitle", &ouzel::Window::getTitle);
	metaTable.addFunction("setTitle", &ouzel::Window::setTitle);
	metaTable.addFunction("convertWindowToNormalizedLocation", &ouzel::Window::convertWindowToNormalizedLocation);
	metaTable.addFunction("convertWindowToNormalizedLocationRelative", &ouzel::Window::convertWindowToNormalizedLocationRelative);
	metaTable.addFunction("convertNormalizedToWindowLocation", &ouzel::Window::convertNormalizedToWindowLocation);
	metaTable.addFunction("convertNormalizedToWindowLocationRelative", &ouzel::Window::convertNormalizedToWindowLocationRelative);

	state["oz"]["Window"].setClass(metaTable);
}
