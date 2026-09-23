#include "MCTargetDesc/V3DInstPrinter.h"
#include "llvm/MC/MCInst.h"

using namespace llvm;

#define DEBUG_TYPE "asm-printer"

#define PRINT_ALIAS_INSTR
#include "V3DGenAsmWriter.inc"

void V3DInstPrinter::printInst(const MCInst *MI, uint64_t Address,
                               StringRef Annot, const MCSubtargetInfo &STI,
                               raw_ostream &OS) {}
