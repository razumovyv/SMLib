//---------------------- File DisplayImpl.cpp----------------------------------

#include <windows.h>
#include <vector>
#include "..\DisplayImpl.h"


namespace sml { namespace cls{

    //-------------------------------------------------------------------------
    // Returning a vector of active displays atached of desktops
    //-------------------------------------------------------------------------
    std::vector<video::Display> DisplayImpl::GetActiveDesktopDisplays( ){

        //---------------------------------------------------------------------
        // Creating a vector for display instances
        //---------------------------------------------------------------------
        std::vector<video::Display> loadedDisplayList;

        DISPLAY_DEVICE displayInfo;
        ZeroMemory(&displayInfo, sizeof(displayInfo));
        displayInfo.cb = sizeof(displayInfo);

        for(size_t displayCount = 0;
            EnumDisplayDevices( NULL 
                                , displayCount
                                , &displayInfo
                                , 0 );
            displayCount++ ) {

            if((displayInfo.StateFlags & DISPLAY_DEVICE_ATTACHED_TO_DESKTOP)
              &(displayInfo.StateFlags & DISPLAY_DEVICE_ACTIVE)) 
            {

                DISPLAY_DEVICE monitorInfo;
                ZeroMemory(&monitorInfo, sizeof(monitorInfo));
                monitorInfo.cb = sizeof(monitorInfo);

                for (size_t monitorCount = 0;
                    EnumDisplayDevices(displayInfo.DeviceName
                                        , monitorCount
                                        , &monitorInfo
                                        , 0);
                    monitorCount++) {

                    video::Display 
                        sml_display(monitorCount
                                , (const char*)displayInfo.DeviceName
                                , (const char*)displayInfo.DeviceString
                                , (const char*)monitorInfo.DeviceString
                                ,  (displayInfo.StateFlags 
                                  & DISPLAY_DEVICE_PRIMARY_DEVICE) ? true 
                                                                   : false;

                    if(std::find( loadedDisplayList.begin()
                                , loadedDisplayList.end()
                                , sml_display) == loadedDisplayList.end()) 
                    {

                        loadedDisplayList.push_back(sml_display);   
                    
                    }
                }
            }
        }        
            
        return  loadedDisplayList;
    }

    //-------------------------------------------------------------
    // Get primary Display
    //-------------------------------------------------------------
    video::Display DisplayImpl::GetPrimaryDisplay() {

        std::vector<video::Display> displayList; 
        displayList = DisplayImpl::GetActiveDesktopDisplays();

        for(video::Display disp : displayList) {

            if(disp.IsPrimary()) return disp;
        }

        return displayList[0];
    }

    //-------------------------------------------------------------
    // Returning a vector of supported modes for display
    //-------------------------------------------------------------
    std::vector<video::VideoMode> 
    DisplayImpl::GetDisplayModes(const char* displayName) {

        std::vector<video::VideoMode> modes;
        modes.clear();
        DEVMODE modeData;
        ZeroMemory(&modeData, sizeof(modeData));
        for (size_t i = 0; EnumDisplaySettings(displayName, i, &modeData); i++) {

            video::VideoMode mode(modeData.dmPelsWidth
                                , modeData.dmPelsHeight
                                , modeData.dmBitsPerPel
                                , modeData.dmDisplayFrequency);
            if (std::find(modes.begin(), modes.end(), mode) == modes.end())
            {

                modes.push_back(mode);
            }
        }

        return modes;
    }
    
    //------------------------------------------------------------
    // Returning a current desktop mode for selected display
    //------------------------------------------------------------
    video::VideoMode
    DisplayImpl::GetCurrentDesktopMode(const char* displayName) {

        DEVMODE modeData;
        ZeroMemory(&modeData, sizeof(modeData));

        if(!EnumDisplaySettings((LPCSTR)displayName, ENUM_CURRENT_SETTINGS, &modeData))
        {
            //TODO: ERROR LOG
            return {0};
        }
        
        return video::VideoMode mode(modeData.dmPelsWidth
                                    , modeData.dmPelsHeight
                                    , modeData.dmBitsPerPel
                                    , modeData.dmDisplayFrequency);
    }

    //------------------------------------------------------------
    // Seting a video mode to a selected display
    //------------------------------------------------------------
    bool DisplayImpl::SetVideoMode(const char* displayName
                                 , const video::VideoMode& mode
                                 , uint32_t flags)
    {
       DEVMODE dispMode;
       ZeroMemory(&dispMode, sizeof(dispMode));
       dispMode.dmSize = sizeof(dispMode);
       EnumDisplaySettings(displayName, ENUM_CURRENT_SETTINGS, &dispMode);
       dispMode.dmPelsWidth = mode.width;
       dispMode.dmPelsHeight = mode.height;
       dispMode.dmBitsPerPel = mode.bitPerPixel;
       dispMode.dmDisplayFrequency = mode.displayFrecency;
       dispMode.dmFields = (DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT | DM_DISPLAYFREQUENCY);
       return (ChangeDisplaySettingsEx(displayName, &dispMode, NULL, flags ,0) == DISP_CHANGE_SUCCESSFUL); 
    }

    
            
} /* namespace cls*/ } // namespace sml

//------------------- End of file DisplayImpl.cpp -----------------------------
