#include <iostream>
#include <SMLib/Video.h>

using namespace sml::video;

int main(int argc, char* argv[])
{

	auto displayList = Display::GetDisplaysList();
	const DisplayPtr display = displayList[0];
	VideoMode mode = display->GetVideoMode();
    std::cout << "width: " << mode.width << std::endl;
	return 0;
}