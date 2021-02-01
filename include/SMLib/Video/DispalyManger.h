//-------------------------- File DisplayManger.h -----------------------------

#ifndef SML_VIDEO_DISPLAY_MANAGER_H_
#define SML_VIDEO_DISPLAY_MANAGER_H_

//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------
#include <SMLib/config.h>
#include <map>

namespace sml{  namespace video {
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
                
            //-------------------------------------------------------------
            // Returning a number of an active displays in your system
            //-------------------------------------------------------------
            uint32_t GetNumberOfActiveDisplays() const;
                
            //-------------------------------------------------------------
            // Returning a current video mode of primary display
            //-------------------------------------------------------------
            VideoMode GetPrimaryDisplayMode() const;
            
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
            
        private:
            //-------------------------------------------------------------
            // The number of an active displays in yours operating system
            //-------------------------------------------------------------
            uint32_t m_NumOfDisplays;
            
            std::map<std::string, sml::video::Dispaly> m_DisplayList;
                
    }; //  class DisplayManager

} /* namespace video */ } // namspace sml
#endif // !SML_VIDEO_DISPLAY_MANAGER_H_
//----------------------- End of file DisplayManger.h -------------------------
