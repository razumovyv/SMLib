//------------------------ File DispalyManager.h ------------------------------
#ifndef SML_DISPLAY_MANAGER_H_
#define SML_DISPLAY_MANAGER_H_

//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------
#include <SMLib/Video/VideoExport.h>

namespace sml
{
    namespace system { class NoneCopyable; }
    namespace video
    {   
        class DisplayManager;

        class SML_VIDEO_API DisplayManagerDestroyer : system::NoneCopyable
        {
            DisplayManagerDestroyer();
            ~DisplayManagerDestroyer();
        };

        class SML_VIDEO_API DisplayManager : system::NoneCopyable
        {
        public:
            static DisplayManager* GetInstance();
        protected:

            //-----------------------------------------------------------------
            // The protected constructor for a fabric function
            //-----------------------------------------------------------------
            DisplayManager();

            //-----------------------------------------------------------------
            // The protected destructor for a fabric function
            //-----------------------------------------------------------------
            ~DisplayManager();

        private:

            static DisplayManager* _instance;

        }; // class DiplayManager
    } // namespace video
} // namespace sml

#endif // !SML_DISPLAY_MANAGER_H_

//--------------------- End of file DispalyManager.h --------------------------
