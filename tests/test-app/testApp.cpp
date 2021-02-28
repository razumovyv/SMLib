#include <iostream>
#include <SMLib/Video.h>

using namespace sml::video;

int main(int argc, char* argv[])
{
  const DisplayContainer& displays = DisplayContainer::Create();
  PDisplay display = displays[0];
  const PDisplay& display_2 = displays[0];
  VideoMode mode = display_2->GetVideoMode();


  std::cout << mode.width << "x" << mode.height << std::endl;
  std::cin.get();
  return 0;
}