//--------------------------- File VideoMode.h -------------------------------
#ifndef SML_VIDEO_MODE_H_
#define SML_VIDEO_MODE_H_

//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------
#include <SMLib/Video/Export.h>

namespace sml
{
    namespace video
    {
        struct SML_VIDEO_API VideoMode
        {
                //-----------------------------------------------------------------
                // Default constructor
                // Initialize member dields to default values
                //
                // m_width           : 640
                // m_height          : 480
                // m_bitPerPixel     : 32
                // m_DisplayFrecancy : 60 Hz
                //-----------------------------------------------------------------
                VideoMode( );

                //-----------------------------------------------------------------
                // Custom constructor with parameters
                //-----------------------------------------------------------------
                VideoMode( uint32_t width 
                         , uint32_t height 
                         , uint32_t bitPerPixel = 32 
                         , uint32_t frecency    = 60 );

                //-----------------------------------------------------------------
                // Member data
                //-----------------------------------------------------------------
                uint32_t width;           
                uint32_t height;          
                uint32_t bitPerPixel;     
                uint32_t displayFrecency;

        };
    } // namespace video
} // namspace sml
#endif // !SML_VIDEO_MODE_H_
//------------------------ End of file VideoMode.h ---------------------------
