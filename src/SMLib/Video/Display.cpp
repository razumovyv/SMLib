//-------------------------- File Display.cpp ---------------------------------
#include <tuple>
#include <SMLib/Video/Display.h>
#include "DisplayImpl.h"

namespace sml {  namespace video {

    //---------------------------------------------------------------------
    // Default constructor
    //
    // TODO: Documentations
    //
    //---------------------------------------------------------------------
    Display::Display() : 
    name_               ("none"),
    adapterDescription_ ("none"),
    monitorDescription_ ("none"),
    isPrimary_          (false) { }

    //---------------------------------------------------------------------
    // Base constructor
    //
    // TODO: Documentations
    //
    //---------------------------------------------------------------------
    Display::Display( const std::string &name, 
                      const std::string &adapterDescription, 
                      const std::string &monitorDescription, 
                      const bool        isPrimary ) : 
                      name_               ( name ), 
                      adapterDescription_ ( adapterDescription ), 
                      monitorDescription_ ( monitorDescription ), 
                      isPrimary_          ( isPrimary   ) { }

    Display::~Display() { }

    //-----------------------------------------------------------------
    // Returning a supported video modes list
    //
    // TODO: Documentations
    //
    //-----------------------------------------------------------------
    std::vector< VideoMode> Display::GetListVideoModes( ) const 
    {

        return cls::DisplayImpl::GetListVideoModes( name_.c_str( ) );
    }   

    //---------------------------------------------------------------------
    // Returning a current settings for instance
    //
    // TODO: Documentations
    //
    //---------------------------------------------------------------------
    VideoMode Display::GetVideoMode( ) const 
    {

        return cls::DisplayImpl::GetVideoMode( name_.c_str( ) );
        
    }

    //-------------------------------------------------------------
    // Setting up a custom mode for this display
    //
    // TODO: Documentations
    //
    //-------------------------------------------------------------
    bool Display::SetVideoMode( const VideoMode& videoMode, uint32_t flags ) const
    {

        if( !IsValidMode( videoMode ) ) return false;
        
        return cls::DisplayImpl::SetVideoMode( name_.c_str( ), videoMode, flags );
    }

    //-------------------------------------------------------------
    // Checking a selected mode
    //
    // TODO: Documentations
    //
    //-------------------------------------------------------------
    bool Display::IsValidMode( const VideoMode& videoMode ) const 
    {

        return cls::DisplayImpl::SetVideoMode( name_.c_str(), 
                                               videoMode, 
                                               SML_VM_TEST );
    }

    // TODO: Description
    // TODO: Documentation
    bool Display::IsPrimary( ) const 
    {
        
        return isPrimary_;
    }

    bool operator ==( const Display& left, const Display& right ) 
    {
        auto _left = std::tie( left.name_,
                               left.adapterDescription_,
                               left.monitorDescription_,
                               left.isPrimary_ );

        auto _right = std::tie( right.name_,
                                right.adapterDescription_,
                                right.monitorDescription_,
                                right.isPrimary_ );

        return (_left == _right);
    }

    bool operator !=( const Display& left, const Display& right ) 
    {
        auto _left = std::tie( left.name_,
                            left.adapterDescription_,
                            left.monitorDescription_,
                            left.isPrimary_ );

        auto _right = std::tie( right.name_,
                                right.adapterDescription_,
                                right.monitorDescription_,
                                right.isPrimary_ );

        return (_left != _right);
    }
} // namespace video
} // namespace sml
//------------------------End of file Display.cpp -----------------------------