//--------------------------- File VideoMode.h ------------------------------
#ifndef SML_VIDEO_MODE_H_
#define SML_VIDEO_MODE_H_

//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------
#include <vector>
#include <SMLib/Video/VideoExport.h>

namespace sml
{
    namespace video
    {
        class SML_VIDEO_API VideoMode
        {
            public:
            //-----------------------------------------------------------------
            // Default constructor
            // Initialize member dields to default values
            //
            // m_width           : 640
            // m_height          : 480
            // m_bitPerPixel     : 32
            // m_DisplayFrecancy : 60 Hz
            //-----------------------------------------------------------------
            VideoMode();

            //-----------------------------------------------------------------
            // Custom constructor with parameters
            //-----------------------------------------------------------------
            VideoMode(uint32_t width 
                    , uint32_t height 
                    , uint32_t bitPerPixel = 32 
                    , uint32_t frecency    = 60);

            //-----------------------------------------------------------------
            // Destructor
            //-----------------------------------------------------------------
            ~VideoMode();

            //-----------------------------------------------------------------
            // Returning "true" if the video mode was finded in a list 
            // of supported modes.
            //-----------------------------------------------------------------
             bool isValid() const;

            
            private:
            //-----------------------------------------------------------------
            // Member data
            //-----------------------------------------------------------------
            uint32_t m_Width;           // Displays(windows) width
            uint32_t m_Height;          // Displays(windows) heigth
            uint32_t m_BitPerPixel;     // ColorDepth
            uint32_t m_DisplayFrecency;

        };
    } // namespace video
} // namspace sml
#endif // !SML_VIDEO_MODE_H_
//------------------------ End of file VideoMode.h --------------------------
