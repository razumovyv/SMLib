//----------------------------- File Types.h ----------------------------------
#ifndef SML_VIDEO_TYPES_H_
#define SML_VIDEO_TYPES_H_

namespace sml{ namespace video{

//-----------------------------------------------------------------------------
// Flags for SetVideoMode
//-----------------------------------------------------------------------------
constexpr uint32_t SML_VM_REGUPDAETE  =  0x00000001;
constexpr uint32_t SML_VM_TEST        =  0x00000002;
constexpr uint32_t SML_VM_FULLSCREEN  =  0x00000004;
constexpr uint32_t SML_VM_GLOBAL      =  0x00000008;
constexpr uint32_t SML_VM_SET_PRIMARY =  0x00000010;
constexpr uint32_t SML_VM_RESET       =  0x40000000;
constexpr uint32_t SML_VM_NORESET     =  0x10000000;

} // namespace video
} // namespace sml



#endif
//-------------------------- End of file Types.h ------------------------------