//------------------ File DisplayMode.cpp -------------------------------------

//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------
#include <SMLib/Video/VideoMode.h>
#include <tuple>

namespace sml {
namespace video {

//---------------------------------------------------------------------
// Default constructor
//---------------------------------------------------------------------
VideoMode::VideoMode()
  : width(640)
  , height(480)
  , bitPerPixel(32)
  , displayFrecency(60)
{}

//---------------------------------------------------------------------
// Custom constructor
//---------------------------------------------------------------------
VideoMode::VideoMode(uint32_t width,
                     uint32_t height,
                     uint32_t bitPerPixel,
                     uint32_t frecancy)
  : width(width)
  , height(height)
  , bitPerPixel(bitPerPixel)
  , displayFrecency(frecancy)
{}

bool
operator==(const VideoMode& left, const VideoMode& right)
{
  auto _left =
    std::tie(left.width, left.height, left.bitPerPixel, left.displayFrecency);

  auto _right = 
    std::tie(right.width, right.height, right.bitPerPixel, right.displayFrecency);

  return (_left == _right);
}

bool
operator!=(const VideoMode& left, const VideoMode& right)
{
  auto _left =
    std::tie(left.width, left.height, left.bitPerPixel, left.displayFrecency);

  auto _right = 
    std::tie(right.width, right.height, right.bitPerPixel, right.displayFrecency);

  return (_left != _right);
}

} // namespace video
} // namspace sml
//--------------- End of file DisplayMode.cpp ---------------------------------
