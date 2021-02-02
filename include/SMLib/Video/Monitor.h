//-------------------------- File Monitor.h -----------------------------------

#ifndef SML_MONITOR_H_
#define SML_MONITOR_H_

//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------

#include <vector>
#include <string>

#include <SMLib/Video/VideoExport.h>
#include <SMLib/Video/VideoMode.h>

namespace sml
{
    namespace video
    {
        class SML_VIDEO_API Monitor
        {   
            public:
                Monitor();
                ~Monitor();

            protected:

                std::vector<VideoMode> _monitorModes;
            
            private:
                uint32_t    m_Index;        
                std::string m_AdapterName;  
                std::string m_AdapterDesc;
                std::string m_MonitorDesc;
                bool        m_isPrimary;
        };
    } // namspace video
} // namspace sml
#endif // !SML_MONITOR_H_
//---------------------- End of file Monitor.h --------------------------------
