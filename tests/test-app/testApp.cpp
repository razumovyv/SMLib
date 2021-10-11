#include <iostream>
#include <SMLib/Video.h>

using namespace sml::video;

int main(int argc, char* argv[])
{
  const DisplayContainer& displays = DisplayContainer::Create();
  PDisplay display_1 = displays[0];
  PDisplay display_2 = displays[1];

  VideoMode modeDisplay_1 = display_1->GetVideoMode();
  VideoMode modeDisplay_2 = display_2->GetVideoMode();

  std::cout << "Num of Displays:>>" << displays.Size() << std::endl;

  std::cout << "Display 1: >>" << display_1->GetMonitorDescription()
            << std::endl;
  std::cout << "Display 1 Adapter: >>" << display_1->GetAdapterDescription()
            << std::endl;
  std::cout << "Display 1 Mode:>>" << modeDisplay_1.width << "x"
            << modeDisplay_1.height
            << " BitPerPixel =" << modeDisplay_1.bitPerPixel << ", "
            << modeDisplay_1.displayFrecency << " Hz" << std::endl;

  std::cout << "Display 2: >>" << display_2->GetMonitorDescription()
            << std::endl;
  std::cout << "Display 2 Adapter: >>" << display_2->GetAdapterDescription()
            << std::endl;
  std::cout << "Display 2 Mode:>>" << modeDisplay_2.width << "x"
            << modeDisplay_2.height
            << " BitPerPixel =" << modeDisplay_2.bitPerPixel << ", "
            << modeDisplay_2.displayFrecency << " Hz" << std::endl;
  return 0;
}