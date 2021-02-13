//-------------------------- File Display.cpp ---------------------------------

#include <SMLib/Video/Display.h>
#include <SMLib/Video/DisplayImpl.h>

namespace sml {

    namespace video {

        //---------------------------------------------------------------------
        // Default constructor
        //---------------------------------------------------------------------
        Display::Display()
            : index_        ( 0 )
            , name_         ( "none" )
            , adapterDesc_  ( "none" )
            , monitorDesc_  ( "none" )
            , isPrimary_    ( false ) { }

        //---------------------------------------------------------------------
        // Base constructor
        //---------------------------------------------------------------------
        Display::Display( uint32_t index 
                        , const char* displayName 
                        , const char* adapterDesc
                        , const char* monitorDesc
                        , const bool isPrimary) 
                        : index_        ( index )
                        , name_         ( displayName )
                        , adapterDesc_  ( adapterDesc )
                        , monitorDesc_  ( monitorDesc )
                        , isPrimary_    ( isPrimary ) { }

        Display::~Display() { }

        //---------------------------------------------------------------------
        // Returning a current settings for instance
        //---------------------------------------------------------------------
        VideoMode Display::GetCurrentVideoMode() const {

            return cls::DisplayImpl::GetCurrentDesktopMode(this->adapterDesc_.c_str());
        }

        //---------------------------------------------------------------------
        // Returning a vector of active displays
        //---------------------------------------------------------------------
        std::vector<Display> Display::GetActiveDesktopDispalys() {

            return cls::DisplayImpl::GetActiveDesktopDisplays();
        }

        //---------------------------------------------------------------------
        // Get primary display instance
        //---------------------------------------------------------------------
        Display Display::GetPrimaryDisplay(){

            return cls::DisplayImpl::GetPrimaryDisplay();
        }

        //-------------------------------------------------------------
        // Setting up a custom mode for this display
        //-------------------------------------------------------------
        bool Display::SetDesktopMode(const VideoMode& mode, uint32_t flags) {

            if(!IsValidMode(mode)) return false;
            
            return cls::DisplayImpl::SetVideoMode(this->name_.c_str(), mode, flags);
        }

        //-------------------------------------------------------------
        // Checking a selected mode
        //-------------------------------------------------------------
        bool Display::IsValidMode(const VideoMode& mode) const {

            return cls::DisplayImpl::SetVideoMode(this->name_.c_str(), mode, SML_VM_TEST);
        }

        bool Display::IsPrimary() const {
            
            return isPrimary_;
        }
    }
}
//------------------------End of file Display.cpp -----------------------------