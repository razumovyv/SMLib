//--------------------- File DisplayImpl.h ------------------------------------
#ifndef SML_DISPLAY_IMPLEMENTATION_H_
#define SML_DISPLAY_IMPLEMENTATION_H_

//-----------------------------------------------------------------------------
//
// TODO Documentation: main title for file
//
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------
#include <vector>
#include <SMLib/Video/Display.h>
#include <SMLib/Video/VideoMode.h>

//-----------------------------------------------------------------------------
// A main library namespace
//-----------------------------------------------------------------------------
namespace sml { 

//-----------------------------------------------------------------------------
// A opened video module namespace
//-----------------------------------------------------------------------------
namespace video { 

//-----------------------------------------------------------------------------
// A closed video module namespace
//-----------------------------------------------------------------------------
namespace cls {
    class DisplayImpl{
        public:
            //---------------------------------------------------------
            // Returning an active display instance
            //
            // TODO Documentation
            //
            //---------------------------------------------------------
            static bool 
            GetDisplayDesktop( const size_t &index, Display* dispInst );          

            //-----------------------------------------------------------------
            // Returning a vector of supported modes for display
            //
            //TODO Documentation
            //
            //-----------------------------------------------------------------
            static std::vector< VideoMode > 
            GetListVideoModes( const char* displayName );

            //-----------------------------------------------------------------
            // Returning a current desktop mode for selected display
            //
            // TODO Documentation
            //
            //-----------------------------------------------------------------
            static bool GetVideoMode( const char* displayName, VideoMode *pMode );

            //-----------------------------------------------------------------
            // Seting a video mode to a selected display
            //
            // TODO Documentation
            //
            //-----------------------------------------------------------------
            static bool SetVideoMode( const char* displayName, 
                                      const VideoMode &mode, 
                                      uint32_t flags );

        
    };
    
} // namespace cls
} // namespace video
} // namespace sml
#endif
//------------------ End of file DisplayImpl.h --------------------------------
