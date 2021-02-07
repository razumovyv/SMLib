//------------------ File DisplayMode.cpp -------------------------------------

//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------
#include <SMLib/Video/VideoMode.h>

namespace sml
{
    namespace video
    {
        //---------------------------------------------------------------------
        // Default constructor
        //---------------------------------------------------------------------
        VideoMode::VideoMode() 
                    : m_Width(640) 
                    , m_Height(480) 
                    , m_BitPerPixel(32)
                    , m_DisplayFrecency(60)
        {

        }

        //---------------------------------------------------------------------
        // Custom constructor
        //---------------------------------------------------------------------
        VideoMode::VideoMode( uint32_t width 
                            , uint32_t height 
                            , uint32_t bitPerPixel
                            , uint32_t frecancy) 
                            : m_Width(width) 
                            , m_Height(height) 
                            , m_BitPerPixel(bitPerPixel)
                            , m_DisplayFrecency(frecancy)
        {

        }

        //---------------------------------------------------------------------
        // Destructor
        //---------------------------------------------------------------------
        VideoMode::~VideoMode()
        {

        }

    } // namespace video
} // namspace sml
//--------------- End of file DisplayMode.cpp ---------------------------------