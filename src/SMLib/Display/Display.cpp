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
    Dispaly::Display(){
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
