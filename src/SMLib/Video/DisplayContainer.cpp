//--------------------- File DIsplayContainer.cpp -----------------------------

#include <SMLib/Video/DisplayContainer.h>
#include "DisplayImpl.h"

namespace sml {
namespace video {

DisplayContainer&
DisplayContainer::Create()
{
  static DisplayContainer instance;
  return instance;
}

DisplayContainer::DisplayContainer() 
{
  displays_ = cls::DisplayImpl::GetDisplayList();
}

const PDisplay&
DisplayContainer::operator[](uint32_t index) const
{
  return (const PDisplay&)(displays_[index]);
}

PDisplay&
DisplayContainer::operator[](uint32_t index)
{
  return (PDisplay&)(displays_[index]);
}
} // namespace video
} // namespace sml
//------------------ End of file DIsplayContainer.cpp -------------------------