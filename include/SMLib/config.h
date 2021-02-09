//----------------------------- File Config.h ---------------------------------
#ifndef SML_CONFIG_H_
#define SML_CONFIG_H_

//-----------------------------------------------------------------------------
// Project version
//-----------------------------------------------------------------------------
#include <SMLib/System/Version.h>

//-----------------------------------------------------------------------------
// Platform detection
//-----------------------------------------------------------------------------
#include <SMLib/System/PlatformDetection.h>

//-----------------------------------------------------------------------------
// Config API import/export
#if !defined(SML_STATIC)
    #if defined(SML_WINDOWS_SYSTEM)

        #define SML_API_EXPORT __declspec(dllexport)
        #define SML_API_IMPORT __declspec(dllimport)
        
        #ifdef _MSC_VER
            #pragma warning(disable : 4251)
        #endif
    #elif defined(__unix__)

        #if __GNUC__ >= 4
            #define SML_API_EXPORT __attribute__ ((__visibility__ ("default")))
            #define SML_API_IMPORT __attribute__ ((__visibility__ ("default")))
        #else
                #define SML_API_EXPORT
                #define SML_API_IMPORT
        #endif

    #else
        #error Your operating system don't supported SMLib
    #endif
#else
    #define SML_API_EXPORT
    #define SML_API_IMPORT
#endif
#include <cstdint>
namespace sml
{
    // Signed types
    using int8_t  = std::int8_t;
    using int16_t = std::int16_t;
    using int32_t = std::int32_t;
    using int64_t = std::int64_t;

    // Unsigned types
    using uint8_t = std::uint8_t;
    using uint16_t = std::uint16_t;
    using uint32_t = std::uint32_t;
    using uint64_t = std::uint64_t;
    
}



#endif // !SML_CONFIG_H_
//-------------------------- End of file Config.h -----------------------------
