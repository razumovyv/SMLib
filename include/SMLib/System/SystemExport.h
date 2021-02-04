//-------------------------- File SystemExport.h -------------------------------
#ifndef SML_SYSTEM_EXPORT_H_
#define SML_SYSTEM_EXPORT_H_
//-----------------------------------------------------------------------------
// Main configure file
//-----------------------------------------------------------------------------
#include <SMLib/config.h>

#if defined(SML_SYSTEM_EXPORT)
    #define SML_SYSTEM_API SML_API_EXPORT
#else
    #define SML_SYSTEM_API SML_API_IMPORT
#endif

#endif // !SML_SYSTEM_EXPORT_H_
//----------------------- End of file SystemExport.h ---------------------------
