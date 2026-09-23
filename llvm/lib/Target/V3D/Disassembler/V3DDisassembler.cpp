#include "TargetInfo/V3DTargetInfo.h"
#include "llvm-c/Target.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCDisassembler/MCDisassembler.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Compiler.h"

using namespace llvm;

namespace {
class V3DDisassembler : public MCDisassembler {
public:
  V3DDisassembler(const MCSubtargetInfo &STI, MCContext &Ctx)
      : MCDisassembler(STI, Ctx) {}

  DecodeStatus getInstruction(MCInst &Instr, uint64_t &Size,
                              ArrayRef<uint8_t> Bytes, uint64_t Address,
                              raw_ostream &CStream) const override {
    return DecodeStatus::Fail;
  }
};
} // namespace

static MCDisassembler *createV3DDisassembler(const Target &T,
                                             const MCSubtargetInfo &STI,
                                             MCContext &Ctx) {
  return new V3DDisassembler(STI, Ctx);
}

extern "C" LLVM_ABI LLVM_EXTERNAL_VISIBILITY void
LLVMInitializeV3DDisassembler() {
  TargetRegistry::RegisterMCDisassembler(getTheV3DTarget(),
                                         createV3DDisassembler);
}
