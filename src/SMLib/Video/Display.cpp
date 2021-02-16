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

        cls::DisplayImpl::GetDisplayDesktop( 0, this );
        listVideoModes_ = cls::DisplayImpl::GetListVideoModes( name_.c_str( ) );
   
    }

    //---------------------------------------------------------------------
    // Constructor #1
    //
    // TODO: Documentations
    //
    //---------------------------------------------------------------------
    Display::Display( const char* name, 
                      const char* adapterDescription, 
                      const char* monitorDescription, 
                      const bool  isPrimary ) :
                      name_               ( namee ), 
                      adapterDescription_ ( adapterDescription ), 
                      monitorDescription_ ( monitorDescription ), 
                      isPrimary_          ( isPrimary   ) 
    { 
        listVideoModes_ = cls::DisplayImpl::GetListVideoModes( name_.c_str( ) );
    }

    //---------------------------------------------------------------------
    // FIXME Base constructor
    //
    // TODO: Documentations
    //
    //---------------------------------------------------------------------
    Display::Display( const string &name, 
                      const string &adapterDescription, 
                      const string &monitorDescription, 
                      const bool   isPrimary ) : 
                      name_               ( name ), 
                      adapterDescription_ ( adapterDescription ), 
                      monitorDescription_ ( monitorDescription ), 
                      isPrimary_          ( isPrimary   ) 
    { 
        listVideoModes_ = cls::DisplayImpl::GetListVideoModes( name_.c_str( ) );
    }

    Display::~Display() 
    { 
        listVideoModes_.clear(); 
    }

    //-----------------------------------------------------------------
    // Returning a supported video modes list
    //
    // TODO: Documentations
    //
    //-----------------------------------------------------------------
    std::vector< VideoMode> Display::GetListVideoModes( ) const 
    {

        return listVideoModes_;
    }   

    //---------------------------------------------------------------------
    // Returning a current settings for instance
    //
    // TODO: Documentations
    //
    //---------------------------------------------------------------------
    VideoMode Display::GetVideoMode( ) const 
    {

        VideoMode videoMode;
        if( cls::DisplayImpl::GetVideoMode( name_.c_str( ), &videoMode ) )
        {
            return videoMode;

        } else {

            // TODO Error log
            return VideoMode( 0,0,0,0 );
        }
        
    }

    //-------------------------------------------------------------
    // Setting up a custom mode for this display
    //
    // TODO: Documentations
    //
    //-------------------------------------------------------------
    bool Display::SetVideoMode( const VideoMode& videoMode, uint32_t flags )
    {

        if( !IsValidMode( videMode ) ) return false;
        
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

    bool operator==( const Display& left, const Display& right ) 
    {
        
        return (( left.name_                == right.name_               )
              &&( left.adapterDescription_  == right.adapterDescription_ )
              &&( left.monitorDescription_  == right.monitorDescription_ )
              &&( left.isPrimary_           == right.isPrimary_          ));
    }

    bool operator!=( const Display& left, const Display& right ) 
    {
    
        return !( ( left.name_               == right.name_               )
                &&( left.adapterDescription_ == right.adapterDescription_ )
                &&( left.monitorDescription_ == right.monitorDescription_ )
                &&( left.isPrimary_          == right.isPrimary_          ));
    }
} // namespace video
} // namespace sml
//------------------------End of file Display.cpp -----------------------------