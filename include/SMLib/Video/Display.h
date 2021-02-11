//-------------------------- File Display.h -----------------------------------
#ifndef SML_DISPLAY_H_
#define SML_DISPLAY_H_

//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------

#include <vector>
#include <map>
#include <string>

#include <SMLib/System/NoneCopyable.h>
#include <SMLib/Video/VideoExport.h>
#include <SMLib/Video/VideoMode.h>
#include <SMLib/Video/Types.h>


namespace sml
{
    namespace video
    {
        
        class SML_VIDEO_API Display
        {   
            public:
                //-------------------------------------------------------------
                // A default constructor
                //-------------------------------------------------------------
                Display( );

                Display(uint32_t index
                      , const char* displayName
                      , const char* adapterDesc
                      , const char* monitorDesc
                      , const bool isPrimary);

                //-------------------------------------------------------------
                // A destructor
                //-------------------------------------------------------------
                ~Display( );

                //-------------------------------------------------------------
                // Get a vector of active displayInstance with atached monitors
                //-------------------------------------------------------------
                static std::vector<Display> GetActiveDesktopDispalys();

                //-------------------------------------------------------------
                // Get primary display instance
                //-------------------------------------------------------------
                static Display GetPrimaryDisplay();

                //-------------------------------------------------------------
                // Doing request to the operating system
                //-------------------------------------------------------------
                VideoMode GetCurrentVideoMode( ) const;

                //-------------------------------------------------------------
                // Setting up a custom mode for this display
                //-------------------------------------------------------------
                bool SetDesktopMode(const VideoMode& mode
                                        , uint32_t flags = SML_VM_FULLSCREEN);

                //-------------------------------------------------------------
                // Checking a selected mode
                //-------------------------------------------------------------
                bool IsValidMode(const VideoMode& mode) const;

                //-------------------------------------------------------------
                // Returning "true" if display is priamry
                //-------------------------------------------------------------
                bool IsPrimary() const;
 
            private:
                //-------------------------------------------------------------
                // Member fields
                //-------------------------------------------------------------
                uint32_t    index_;        
                std::string name_;  
                std::string adapterDesc_;
                std::string monitorDesc_;
                bool        isPrimary_;
        };
    } // namspace video
} // namspace sml
#endif // !SML_DISPLAY_H_
//---------------------- End of file Display.h --------------------------------
