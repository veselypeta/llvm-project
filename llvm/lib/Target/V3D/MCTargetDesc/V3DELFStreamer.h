#ifndef LLVM_LIB_TARGET_V3D_MCTARGETDESC_V3DELFSTREAMER_H
#define LLVM_LIB_TARGET_V3D_MCTARGETDESC_V3DELFSTREAMER_H

#include "V3DTargetStreamer.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCELFStreamer.h"
namespace llvm {

class V3DELFStreamer : public MCELFStreamer {
public:
  V3DELFStreamer(MCContext &Ctx, std::unique_ptr<MCAsmBackend> MAB,
                 std::unique_ptr<MCObjectWriter> MOW,
                 std::unique_ptr<MCCodeEmitter> MCE);
};

class V3DTargetELFStreamer : public V3DTargetStreamer {
public:
  V3DTargetELFStreamer(MCStreamer &S);
};

MCStreamer *createV3DELFStreamer(const Triple &, MCContext &C,
                                 std::unique_ptr<MCAsmBackend> &&MAB,
                                 std::unique_ptr<MCObjectWriter> &&MOW,
                                 std::unique_ptr<MCCodeEmitter> &&MCE);
} // namespace llvm

#endif // LLVM_LIB_TARGET_V3D_MCTARGETDESC_V3DELFSTREAMER_H
