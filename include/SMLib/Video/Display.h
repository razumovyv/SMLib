//-------------------------- File Display.h -----------------------------------
#ifndef SML_DISPLAY_H_
#define SML_DISPLAY_H_

//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------
#include <vector>

#include <SMLib/Video/Export.h>
#include <SMLib/Video/VideoMode.h>
#include <SMLib/Video/Flags.h>


namespace sml { namespace video {
        
    class SML_VIDEO_API Display {

        public:
            //-------------------------------------------------------------
            // A default constructor
            //
            // TODO: Documentations
            //
            //-------------------------------------------------------------
            Display( );

            Display(  const char* displayName
                    , const char* adapterDesc
                    , const char* monitorDesc
                    , const bool isPrimary);

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
            bool SetVideoMode( const VideoMode& mode
                             , uint32_t flags = SML_VM_FULLSCREEN );

            //-----------------------------------------------------------------
            // Checking a selected mode
            //
            // TODO: Documentations
            //
            //-----------------------------------------------------------------
            bool IsValidMode( const VideoMode& mode ) const;

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

            string      name_;  
            string      adapterDesc_;
            string      monitorDesc_;
            bool        isPrimary_;
            
            std::vector< VideoMode> listModes_;
    };
} // namspace video
} // namspace sml
#endif // !SML_DISPLAY_H_
//---------------------- End of file Display.h --------------------------------
