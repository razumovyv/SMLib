//---------------------- File DisplayImpl.cpp----------------------------------

#include <SMLib/Display/DisplayImpl.h>
#include <windows.h>
#include <vector>

namespace sml { namespace cls{

    std::vector<video::Display> DisplayImpl::GetDisplayListFromSystem(){
            
        std::vector<video::Display> loadedDisplayList;

        DISPLAY_DEVICE displayInfo;
        ZeroMemory(&displayInfo, sizeof(displayInfo));
        displayInfo.cb = sizeof(displayInfo);

        for(int index = 0; EnumDisplayDevices(NULL, index, &displayInfo, 0); index++)
        {
                
            if(displayInfo.StateFlags & DISPLAY_DEVICE_ACTIVE)
            {
            Display sml_display(i, 
                               (const char*)displayInfo.DeviceName, 
                               (const char*)displayInfo.DeviceString, 
                               (displayInfo.StateFlags & 
                                DISPLAY_DEVICE_PRIMARY_DEVICE) ? true : false);
                
            displayList.push_back(sml_display);
            }

        }        
            
        return  loadedDisplayList;
    }
            
} /* namespace cls*/ } // namespace sml

//------------------- End of file DisplayImpl.cpp -----------------------------
