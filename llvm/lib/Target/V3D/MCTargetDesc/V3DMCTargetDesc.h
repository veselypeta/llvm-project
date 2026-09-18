#ifndef LLVM_LIB_TARGET_V3D_MCTARGETDESC_V3DMCTARGETDESC_H
#define LLVM_LIB_TARGET_V3D_MCTARGETDESC_V3DMCTARGETDESC_H

#include "llvm/MC/MCTargetOptions.h"

namespace llvm {
class MCCodeEmitter;
class MCInstrInfo;
class MCRegisterInfo;
class Target;
class MCSubtargetInfo;
class MCAsmBackend;
class MCObjectTargetWriter;
class MCContext;



MCCodeEmitter *createV3DMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);

MCAsmBackend *createV3DAsmBackend(const Target &T, const MCSubtargetInfo &STI,
                                  const MCRegisterInfo &MRI,
                                  const MCTargetOptions &Options);

std::unique_ptr<MCObjectTargetWriter> createV3DELFObjectWriter(uint8_t OSABI);

} // namespace llvm

#define GET_REGINFO_ENUM
#include "V3DGenRegisterInfo.inc"

#define GET_INSTR_INFO_ENUM
#define GET_INTRINFO_MC_HELPER_DECLS
#define GET_INSTR_INFO_OPERAND_ENUM
#include "V3DGenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "V3DGenSubtargetInfo.inc"

#endif // LLVM_LIB_TARGET_V3D_MCTARGETDESC_V3DMCTARGETDESC_H
