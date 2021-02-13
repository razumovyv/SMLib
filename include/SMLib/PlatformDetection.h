//-------------------------- File PlatformDetection.h -------------------------
#ifndef SML_SYSTEM_PLATFORM_DETECTION_H_
#define SML_SYSTEM_PLATFORM_DETECTION_H_

//-----------------------------------------------------------------------------
// Identify the operating system
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
    
#endif // !SML_CORE_PLATFORM_DETECTION_H_
//---------------------- End of file PlatformDetection.h --------------------
