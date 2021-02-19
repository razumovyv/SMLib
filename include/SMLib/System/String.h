//---------------------------- File String.h-----------------------------------
#ifndef SML_SYSTEM_STRING_H_
#define SML_SYSTEM_STRING_H_

#include <string>
#include <SMLib/System/Export.h>

namespace sml {
namespace system {
    class SML_SYSTEM_API String {
        public:

            String();

            String(const char* value);

            ~String();


        private:
            std::string value_;

    };
} // namespace system
} // namespace sml
#endif // !SML_SYSTEM_STRING_H_

//------------------------- End of file String.h-------------------------------