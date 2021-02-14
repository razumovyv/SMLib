//---------------------- File DisplayImpl.cpp----------------------------------

#include <windows.h>
#include "..\DisplayImpl.h"


namespace sml { namespace video { namespace cls{

    //-------------------------------------------------------------------------
    // Returning a vector of active displays atached of desktops
    //-------------------------------------------------------------------------
    std::vector< Display > DisplayImpl::GetActiveDesktopDisplays( ){

        //---------------------------------------------------------------------
        // Creating a vector for display instances
        //---------------------------------------------------------------------
        std::vector< Display > displayList;

        DISPLAY_DEVICE dispInfo; // Information about a display
        DISPLAY_DEVICE monInfo;  // Information about a monitor
        ZeroMemory( &dispInfo, sizeof( dispInfo ) );
        dispInfo.cb = sizeof( dispInfo );

        for( size_t dispCount = 0; EnumDisplayDevices( NULL 
                                                    , dispCount
                                                    , &dispInfo
                                                    , 0 ); dispCount++ ) 
        {

            if(( dispInfo.StateFlags & DISPLAY_DEVICE_ATTACHED_TO_DESKTOP )
              &( dispInfo.StateFlags & DISPLAY_DEVICE_ACTIVE )) 
            {

                ZeroMemory( &monInfo, sizeof( monInfo ) );
                monInfo.cb = sizeof( monInfo );

                for ( size_t monCount = 0;
                    EnumDisplayDevices( dispInfo.DeviceName
                                        , monCount
                                        , &monInfo
                                        , 0 ); monCount++ ) 
                {

                    Display disp( ( const char* )dispInfo.DeviceName
                                , ( const char* )dispInfo.DeviceString
                                , ( const char* )monInfo.DeviceString
                                , ( dispInfo.StateFlags 
                                & DISPLAY_DEVICE_PRIMARY_DEVICE) ? true : false );

                    if( std::find( displayList.begin( )
                                , displayList.end( )
                                , disp ) == displayList.end( ) ) 
                    {

                        displayList.push_back( disp );   
                    
                    }
                }
            }
        }        
            
        return  displayList;
    }

    //-------------------------------------------------------------------------
    // Returning a primary display instance
    //-------------------------------------------------------------------------
    Display DisplayImpl::GetPrimaryDisplay( ) {

        DISPLAY_DEVICE dispInfo; // Information about a display
        DISPLAY_DEVICE monInfo;  // Information about a monitor
        ZeroMemory( &dispInfo, sizeof( dispInfo ) );
        dispInfo.cb = sizeof( dispInfo );

        for( size_t i; EnumDisplayDevices( NULL, i, &dispInfo, 0 ); i++ ) {
            
            if( dispInfo.StateFlags & DISPLAY_DEVICE_PRIMARY_DEVICE ) {
                ZeroMemory( &monInfo, sizeof( monInfo ) );
                monInfo.cb = sizeof( monInfo );

                if( !EnumDisplayDevices( dispInfo.DeviceName, 0, &monInfo, 0))
                {
                    return Display();
                }

                return Display(( const char* )dispInfo.DeviceName
                              ,( const char* )dispInfo.DeviceString
                              ,( const char* )monInfo.DeviceString
                              ,true );
            }
        }

        return Display();

    }

    //-------------------------------------------------------------
    // Returning a vector of supported modes for display
    //-------------------------------------------------------------
    std::vector< VideoMode > DisplayImpl::GetListVideoModes( const char* displayName ){

        std::vector<VideoMode> modes;
        modes.clear();
        DEVMODE modeData;
        ZeroMemory(&modeData, sizeof(modeData));
        for (size_t i = 0; EnumDisplaySettings(displayName, i, &modeData); i++)
        {

            VideoMode mode( modeData.dmPelsWidth
                          , modeData.dmPelsHeight
                          , modeData.dmBitsPerPel
                          , modeData.dmDisplayFrequency );
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
    VideoMode DisplayImpl::GetVideoMode(const char* displayName) {

        DEVMODE modeData;
        ZeroMemory(&modeData, sizeof(modeData));

        if(!EnumDisplaySettings(displayName, ENUM_CURRENT_SETTINGS, &modeData))
        {
            //TODO: ERROR LOG
            return VideoMode(0,0,0,0);
        }
        
        return VideoMode(modeData.dmPelsWidth
                       , modeData.dmPelsHeight
                       , modeData.dmBitsPerPel
                       , modeData.dmDisplayFrequency);
    }

    //------------------------------------------------------------
    // Seting a video mode to a selected display
    //------------------------------------------------------------
    bool DisplayImpl::SetVideoMode(const char* displayName
                                 , const VideoMode& mode
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

    
            
} // namespace cls
} // namespace video
} // namespace sml

//------------------- End of file DisplayImpl.cpp -----------------------------
