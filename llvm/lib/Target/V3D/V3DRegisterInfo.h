#ifndef LLVM_LIB_TARGET_V3D_V3DREGISTERINFO_H
#define LLVM_LIB_TARGET_V3D_V3DREGISTERINFO_H

#define GET_REGINFO_HEADER
#include "V3DGenRegisterInfo.inc"

namespace llvm {

struct V3DRegisterInfo : public V3DGenRegisterInfo {};

} // namespace llvm
#endif // LLVM_LIB_TARGET_V3D_V3DREGISTERINFO_H
