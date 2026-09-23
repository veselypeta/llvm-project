#ifndef LLVM_LIB_TARGET_RISCV_MCTARGETDESC_RISCVELFSTREAMER_H
#define LLVM_LIB_TARGET_RISCV_MCTARGETDESC_RISCVELFSTREAMER_H

#include "llvm/MC/MCStreamer.h"
#include "llvm/Support/FormattedStream.h"
namespace llvm {

class V3DTargetStreamer : public MCTargetStreamer {

public:
  V3DTargetStreamer(MCStreamer &S);
};

class V3DTargetAsmStreamer : public V3DTargetStreamer {
  formatted_raw_ostream &OS;

public:
  V3DTargetAsmStreamer(MCStreamer &S, formatted_raw_ostream &OS);
};

} // namespace llvm
#endif // LLVM_LIB_TARGET_RISCV_MCTARGETDESC_RISCVELFSTREAMER_H
