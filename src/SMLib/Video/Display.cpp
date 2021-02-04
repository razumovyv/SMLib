//-------------------------- File Display.cpp ---------------------------------

#include <SMLib/Video/Display.h>

namespace sml
{
    namespace video
    {
        Display::Display(uint32_t index, 
                         const char* adapterName, 
                         const char* adapterDesc,
                         const char* monitorDesc,
                         const bool isPrimary
                         const bool isActive) :
                         m_Index(index),
                         m_AdapterName(adapterName),
                         m_AdapterDesc(adapterDesc),
                         m_MonitorDesc(monitorDesc),
                         m_isPrimary(isPrimary)  
        {

        }

        Display::~Display()
        {
            
        }
    }
}
//------------------------End of file Display.cpp -----------------------------