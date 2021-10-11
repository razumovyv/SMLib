//---------------------------- File WindowBase.h ------------------------------
#ifndef SML_VIDEO_WINDOWBASE_H_
#define SML_VIDEO_WINDOWBASE_H_

#include <SMLib/Config.h>
#include <SMLib/System/NoneCopyable.h>
namespace sml {
namespace video {

class WindowBase : public system::NoneCopyable
{
public:
  WindowBase() = default;
  ~WindowBase() = default;

private:
};
} // namespace video
} // namespace sml

#endif
//------------------------- End of file WindowBase.h --------------------------