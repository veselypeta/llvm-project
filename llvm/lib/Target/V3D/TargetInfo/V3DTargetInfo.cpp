#include "TargetInfo/V3DTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Compiler.h"

using namespace llvm;

Target &llvm::getTheV3DTarget() {
  static Target TheV3DTarget;
  return TheV3DTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeV3DTargetInfo() {
  RegisterTarget<Triple::v3d> X(getTheV3DTarget(), "v3d", "VideoCode VII (V3D)",
                                "V3D");
}
