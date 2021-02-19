//------------------ File DisplayMode.cpp -------------------------------------

//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------
#include <SMLib/Video/VideoMode.h>

namespace sml {

    namespace video {

        //---------------------------------------------------------------------
        // Default constructor
        //---------------------------------------------------------------------
        VideoMode::VideoMode() 
        : width           ( 640 ),
          height          ( 480 ), 
          bitPerPixel     ( 32 ),
          displayFrecency ( 60 ) { }

        //---------------------------------------------------------------------
        // Custom constructor
        //---------------------------------------------------------------------
        VideoMode::VideoMode( uint32_t width, 
                              uint32_t height, 
                              uint32_t bitPerPixel,
                              uint32_t frecancy) 
        : width           ( width ), 
          height          ( height ), 
          bitPerPixel     ( bitPerPixel ),
          displayFrecency ( frecancy ) { }

        bool operator ==(const VideoMode& left, const VideoMode& right)
            {
                return ((left.width == right.width) &&
                        (left.height == right.height) &&
                        (left.bitPerPixel == right.bitPerPixel) &&
                        (left.displayFrecency == right.displayFrecency));
            }

        bool operator !=(const VideoMode& left, const VideoMode& right)
            {
                return !((left.width == right.width) &&
                         (left.height == right.height) &&
                         (left.bitPerPixel == right.bitPerPixel) &&
                         (left.displayFrecency == right.displayFrecency));
            }

    } // namespace video
} // namspace sml
//--------------- End of file DisplayMode.cpp ---------------------------------