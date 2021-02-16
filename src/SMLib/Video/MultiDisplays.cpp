//------------------------------ File DisplayAccess.cpp -----------------------

#include <SMLib/Video/MultiDisplays.h>
#include "DisplayImpl.h"

namespace sml { 

namespace video {

    //-------------------------------------------------------------------------
    // Default constructor
    //-------------------------------------------------------------------------
    MultiDisplay::MultiDisplay( )
    { 
        
    }

    //-------------------------------------------------------------------------
    // Destructor
    //-------------------------------------------------------------------------
    MultiDisplay::~MultiDisplay() { 
        displays_.clear();
    }

    void MultiDisplay::ClearDisplayInstances()
    {
        displays_.clear();
    }

    //-------------------------------------------------------------------------
    // Factory function for returning singleton
    //-------------------------------------------------------------------------
    MultiDisplay* MultiDisplay::GetMultiDisplays( const bool useMultidisplay )
    {
        static MultiDisplay multiDisplaysInstance;
        
        multiDisplaysInstance.ClearDisplayInstances();
        Display display;

        switch (useMultidisplay)
        {
        case SML_MD_DESKTOP_DISPLAYS:
            for( uint32_t i = 0; 
                 cls::DisplayImpl::GetDisplayDesktop( i, &display ); 
                 i++ )
            {
                multiDisplaysInstance.RegInstance(i, display);
            }
            break;
        default:
            cls::DisplayImpl::GetDisplayDesktop(0, &display);
            multiDisplaysInstance.RegInstance(0, display);
            break;
        }
        
        return &multiDisplaysInstance;
    }

    //-------------------------------------------------------------------------
    // Returnin nuber of display instances
    //-------------------------------------------------------------------------
    size_t MultiDisplay::GetNumberDisplays()
    {
        return numberInstances_;
    }
    //-----------------------------------------------------------------
    // Adding a display instance to a container
    //-----------------------------------------------------------------
    void 
    MultiDisplay::RegInstance( const uint32_t &index, const Display &regInst ) 
    { 
        displays_.insert(std::pair<uint32_t, Display>(index, regDisp));
        numberInstances++;
    }

    //-----------------------------------------------------------------
    // Returning a reference to a display instance
    //-----------------------------------------------------------------
    Display& MultiDisplay::GetDisplayRef( const uint32_t &index ) const 
    {
        return displays_[index];
    }

} // namespace video
} // namespace sml
//--------------------------- End of file DisplayAccess.cpp -------------------
