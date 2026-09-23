#include "V3DMCTargetDesc.h"
#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCInstrInfo.h"
using namespace llvm;

namespace {

class V3DMCCodeEmitter : public MCCodeEmitter {
  MCContext &Ctx;
  MCInstrInfo const &MCII;

public:
  V3DMCCodeEmitter(MCContext &Ctx, MCInstrInfo const &MCII)
      : Ctx(Ctx), MCII(MCII) {}
  ~V3DMCCodeEmitter() override = default;

  void encodeInstruction(const MCInst &Inst, SmallVectorImpl<char> &CB,
                         SmallVectorImpl<MCFixup> &Fixups,
                         const MCSubtargetInfo &STI) const override;
};

} // namespace

MCCodeEmitter *llvm::createV3DMCCodeEmitter(const MCInstrInfo &MCII,
                                            MCContext &Ctx) {
  return new V3DMCCodeEmitter(Ctx, MCII);
}

void V3DMCCodeEmitter::encodeInstruction(const MCInst &Inst,
                                         SmallVectorImpl<char> &CB,
                                         SmallVectorImpl<MCFixup> &Fixups,
                                         const MCSubtargetInfo &STI) const {}
