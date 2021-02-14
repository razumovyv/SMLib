//-------------------------- File Display.cpp ---------------------------------

#include <SMLib/Video/Display.h>
#include "DisplayImpl.h"

namespace sml {  namespace video {

    //---------------------------------------------------------------------
    // Default constructor
    //
    // TODO: Documentations
    //
    //---------------------------------------------------------------------
    Display::Display(){ 

        *(this) = cls::DisplayImpl::GetPrimaryDisplay();
        listModes_ = cls::DisplayImpl::GetListVideoModes(name_.c_str());
   
    }

    //---------------------------------------------------------------------
    // Base constructor
    //
    // TODO: Documentations
    //
    //---------------------------------------------------------------------
    Display::Display( const char* displayName 
                    , const char* adapterDesc
                    , const char* monitorDesc
                    , const bool isPrimary) 
                    : name_         ( displayName )
                    , adapterDesc_  ( adapterDesc )
                    , monitorDesc_  ( monitorDesc )
                    , isPrimary_    ( isPrimary ) 
    { 
        listModes_ = cls::DisplayImpl::GetListVideoModes(name_.c_str());
    }

    Display::~Display() {listModes_.clear(); }

    //---------------------------------------------------------------------
    // Returning a vector of active displays
    //
    // TODO: Documentations
    //
    //---------------------------------------------------------------------
    std::vector<Display> Display::GetActiveDesktopDispalys() {

        return cls::DisplayImpl::GetActiveDesktopDisplays();
    }

    //-----------------------------------------------------------------
    // Returning a supported video modes list
    //
    // TODO: Documentations
    //
    //-----------------------------------------------------------------
    std::vector< VideoMode> Display::GetListVideoModes( ) const {

        return listModes_;
    }   

    //---------------------------------------------------------------------
    // Returning a current settings for instance
    //
    // TODO: Documentations
    //
    //---------------------------------------------------------------------
    VideoMode Display::GetVideoMode( ) const {

        return cls::DisplayImpl::GetVideoMode( name_.c_str() );
    }

    //-------------------------------------------------------------
    // Setting up a custom mode for this display
    //
    // TODO: Documentations
    //
    //-------------------------------------------------------------
    bool Display::SetVideoMode( const VideoMode& mode, uint32_t flags ) {

        if( !IsValidMode(mode) ) return false;
        
        return cls::DisplayImpl::SetVideoMode( name_.c_str(), mode, flags );
    }

    //-------------------------------------------------------------
    // Checking a selected mode
    //
    // TODO: Documentations
    //
    //-------------------------------------------------------------
    bool Display::IsValidMode( const VideoMode& mode ) const {

        return cls::DisplayImpl::SetVideoMode( name_.c_str(), mode, SML_VM_TEST );
    }

    // TODO: Description
    // TODO: Documentation
    bool Display::IsPrimary() const {
        
        return isPrimary_;
    }

    bool operator==( const Display& left, const Display& right ) {
        
        return (( left.name_        == right.name_        )
              &&( left.adapterDesc_ == right.adapterDesc_ )
              &&( left.monitorDesc_ == right.monitorDesc_ )
              &&( left.isPrimary_   == right.isPrimary_   ));
    }
    bool operator!=( const Display& left, const Display& right ) {
    
        return !( ( left.name_        == right.name_        )
                &&( left.adapterDesc_ == right.adapterDesc_ )
                &&( left.monitorDesc_ == right.monitorDesc_ )
                &&( left.isPrimary_   == right.isPrimary_   ));
    }
} // namespace video
} // namespace sml
//------------------------End of file Display.cpp -----------------------------