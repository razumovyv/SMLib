//------------------------------ File DisplayAccess.cpp -----------------------

#include <SMLib/Video/MultiDisplay.h>
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
    MultiDisplay::~MultiDisplay() 
    { 
        ClearDisplayInstances();
    }
    
    //-----------------------------------------------------------------
    // Clear container with displays
    //-----------------------------------------------------------------
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
                multiDisplaysInstance.RegInstance( display );
            }
            break;
        default:
            cls::DisplayImpl::GetDisplayDesktop( 0, &display );
            multiDisplaysInstance.RegInstance( display );
            break;
        }
        
        return &multiDisplaysInstance;
    }

    //-------------------------------------------------------------------------
    // Returnin nuber of display instances
    //-------------------------------------------------------------------------
    size_t MultiDisplay::GetNumberDisplays() const
    {
        return this->displays_.size();
    }
    //-----------------------------------------------------------------
    // Adding a display instance to a container
    //-----------------------------------------------------------------
    void 
    MultiDisplay::RegInstance( const Display &regInst ) 
    { 
        displays_.emplace_back( regInst );
    }

    //-----------------------------------------------------------------
    // Returning a reference to a display instance
    //-----------------------------------------------------------------
    Display MultiDisplay::GetDisplayRef( const uint32_t& index ) const
    {
        return displays_[index];
    }

} // namespace video
} // namespace sml
//--------------------------- End of file DisplayAccess.cpp -------------------
