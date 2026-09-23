#include "MCTargetDesc/V3DELFStreamer.h"
#include "V3DTargetStreamer.h"
#include "llvm/MC/MCAsmBackend.h"
#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/MC/MCObjectWriter.h"

using namespace llvm;

V3DELFStreamer::V3DELFStreamer(MCContext &Ctx,
                               std::unique_ptr<MCAsmBackend> MAB,
                               std::unique_ptr<MCObjectWriter> MOW,
                               std::unique_ptr<MCCodeEmitter> MCE)
    : MCELFStreamer(Ctx, std::move(MAB), std::move(MOW), std::move(MCE)) {}

V3DTargetELFStreamer::V3DTargetELFStreamer(MCStreamer &S)
    : V3DTargetStreamer(S) {}

MCStreamer *llvm::createV3DELFStreamer(const Triple &, MCContext &C,
                                       std::unique_ptr<MCAsmBackend> &&MAB,
                                       std::unique_ptr<MCObjectWriter> &&MOW,
                                       std::unique_ptr<MCCodeEmitter> &&MCE) {
  return new V3DELFStreamer(C, std::move(MAB), std::move(MOW), std::move(MCE));
}
