//--------------------- File DisplayImpl.h ------------------------------------
#ifndef SML_DISPLAY_IMPLEMENTATION_H_
#define SML_DISPLAY_IMPLEMENTATION_H_

//-----------------------------------------------------------------------------
//
// TODO Documentation: main title for file
//
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------
#include <SMLib/Video/Display.h>
#include <SMLib/Video/VideoMode.h>
#include <vector>

//-----------------------------------------------------------------------------
// A main library namespace
//-----------------------------------------------------------------------------
namespace sml {

//-----------------------------------------------------------------------------
// A opened video module namespace
//-----------------------------------------------------------------------------
namespace video {

//-----------------------------------------------------------------------------
// A closed video module namespace
//-----------------------------------------------------------------------------
namespace cls {


class DisplayImpl
{
public:
  //---------------------------------------------------------------------------
  // Returning an active display instance
  //
  // TODO Documentation
  //
  //---------------------------------------------------------------------------
  static std::vector<PDisplay> GetDisplayList();

  //---------------------------------------------------------------------------
  // Returning a vector of supported modes for display
  //
  // TODO Documentation
  //
  //---------------------------------------------------------------------------
  static std::vector<VideoMode> GetListVideoModes(const char* displayName);

  //---------------------------------------------------------------------------
  // Returning a current desktop mode for selected display
  //
  // TODO Documentation
  //
  //---------------------------------------------------------------------------
  static VideoMode GetVideoMode(const char* displayName);

  //---------------------------------------------------------------------------
  // Seting a video mode to a selected display
  //
  // TODO Documentation
  //
  //---------------------------------------------------------------------------
  static bool SetVideoMode(const char* displayName,
                           const VideoMode& mode,
                           uint32_t flags);
};

} // namespace cls
} // namespace video
} // namespace sml
#endif
//------------------ End of file DisplayImpl.h --------------------------------
