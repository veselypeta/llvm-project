#include "MCTargetDesc/V3DMCTargetDesc.h"
#include "MCTargetDesc/V3DELFStreamer.h"
#include "TargetInfo/V3DTargetInfo.h"
#include "V3DAsmBackend.h"
#include "V3DInstPrinter.h"
#include "V3DMCAsmInfo.h"
#include "V3DTargetStreamer.h"
#include "llvm/MC/LaneBitmask.h"
#include "llvm/MC/MCAsmBackend.h"
#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/MC/MCInstrAnalysis.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Compiler.h"
#include "llvm/Support/FormattedStream.h"
#include <memory>

using namespace llvm;

#define GET_INSTRINFO_MC_DESC
#include "V3DGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "V3DGenSubtargetInfo.inc"

#define GET_REGINFO_MC_DESC
#include "V3DGenRegisterInfo.inc"

namespace {
class V3DMCInstrAnalysis : public MCInstrAnalysis {

public:
  explicit V3DMCInstrAnalysis(const MCInstrInfo *Info)
      : MCInstrAnalysis(Info) {}
};

} // namespace

static MCAsmInfo *createV3DMCAsmInfo(const MCRegisterInfo &MRI, const Triple &T,
                                     const MCTargetOptions &Opts) {
  return new V3DMCAsmInfo(T, Opts);
}

static MCInstrInfo *createV3DMCInstrInfo() {
  MCInstrInfo *MII = new MCInstrInfo();
  InitV3DMCInstrInfo(MII);
  return MII;
}

static MCRegisterInfo *createV3DMCRegisterInfo(const Triple &T) {
  MCRegisterInfo *MRI = new MCRegisterInfo();
  InitV3DMCRegisterInfo(MRI, V3D::R0);
  return MRI;
}

static MCInstPrinter *createV3DMCInstPrinter(const Triple &T,
                                             unsigned SyntaxVariant,
                                             const MCAsmInfo &MAI,
                                             const MCInstrInfo &MII,
                                             const MCRegisterInfo &MRI) {
  return new V3DInstPrinter(MAI, MII, MRI);
}

static MCSubtargetInfo *createV3DMCSubtargetInfo(const Triple &T, StringRef CPU,
                                                 StringRef FS) {
  MCSubtargetInfo *X = createV3DMCSubtargetInfoImpl(T, CPU, CPU, FS);
  return X;
}

static MCTargetStreamer *
createV3DObjectTargetStreamer(MCStreamer &S, const MCSubtargetInfo &STI) {
  return new V3DTargetELFStreamer(S);
}

static MCTargetStreamer *createV3DAsmTargetStreamer(MCStreamer &S,
                                                    formatted_raw_ostream &OS,
                                                    MCInstPrinter *InstPrint) {
  return new V3DTargetAsmStreamer(S, OS);
}

static MCInstrAnalysis *createV3DInstrAnalysis(const MCInstrInfo *Info) {
  return new V3DMCInstrAnalysis(Info);
}

static MCTargetStreamer *createV3DNullTargetStreamer(MCStreamer &S) {
  return new V3DTargetStreamer(S);
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeV3DTargetMC() {

  TargetRegistry::RegisterMCAsmInfo(getTheV3DTarget(), createV3DMCAsmInfo);
  TargetRegistry::RegisterMCInstrInfo(getTheV3DTarget(), createV3DMCInstrInfo);
  TargetRegistry::RegisterMCRegInfo(getTheV3DTarget(), createV3DMCRegisterInfo);
  TargetRegistry::RegisterMCAsmBackend(getTheV3DTarget(), createV3DAsmBackend);
  TargetRegistry::RegisterMCCodeEmitter(getTheV3DTarget(),
                                        createV3DMCCodeEmitter);
  TargetRegistry::RegisterMCInstPrinter(getTheV3DTarget(),
                                        createV3DMCInstPrinter);
  TargetRegistry::RegisterMCSubtargetInfo(getTheV3DTarget(),
                                          createV3DMCSubtargetInfo);
  TargetRegistry::RegisterELFStreamer(getTheV3DTarget(), createV3DELFStreamer);
  TargetRegistry::RegisterObjectTargetStreamer(getTheV3DTarget(),
                                               createV3DObjectTargetStreamer);
  TargetRegistry::RegisterMCInstrAnalysis(getTheV3DTarget(),
                                          createV3DInstrAnalysis);

  TargetRegistry::RegisterAsmTargetStreamer(getTheV3DTarget(),
                                            createV3DAsmTargetStreamer);
  TargetRegistry::RegisterNullTargetStreamer(getTheV3DTarget(),
                                             createV3DNullTargetStreamer);
}
