//--------------------- File DisplayImpl.h ------------------------------------
#ifndef SML_DISPLAY_IMPLEMENTATION_H_
#define SML_DISPLAY_IMPLEMENTATION_H_

#include <vector>
#include <SMLib/Video/Display.h>
#include <SMLib/Video/VideoMode.h>
namespace sml { 

    namespace cls {

        class DisplayImpl{

            public:
                //-------------------------------------------------------------
                // Default constructor
                //-------------------------------------------------------------
                DisplayImpl( ) {};

                //-------------------------------------------------------------
                // Destructor
                //-------------------------------------------------------------
                 ~DisplayImpl( ) {};
                
                //-------------------------------------------------------------
                // Returning a vector of active displays atached of desktops
                //-------------------------------------------------------------
                static std::vector<video::Display> 
                GetActiveDesktopDisplays( );


                
                //-------------------------------------------------------------
                // Get primary Display
                //-------------------------------------------------------------
                static Display GetPrimaryDisplay();

                //-------------------------------------------------------------
                // Returning a vector of supported modes for display
                //-------------------------------------------------------------
                 static std::vector<video::VideoMode> 
                 GetDisplayModes(const char* displayName);

                 //------------------------------------------------------------
                 // Returning a current desktop mode for selected display
                 //------------------------------------------------------------
                 static video::VideoMode
                 GetCurrentDesktopMode(const char* displayName);

                 //------------------------------------------------------------
                 // Seting a video mode to a selected display
                 //------------------------------------------------------------
                 static bool SetVideoMode(const char* displayName
                                        , const VideoMode& mode
                                        , uint32_t flags);

            
        };
    } // namespace cls
} // namespace sml
#endif
//------------------ End of file DisplayImpl.h -------------------------
