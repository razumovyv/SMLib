//---------------------- File Display.cpp---------------------------

//------------------------------------------------------------------
// Headers
//------------------------------------------------------------------
#include <SMLib/Display/Display.h>

namespace sml{
    namespace display{
        //--------------------------------------------------------------
        // Default constructor
        //--------------------------------------------------------------
        Display::Display(){
        }
        
        //--------------------------------------------------------------
        // Custom constructor
        //---------------------------------------------------------------
        Display::Display(uint32_t index, 
                         const char* diaplyName,                 
                         const char* displayDescription,
                         bool isPrimary) : 
                            m_Index(index), 
                            m_Name(displayName),
                            m_Description(displayDescription),
                            m_isPrimary(isPrimary)
        {

        }

        //--------------------------------------------------------------
        // Descructor
        //--------------------------------------------------------------
        Display::~Display(){
        }
        /*
        std::vector<DisplayMode> Display::GetDisplayModesList(){
          return m_modesList;
        }*/
        
        std::vector<Display> Display::GetDisplayList(){

            return cls::DisplayImpl::GetDisplayListFromSystem();
            
        } 
      
    } // namespace display
} // namespace sml
//------------------- End of file Display.cpp-----------------------
