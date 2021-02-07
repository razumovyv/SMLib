//--------------------- File DisplayImpl.h ------------------------------------
#ifndef SML_DISPLAY_IMPLEMENTATION_H_
#define SML_DISPLAY_IMPLEMENTATION_H_

#include <vector>
#include <SMLib/Video/Display.h>
namespace sml{ namespace cls{
    class DisplayImpl{

        public:
            //-----------------------------------------------------------------
            // Default constructor
            //-----------------------------------------------------------------
            DisplayImpl() {};
            //-----------------------------------------------------------------
            // Distructor
            //-----------------------------------------------------------------
            virtual ~DisplayImpl() {};
                    
             //----------------------------------------------------------------
             // Returning a vector of active displays
             //----------------------------------------------------------------
            static std::vector<video::Display> GetDisplayListFromSystem();

            //-----------------------------------------------------------------
            // Returning a vector of supported modes for display
            //-----------------------------------------------------------------
           // static std::vector<video::VideoMode> 
           // GetDisplayModes(const std::string& displayName);
            
    };
} /* namespace cls*/ } // namespace sml
#endif
//------------------ End of file DisplayImpl.h -------------------------
