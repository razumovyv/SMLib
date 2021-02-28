//----------------------- File DIsplayContainer.h -----------------------------
#ifndef SML_VIDEO_DISPLAY_CONTAINER_H_
#define SML_VIDEO_DISPLAY_CONTAINER_H_

#include <SMLib/System/NoneCopyable.h>
#include <SMLib/Video/Display.h>
#include <SMLib/Video/Export.h>
#include <SMLib/Video/GeneralTypes.h>

namespace sml {
namespace video {

class SML_VIDEO_API DisplayContainer : private system::NoneCopyable
{
public:
  static DisplayContainer& Create();
  const PDisplay& operator[](uint32_t index) const;
  PDisplay& operator[](uint32_t index);

protected:
  DisplayContainer();
  ~DisplayContainer() = default;

private:
  std::vector<PDisplay> displays_;
};

} // namespace video
} // namespace sml
#endif // !SML_VIDEO_DISPLAY_CONTAINER_H_
//------------------- End of file DisplayContainer.h --------------------------