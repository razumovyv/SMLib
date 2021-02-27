//-------------------------- File Display.cpp ---------------------------------
#include "DisplayImpl.h"
#include <SMLib/Video/Display.h>
#include <tuple>
#include <iostream>

namespace sml {
namespace video {

//-----------------------------------------------------------------------------
// Base constructor
//
// TODO: Documentations
//
//-----------------------------------------------------------------------------
Display::Display(const std::string& name,
                 const std::string& adapterDescription,
                 const std::string& monitorDescription,
                 const bool isPrimary)

  : name_(name)
  , adapterDescription_(adapterDescription)
  , monitorDescription_(monitorDescription)
  , isPrimary_(isPrimary) {}

//-----------------------------------------------------------------------------
// Active displays
//-----------------------------------------------------------------------------

std::vector<DisplayPtr>
Display::GetDisplaysList()
{
  return cls::DisplayImpl::GetDisplayList();
}

  //---------------------------------------------------------------------------
// Returning a supported video modes list
//
// TODO: Documentations
//
//-----------------------------------------------------------------------------
std::vector<VideoMode>
Display::GetListVideoModes() const
{

  return cls::DisplayImpl::GetListVideoModes(name_.c_str());
}

//-----------------------------------------------------------------------------
// Returning a current settings for instance
//
// TODO: Documentations
//
//-----------------------------------------------------------------------------
VideoMode
Display::GetVideoMode() const
{

  return cls::DisplayImpl::GetVideoMode(name_.c_str());
}

//-----------------------------------------------------------------------------
// Setting up a custom mode for this display
//
// TODO: Documentations
//
//-----------------------------------------------------------------------------
bool
Display::SetVideoMode(const VideoMode& videoMode, uint32_t flags) const
{

  if (!IsValidMode(videoMode))
    return false;

  return cls::DisplayImpl::SetVideoMode(name_.c_str(), videoMode, flags);
}

//-----------------------------------------------------------------------------
// Checking a selected mode
//
// TODO: Documentations
//
//-----------------------------------------------------------------------------
bool
Display::IsValidMode(const VideoMode& videoMode) const
{

  return cls::DisplayImpl::SetVideoMode(name_.c_str(), videoMode, SML_VM_TEST);
}

// TODO: Description
// TODO: Documentation
bool
Display::IsPrimary() const
{

  return isPrimary_;
}

//-----------------------------------------------------------------------------
// Getting an adapters friendly description
//-----------------------------------------------------------------------------
std::string
Display::GetAdapterDescription() const
{
  return adapterDescription_;
}

//-----------------------------------------------------------------------------
// Getting an adapters friendly description
//-----------------------------------------------------------------------------
std::string
Display::GetMonitorDescription() const
{
  return monitorDescription_;
}

} // namespace video
} // namespace sml
//------------------------End of file Display.cpp -----------------------------
