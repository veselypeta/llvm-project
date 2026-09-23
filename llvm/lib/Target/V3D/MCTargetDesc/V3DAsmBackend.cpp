#include "MCTargetDesc/V3DAsmBackend.h"
#include "MCTargetDesc/V3DMCTargetDesc.h"
#include "llvm/MC/MCObjectWriter.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/MCTargetOptions.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

V3DAsmBackend::V3DAsmBackend(const MCSubtargetInfo &STI,
                             const MCTargetOptions &Opts)
    : MCAsmBackend(llvm::endianness::little), STI(STI), TargetOptions(Opts) {}

std::unique_ptr<MCObjectTargetWriter>
V3DAsmBackend::createObjectTargetWriter() const {
  return createV3DELFObjectWriter(OSABI);
}

void V3DAsmBackend::applyFixup(const MCFragment &, const MCFixup &,
                               const MCValue &Target, uint8_t *Data,
                               uint64_t Value, bool IsResolved) {}

bool V3DAsmBackend::writeNopData(raw_ostream &OS, uint64_t Count,
                                 const MCSubtargetInfo *STI) const {
  return false;
}

MCAsmBackend *llvm::createV3DAsmBackend(const Target &T,
                                        const MCSubtargetInfo &STI,
                                        const MCRegisterInfo &MRI,
                                        const MCTargetOptions &Options) {
  return new V3DAsmBackend(STI, Options);
}
