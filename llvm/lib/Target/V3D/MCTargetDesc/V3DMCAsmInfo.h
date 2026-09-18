#ifndef LLVM_LIB_TARGET_V3D_MCTARGETDESC_V3DMCASMINFO_H
#define LLVM_LIB_TARGET_V3D_MCTARGETDESC_V3DMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {
class Triple;

class V3DMCAsmInfo : public MCAsmInfoELF {
  void anchor() override;

public:
  explicit V3DMCAsmInfo(const Triple &TT, const MCTargetOptions &Options);
};

} // namespace llvm

#endif // LLVM_LIB_TARGET_V3D_MCTARGETDESC_V3DMCASMINFO_H
