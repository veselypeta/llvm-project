#include "MCTargetDesc/V3DMCTargetDesc.h"
#include "TargetInfo/V3DTargetInfo.h"
#include "llvm/MC/MCParser/MCParsedAsmOperand.h"
#include "llvm/MC/MCParser/MCTargetAsmParser.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Compiler.h"
#include "llvm/Support/SMLoc.h"
#include "V3DInstrInfo.h"

using namespace llvm;

#define DEBUG_TYPE "v3d-asm-parser"

namespace {
struct V3DOperand;

class V3DAsmParser : public llvm::MCTargetAsmParser {
public:
  bool parseRegister(MCRegister &Reg, SMLoc &StartLoc, SMLoc &EndLoc) override;

  ParseStatus tryParseRegister(MCRegister &Reg, SMLoc &StartLoc,
                               SMLoc &EndLoc) override;
  bool parseInstruction(ParseInstructionInfo &Info, StringRef Name,
                        SMLoc NameLoc, OperandVector &Operands) override;
  bool matchAndEmitInstruction(SMLoc IDLoc, unsigned &Opcode,
                               OperandVector &Operands, MCStreamer &Out,
                               uint64_t &ErrorInfo,
                               bool MatchingInlineAsm) override;

#define GET_ASSEMBLER_HEADER
#include "V3DGenAsmMatcher.inc"
  V3DAsmParser(const MCSubtargetInfo &STI, MCAsmParser &Parser,
               const MCInstrInfo &MII)
      : MCTargetAsmParser(STI, MII) {
    MCAsmParserExtension::Initialize(Parser);
  }

  enum V3DMatchResultTy : unsigned {
    Match_Dummy = FIRST_TARGET_MATCH_RESULT_TY,
#define GET_OPERAND_DIAGNOSTIC_TYPES
#include "V3DGenAsmMatcher.inc"

  };
};

struct V3DOperand final : public MCParsedAsmOperand {
  enum class KindTy {
    Token,
    Register,
    Imm,
  } Kind;

public:
  V3DOperand(const V3DOperand &O) : MCParsedAsmOperand() { Kind = O.Kind; }

  bool isToken() const override { return Kind == KindTy::Token; }
  bool isImm() const override { return Kind == KindTy::Imm; }
  bool isReg() const override { return Kind == KindTy::Register; }
  MCRegister getReg() const override { return 0; }
  bool isMem() const override { return false; }

  SMLoc getStartLoc() const override { return SMLoc(); };
  SMLoc getEndLoc() const override { return SMLoc(); };

  void print(raw_ostream &, const MCAsmInfo &) const override {};

  // tablegen'd
  void addRegOperands(MCInst &Inst, unsigned N) const {}
  void addImmOperands(MCInst &Inst, unsigned N) const {}
  StringRef getToken() const { return ""; }
};

} // namespace

#define GET_REGISTER_MATCHER
#define GET_SUBTARGET_FEATURE_NAME
#define GET_MATCHER_IMPLEMENTATION
#define GET_MNEMONIC_SPELL_CHECKER
#include "V3DGenAsmMatcher.inc"

bool V3DAsmParser::parseRegister(MCRegister &Reg, SMLoc &StartLoc,
                                 SMLoc &EndLoc) {
  return false;
}

ParseStatus V3DAsmParser::tryParseRegister(MCRegister &Reg, SMLoc &StartLoc,
                                           SMLoc &EndLoc) {
  return ParseStatus::Failure;
}

bool V3DAsmParser::parseInstruction(ParseInstructionInfo &Info, StringRef Name,
                                    SMLoc NameLoc, OperandVector &Operands) {
  return false;
}

bool V3DAsmParser::matchAndEmitInstruction(SMLoc IDLoc, unsigned &Opcode,
                                           OperandVector &Operands,
                                           MCStreamer &Out, uint64_t &ErrorInfo,
                                           bool MatchingInlineAsm) {
  return false;
}

extern "C" LLVM_ABI LLVM_EXTERNAL_VISIBILITY void LLVMInitializeV3DAsmParser() {
  RegisterMCAsmParser<V3DAsmParser> X(getTheV3DTarget());
}
