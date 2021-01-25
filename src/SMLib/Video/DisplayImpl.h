//--------------------- File DisplayImpl.h -----------------------------
#ifndef SML_DISPLAY_IMPLEMENTATION_H_
#define SML_DISPLAY_IMPLEMENTATION_H_

#include <vector>
#include <SMLib/Display/Display.h>
namespace sml{ namespace cls{
    class DisplayImpl{

        public:
            //--------------------------------------------------
            // Default constructor
            //--------------------------------------------------
            DisplayImpl();
            //--------------------------------------------------
            // Distructor
            //--------------------------------------------------
            virtual ~DisplayImpl();
                    
             //----------------------------------------------
            static std::vector<display::Dispaly> GetDisplayListFromSystem();
            
    };
} /* namespace cls*/ } // namespace sml
#endif
//------------------ End of file DisplayImpl.h -------------------------
