//---------------------- File Display.cpp---------------------------

//------------------------------------------------------------------
// Headers
//------------------------------------------------------------------
#include <SMLib/Display/Display.h>

namspace sml{
    namspace display{
        //--------------------------------------------------------------
        // Default constructor
        //--------------------------------------------------------------
        Display::Display(){
        }
        
        //--------------------------------------------------------------
        // Custom constructor
        //---------------------------------------------------------------
        Display::Display(uint32_t index, const char* diaplyName, 
                                          const char* displayDescription) :
                          m_Index(index),
                          m_Name(displayName),
                          m_Description(displayDescription)
        {

        }

        //--------------------------------------------------------------
        // Descructor
        //--------------------------------------------------------------
        Display::~Display(){
        }
        
        std::vecotr<DisplayMode> Display::GetDisplayModesList(){
          return m_modesList;
        }
        
        std::vector<Display> Display::GetDisplayList(){
        
        } 
      
    } // namespace display
} // namespace sml
//------------------- End of file Display.cpp-----------------------
