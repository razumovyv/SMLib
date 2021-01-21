//----------------------------- File Dispaly.h --------------------------------
#ifndef SML_SYSTEM_DISPLAY_H_
#define SML_SYSTEM_DISPLAY_H_

//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------
#include <string>
#include <vector>
#include <SMLib/config.h>


namespace sml
{
    namespace display
    {
        class DispalayMode;

        class SML_API Display
        {
            public:
                //-------------------------------------------------------------
                // Deafult constructor
                //-------------------------------------------------------------
                Display();

                //-------------------------------------------------------------
                // Custom constructor
                //-------------------------------------------------------------
                Display(uint32_t index, const char* diaplyName, const char* displayDescription);

                //-------------------------------------------------------------
                // Destructor
                //-------------------------------------------------------------
                virtual ~Display();
            
            public:
                //-------------------------------------------------------------
                // Get the supported modes list for current display
                //-------------------------------------------------------------
                std::vecotr<DisplayMode> GetDisplayModesList();
            
                //-------------------------------------------------------------
                // Get the display list
                //-------------------------------------------------------------
                static std::vector<Display> GetDisplayList();
                

            private:
                std::vector<DispalayMode> m_modesList;
                uint32_t        m_Index;
                std::string     m_Name;
                std::string     m_Description;
                bool            m_isPrimary;

        }; // class SML_API Display

    } // namespace display
} // namespace sml
#endif // !SML_SYSTEM_DISPLAY_H_
//-------------------------- End of file Dispaly.h ----------------------------
