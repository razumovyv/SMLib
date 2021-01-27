//--------------------------- File DisplayMode.h ------------------------------
#ifndef SML_DISPLAY_MODE_H_
#define SML_DISPLAY_MODE_H_

//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------
#include <vector>
#include <SMLib/config.h>

namespace sml
{
    namespace video
    {
        class SML_API DisplayMode
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
            DisplayMode();

            //-----------------------------------------------------------------
            // Custom constructor with parameters
            //-----------------------------------------------------------------
            DisplayMode(uint32_t width, uint32_t height, 
                                        uint32_t bitPerPixel = 32, 
                                        uint32_t frecency    = 60);

            //-----------------------------------------------------------------
            // Destructor
            //-----------------------------------------------------------------
            ~DisplayMode();

            //-----------------------------------------------------------------
            // Get current setings for the primary display
            //-----------------------------------------------------------------
            static DisplayMode GetCurrentDisplayMode() const;


            private:
            //-----------------------------------------------------------------
            // Member data
            //-----------------------------------------------------------------
            uint32_t m_width;           // Displays(windows) width
            uint32_t m_height;          // Displays(windows) heigth
            uint32_t m_bitPerPixel;     // ColorDepth
            uint32_t m_DisplayFrecency;

        };
    } // namespace display
} // namspace sml
#endif // !SML_DISPLAY_MODE_H_
//------------------------ End of file DisplayMode.h --------------------------
