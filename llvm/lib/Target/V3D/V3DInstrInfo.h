#ifndef LLVM_LIB_TARGET_V3D_V3DINSTRINFO_H
#define LLVM_LIB_TARGET_V3D_V3DINSTRINFO_H

#include "V3D.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "V3DGenInstrInfo.inc"
#include "V3DGenRegisterInfo.inc"

namespace llvm {

class V3DInstrInfo : public V3DGenInstrInfo {

#define GET_INSTRINFO_HELPER_DECLS
#include "V3DGenInstrInfo.inc"
};

} // namespace llvm
#endif // LLVM_LIB_TARGET_V3D_V3DINSTRINFO_H
