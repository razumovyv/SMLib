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
            
            
            return displayList;
        }
            
    } // namespace cls
} // namespace sml

//------------------- End of file Win32DisplayImpl.cpp------------------------
