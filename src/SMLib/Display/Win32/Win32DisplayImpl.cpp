//---------------------- File Win32DisplayImpl.cpp----------------------------

#include <windows.h>
#include <vector>

namespace sml{
    namespace display{
        class Display;
    }
    namespace cls{
        std::vector<dispaly::Display> GetDisplayListFromSystem(){
            
            std::vector<display::Display> displayList;
            DISPLAY_DEVICE displayInfo;
            ZeroMemory(displayInfo&, sizeof(displayInfo));
            
            displayInfo.cb = sizeof(displayInfo);

            for(int i = 0; EnumDisplayDevices(NULL, i, displayInfo, 0), i++)
            {
                displayList.push_back(display::Display(i, &displayInfo.DeviceName, &displayInfo.DeviceString))
            }
            
            
            return displayList;
        }
            
    } // namespace cls
} // namespace sml

//------------------- End of file Win32DisplayImpl.cpp------------------------
