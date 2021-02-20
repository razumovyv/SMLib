
//-------------------------- File NoneCopyable.h -------------------------------
#ifndef SML_NONECOPYABLE_H_
#define SML_NONECOPYABLE_H_

#include <SMLib/System/Export.h>

namespace sml {

    namespace system {

        class SML_SYSTEM_API NoneCopyable {
            public:
                NoneCopyable(const NoneCopyable&) = delete;
                NoneCopyable& operator=(const NoneCopyable&) = delete;
            
            protected:
                NoneCopyable() {}
                ~NoneCopyable() {};
        };
    } // namespace system
} // namespace sml

#endif // !SML_NONECOPYABLE_H_
//----------------------- End of file NoneCopyable.h ---------------------------
