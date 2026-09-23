#ifndef LLVM_LIB_TARGET_RISCV_MCTARGETDESC_V3DINSTPRINTER_H
#define LLVM_LIB_TARGET_RISCV_MCTARGETDESC_V3DINSTPRINTER_H

#include "llvm/MC/MCInstPrinter.h"
namespace llvm {

class V3DInstPrinter : public MCInstPrinter {
public:
  V3DInstPrinter(const MCAsmInfo &MAI, const MCInstrInfo &MII,
                 const MCRegisterInfo &MRI)
      : MCInstPrinter(MAI, MII, MRI) {}

  void printInst(const MCInst *MI, uint64_t Address, StringRef Annot,
                 const MCSubtargetInfo &STI, raw_ostream &OS) override;

  // tablegen'd
  std::pair<const char *, uint64_t>
  getMnemonic(const MCInst &MI) const override;

  void printInstruction(const MCInst *MI, uint64_t Address, raw_ostream &O);
  const char *getRegisterName(MCRegister Reg);
  bool printAliasInstr(const MCInst *MI, uint64_t Address, raw_ostream &OS);
};

} // namespace llvm
#endif // LLVM_LIB_TARGET_RISCV_MCTARGETDESC_V3DINSTPRINTER_H
