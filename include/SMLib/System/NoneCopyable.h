
//-------------------------- File NoneCopyable.h -------------------------------
#ifndef SML_NONECOPYABLE_H_
#define SML_NONECOPYABLE_H_

#include <SMLib/System/SystemExport.h>

namespace sml 
{
    namespace system
    {
        class SML_SYSTEM_API NoneCopyable
        {
            protected:
                NoneCopyable() {}

                ~NoneCopyable() {}
            private:
                NoneCopyable(const NoneCopyable&);
                NoneCopyable& operator=(const NoneCopyable&)
        };
    } // namespace system
} // namespace sml

#endif // !SML_NONECOPYABLE_H_
//----------------------- End of file NoneCopyable.h ---------------------------
