//-------------------------- File VideoExport.h -------------------------------
#ifndef SML_VIDEO_EXPORT_H_
#define SML_VIDEO_EXPORT_H_
//-----------------------------------------------------------------------------
// Main configure file
//-----------------------------------------------------------------------------
#include <SMLib/Config.h>

#if defined(SML_VIDEO_EXPORT)
    #define SML_VIDEO_API SML_API_EXPORT
#else
    #define SML_VIDEO_API SML_API_IMPORT
#endif

#endif // !SML_VIDEO_EXPORT_H_
//----------------------- End of file VideoExport.h ---------------------------