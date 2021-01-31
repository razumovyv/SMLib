//-------------------------- File DisplayManger.h -----------------------------

#ifndef SML_VIDEO_DISPLAY_MANAGER_H_
#define SML_VIDEO_DISPLAY_MANAGER_H_

//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------
#include <SMLib/config.h>

namespace sml
{  
    namespace video
    {
        class SML_API DispalyManager{

            public:
                //-------------------------------------------------------------
                // Disable a copy constructor
                //-------------------------------------------------------------
                DipslayManager(const DispalyManager&) = delete;

                //-------------------------------------------------------------
                // Disable a assigment operator
                //-------------------------------------------------------------
                DispalyManager operator=(const DispalyManager&) = delete;

                //-------------------------------------------------------------
                // A fabric function
                //-------------------------------------------------------------
                static DisplayManager* GetInstance();
            
            protected:
                //-------------------------------------------------------------
                // A Sinleton Instance
                //-------------------------------------------------------------
                static DisplayManager* _Instance;

                //-------------------------------------------------------------
                // Default constructor
                //-------------------------------------------------------------
                DispalyManger();

                //-------------------------------------------------------------
                // Default destructor
                //-------------------------------------------------------------
                ~DisplayManager();

        }; //  class DisplayManager

    } // namespace video
} // namspace sml
#endif // !SML_VIDEO_DISPLAY_MANAGER_H_
//----------------------- End of file DisplayManger.h -------------------------