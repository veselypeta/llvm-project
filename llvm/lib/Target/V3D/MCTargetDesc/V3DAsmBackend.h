#ifndef LLVM_LIB_TARGET_V3D_MCTARGETDESC_V3DASMBACKEND_H
#define LLVM_LIB_TARGET_V3D_MCTARGETDESC_V3DASMBACKEND_H

#include "llvm/MC/MCAsmBackend.h"
#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/MC/MCTargetOptions.h"

namespace llvm {
class MCAssembler;
class MCObjectTargetWriter;
class raw_ostream;

class V3DAsmBackend : public MCAsmBackend {
  const MCSubtargetInfo &STI;
  const MCTargetOptions &TargetOptions;
  uint8_t OSABI;

public:
  V3DAsmBackend(const MCSubtargetInfo &STI, const MCTargetOptions &Opts);
  ~V3DAsmBackend() override = default;

  std::unique_ptr<MCObjectTargetWriter>
  createObjectTargetWriter() const override;

  void applyFixup(const MCFragment &, const MCFixup &, const MCValue &Target,
                  uint8_t *Data, uint64_t Value, bool IsResolved) override;

  bool writeNopData(raw_ostream &OS, uint64_t Count,
                    const MCSubtargetInfo *STI) const override;
};
} // namespace llvm

#endif // LVM_LIB_TARGET_V3D_MCTARGETDESC_V3DASMBACKEND_H
