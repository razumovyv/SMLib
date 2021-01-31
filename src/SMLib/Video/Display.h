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
        class Display
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
                std::vecotr<DisplayMode> GetDisplayModes() const;

                //-------------------------------------------------------------
                // Returning current mode of display
                //-------------------------------------------------------------
                DisplayMode GetCurrentMode() const;

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

                uint32_t        m_Index;        
                std::string     m_Name;         
                std::string     m_AdapterDescription;
                std::string     m_MonitorDescription;

                std::vector<DisplayMode> m_modesList;   

        }; // class SML_API Display

    } // namespace display
} // namespace sml
#endif // !SML_SYSTEM_DISPLAY_H_
//-------------------------- End of file Dispaly.h ----------------------------
