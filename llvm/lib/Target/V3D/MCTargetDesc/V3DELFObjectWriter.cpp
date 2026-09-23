#include "MCTargetDesc/V3DMCTargetDesc.h"
#include "llvm/MC/MCELFObjectWriter.h"

using namespace llvm;

namespace {
class V3DELFObjectWriter : public MCELFObjectTargetWriter {
public:
  V3DELFObjectWriter(uint8_t OSABI);
  unsigned getRelocType(const MCFixup &Fixup, const MCValue &Target,
                        bool IsPCRel) const override;
};
} // namespace

V3DELFObjectWriter::V3DELFObjectWriter(uint8_t OSABI)
    : MCELFObjectTargetWriter(/*Is64Bit*/ false, OSABI, ELF::EM_V3D,
                              /*HasRelocationAddend*/ false) {}

unsigned V3DELFObjectWriter::getRelocType(const MCFixup &Fixup,
                                          const MCValue &Target,
                                          bool IsPCRel) const {
  return 0;
}

std::unique_ptr<MCObjectTargetWriter>
llvm::createV3DELFObjectWriter(uint8_t OSABI) {
  return std::make_unique<V3DELFObjectWriter>(OSABI);
}
