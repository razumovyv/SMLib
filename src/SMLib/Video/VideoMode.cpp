//------------------ File DisplayMode.cpp -------------------------------------

//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------
#include <SMLib/Video/VideoMode.h>

namespace sml
{
    //-------------------------------------------------------------------------
    // Default constructor
    //-------------------------------------------------------------------------
    DisplayMode::DisplayMode() : m_width(640), 
                                 m_height(480), 
                                 m_bitPerPixel(32),
                                 m_DisplayFrecency(60)
    {

    }

    //-------------------------------------------------------------------------
    // Custom constructor
    //-------------------------------------------------------------------------
    DisplayMode::DisplayMode( uint32_t width, 
                              uint32_t height, 
                              uint32_t bitPerPixel,
                              uint32_t frecancy) :
                              m_width(width), 
                              m_height(height), 
                              m_bitPerPixel(bitPerPixel),
                              m_DisplayFrecency(frecancy)
    {

    }
    //-------------------------------------------------------------------------
    // Destructor
    //-------------------------------------------------------------------------
    DisplayMode::~DisplayMode()
    {

    }

} // namspace sml
//--------------- End of file DisplayMode.cpp ---------------------------------