//--------------------------- File DispalyMode.h ------------------------------
#ifndef SML_DISPLAY_MODE_H_
#define SML_DISPLAY_MODE_H_

//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------
#include <vector>
#include <SMLib/config.h>

namespace sml
{
    namespace display
    {
        class SML_API DisplayMode
        {
            public:
            //-----------------------------------------------------------------
            // Default constructor
            // Initialize member dields to default values
            //
            // m_width      : 640
            // m_height     : 480
            // m_bitPerPixel: 32
            //-----------------------------------------------------------------
            DispalyMode();

            //-----------------------------------------------------------------
            // Custom constructor with parameters
            //-----------------------------------------------------------------
            DisplayMode(uint32_t width, uint32_t height, 
                                        uint32_t bitBerPixel = 32);

            //-----------------------------------------------------------------
            // Destructor
            //-----------------------------------------------------------------
            ~DispalyMode();

            //-----------------------------------------------------------------
            // Return vector of supported dispaly modes
            //-----------------------------------------------------------------
            static std::vector<DisplayMode> GetDisplayModes();

            //-----------------------------------------------------------------
            // Get current setings for the primary display
            //-----------------------------------------------------------------
            static DespalyMode GetCurrentDisplayMode();


            private:
            //-----------------------------------------------------------------
            // Member data
            //-----------------------------------------------------------------
            uint32_t m_width;           // Displays(windows) width
            uint32_t m_height;          // Displays(windows) heigth
            uint32_t m_bitPerPixel;     // ColorDepth
            uint32_t m_DispalyFrecency;

        };
    } // namespace dispaly
} // namspace sml
#endif // !SML_DISPLAY_MODE_H_
//------------------------ End of file DispalyMode.h --------------------------
