//----------------------------- File Display.h --------------------------------
#ifndef SML_SYSTEM_DISPLAY_H_
#define SML_SYSTEM_DISPLAY_H_

//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <SMLib/config.h>
//#include <SMLib/Video/DisplayMode.h>


namespace sml
{
    namespace video
    {
        class SML_API Display
        {
            public:
                //-------------------------------------------------------------
                // Destructor
                //-------------------------------------------------------------
                virtual ~Display();

                friend class DisplayImpl;
            
            
            public:
                //-------------------------------------------------------------
                // Get the supported modes list for current display
                //-------------------------------------------------------------
                std::vecotr<DisplayMode> 
                GetDisplayModes(std::string displayName) const;
            
                //-------------------------------------------------------------
                // Get the display list from system
                //-------------------------------------------------------------
                static std::vector<Display*> GetDisplays() const;

                //-------------------------------------------------------------
                // Returning the number of active displays
                //-------------------------------------------------------------
                uint32_t GetNumOfDisplays() const;

                //-------------------------------------------------------------
                // Returning current mode of display
                //-------------------------------------------------------------
                DisplayMode GetCurrentMode(std::string displayName) const;

            protected:

                //-------------------------------------------------------------
                // Deafult constructor
                //-------------------------------------------------------------
                Display();

                //-------------------------------------------------------------
                // Custom constructor
                //-------------------------------------------------------------
                Display(uint32_t index, 
                        const char* diaplyName, 
                        const char* displayDescription, 
                        bool isPrimary);
                
                //-------------------------------------------------------------
                // Disable a copy constructor
                //-------------------------------------------------------------
                Display(const Display&) = delete;

                //-------------------------------------------------------------
                // Disable a assigment operator
                //-------------------------------------------------------------
                Display& operator=(const Display&) = delete;

            private:
                //-------------------------------------------------------------
                // Container for exempls of class
                //-------------------------------------------------------------
                static std::map<std::string, Display*> m_displayMap;

                uint32_t        m_SystemIndex;        
                std::string     m_SystemName;         
                std::string     m_AdapterDescription;
                std::string     m_MonitorDescription;

                std::vector<DisplayMode> m_modesList;   

        }; // class SML_API Display

    } // namespace display
} // namespace sml
#endif // !SML_SYSTEM_DISPLAY_H_
//-------------------------- End of file Dispaly.h ----------------------------
