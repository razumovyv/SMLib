//--------------------- File DisplayImpl.h ------------------------------------
#ifndef SML_DISPLAY_IMPLEMENTATION_H_
#define SML_DISPLAY_IMPLEMENTATION_H_

#include <vector>
#include <SMLib/Video/Display.h>
#include <SMLib/Video/VideoMode.h>
namespace sml { namespace video { namespace cls {

    class DisplayImpl{

        protected:
            friend class Display;
            //-----------------------------------------------------------------
            // Returning a vector of active displays atached of desktops
            //-----------------------------------------------------------------
            static std::vector< Display > GetActiveDesktopDisplays( );

            //-----------------------------------------------------------------
            // Returning a primary display
            //-----------------------------------------------------------------
            static Display GetPrimaryDisplay( );           

            //-----------------------------------------------------------------
            // Returning a vector of supported modes for display
            //-----------------------------------------------------------------
            static std::vector< VideoMode > GetListVideoModes( const char* displayName );

            //-----------------------------------------------------------------
            // Returning a current desktop mode for selected display
            //-----------------------------------------------------------------
            static VideoMode GetVideoMode( const char* displayName );

            //-----------------------------------------------------------------
            // Seting a video mode to a selected display
            //-----------------------------------------------------------------
            static bool SetVideoMode( const char* displayName
                                    , const VideoMode& mode
                                    , uint32_t flags );

        
    };
    
} // namespace cls
} // namespace video
} // namespace sml
#endif
//------------------ End of file DisplayImpl.h -------------------------
