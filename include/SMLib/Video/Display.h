//-------------------------- File Display.h -----------------------------------
#ifndef SML_DISPLAY_H_
#define SML_DISPLAY_H_

//-----------------------------------------------------------------------------
//
// TODO Documentation: main title for file
//
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------
#include <vector>
#include <SMLib/Video/Export.h>
#include <SMLib/Video/VideoMode.h>
#include <SMLib/Video/Flags.h>

//-----------------------------------------------------------------------------
// A main library namespace
//-----------------------------------------------------------------------------
namespace sml { 
//-----------------------------------------------------------------------------
// A opened video module namespace
//-----------------------------------------------------------------------------
namespace video {
        
    class SML_VIDEO_API Display {

        public:

            //-----------------------------------------------------------------
            // A default constructor
            //
            // Constructor creates an instance of a primary display
            //
            // TODO: Documentations
            //
            //-----------------------------------------------------------------
            Display( );

            //-----------------------------------------------------------------
            // Constructor #1
            //
            // TODO: Documentations
            //
            //-----------------------------------------------------------------
            Display( const char* name, 
                     const char* adapterDescription, 
                     const char* monitorDescription, 
                     const bool  isPrimary );

            //-----------------------------------------------------------------
            //Constructor #2
            //
            // TODO: Documentations
            //
            //-----------------------------------------------------------------
            Display( const string &name, 
                     const string &adapterDescription, 
                     const string &monitorDescription, 
                     const bool   isPrimary );

            //-----------------------------------------------------------------
            // A destructor
            //
            // TODO: Documentations
            //
            //-----------------------------------------------------------------
            ~Display( );

            //-----------------------------------------------------------------
            // Returning a supported video modes list
            //
            // TODO: Documentations
            //
            //-----------------------------------------------------------------
            std::vector< VideoMode > GetListVideoModes( ) const;

            //-----------------------------------------------------------------
            // Doing request to the operating system
            //
            // TODO: Documentations
            //
            //-----------------------------------------------------------------
            VideoMode GetVideoMode( ) const;

            //-----------------------------------------------------------------
            // Setting up a custom mode for this display
            //
            // TODO: Documentations
            //
            //-----------------------------------------------------------------
            bool SetVideoMode( const VideoMode& videoMode, 
                               uint32_t flags = SML_VM_FULLSCREEN );

            //-----------------------------------------------------------------
            // Checking a selected mode
            //
            // TODO: Documentations
            //
            //-----------------------------------------------------------------
            bool IsValidMode( const VideoMode& videoMode ) const;

            //-----------------------------------------------------------------
            // Returning "true" if display is priamry
            //
            // TODO: Documentations
            //
            //-----------------------------------------------------------------
            bool IsPrimary( ) const;

            friend bool operator==( const Display& left, const Display& right );
            friend bool operator!=( const Display& left, const Display& right );

        private:
            //-----------------------------------------------------------------
            // Member fields
            //
            // TODO: Documentations
            //
            //-----------------------------------------------------------------

            std::string      name_;  
            std::string      adapterDescription_;
            std::string      monitorDescription_;
            bool             isPrimary_;
            
            std::vector< VideoMode> listVideoModes_;

    };
} // namspace video
} // namspace sml
#endif // !SML_DISPLAY_H_
//---------------------- End of file Display.h --------------------------------ц
