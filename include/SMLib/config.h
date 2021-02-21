//----------------------------- File Config.h ---------------------------------
#ifndef SML_CONFIG_H_
#define SML_CONFIG_H_

//-----------------------------------------------------------------------------
//
// TODO Documentation: main title for file
//
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Project version
//-----------------------------------------------------------------------------
#include <SMLib/Version.h>

//-----------------------------------------------------------------------------
// Platform detection
//-----------------------------------------------------------------------------
#if defined(_WIN32) || defined(_WIN32_)

    #define SML_WINDOWS_SYSTEM
    #ifndef NOMINMAX
        #define NOMINMAX
    #endif

#elif defined(__APPLE__) && defined(__MACH__)
    
    #define SML_APPLE_SYSTEM
    #error Apple operating systems don't supported by Simple Game Engine

#elif defined(__unix__)
    
    // Indentify Unix operaring systems

    #if defined(__linux__)

        // Linux
        #define SML_LINUX_SYSTEM

    #elif defined(__ANDROID__)
        // Android
        #define SML_ANDROID_SYSTEM
        #error Android operating system don't supported by the Simple Game Engine
    
    #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)

        // FreeBSD
        #define SML_FREEBSD_SYSTEM
        #error FreeBSD operating system don't supported the Simple Game Engine

    #elif defined(__OpenBSD__)

        // OpenBSD
        #define SML_OPENBSD_SYSTEM
        #error OpenBSD operating system don't supported the Simple Game Engine

    #elif defined(__NetBSD__)

        // NetBSD
        #define SML_NETBSD_SYSTEM
        #error NetBSD operating system don't supported by Simple Game Engine

    #else

        // Unsupported UNIX system
        #error This UNIX operating system is not supported by Simple Game Engine

    #endif
#else
    #error This system do not support by the Simple Game Emgine
#endif

//-----------------------------------------------------------------------------
// Config API import/export
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// Namespace organization
//-----------------------------------------------------------------------------

namespace sml{
//-----------------------------------------------------------------------------
// Libarary root namespace
//-----------------------------------------------------------------------------
    
    namespace system{
    //-------------------------------------------------------------------------
    // Opened system module namespace
    //-------------------------------------------------------------------------
        namespace cls{
        //---------------------------------------------------------------------
        // Closed system module namespace
        //---------------------------------------------------------------------
        }    
    }
    namespace video{
    //-------------------------------------------------------------------------
    // Opened video module namespace
    //-------------------------------------------------------------------------
        namespace cls{
        //---------------------------------------------------------------------
        // Closed video module namespace
        //---------------------------------------------------------------------
        }
    }
    namespace graphics{
    //-------------------------------------------------------------------------
    // Opened graphics module namespace
    //-------------------------------------------------------------------------
        namespace cls{
        //---------------------------------------------------------------------
        // Closed graphics module namespace
        //---------------------------------------------------------------------
        }
    }
    namespace audio{
    //-------------------------------------------------------------------------
    // Opened audio module namespace
    //-------------------------------------------------------------------------
        namespace cls{
        //---------------------------------------------------------------------
        // Closed audio module namespace
        //---------------------------------------------------------------------
        }
    }
    namespace network{
    //-------------------------------------------------------------------------
    // Opened network module namespace
    //-------------------------------------------------------------------------
        namespace cls{
        //---------------------------------------------------------------------
        // Closed network module namespace
        //---------------------------------------------------------------------
        }
    }
}

//-----------------------------------------------------------------------------
// Using types
//-----------------------------------------------------------------------------
#include <cstdint>

namespace sml
{
    // Signed types
    using int8_t    = std::int8_t;
    using int16_t   = std::int16_t;
    using int32_t   = std::int32_t;
    using int64_t   = std::int64_t;

    // Unsigned types
    using uint8_t   = std::uint8_t;
    using uint16_t  = std::uint16_t;
    using uint32_t  = std::uint32_t;
    using uint64_t  = std::uint64_t;
    
}



#endif // !SML_CONFIG_H_
//-------------------------- End of file Config.h -----------------------------
