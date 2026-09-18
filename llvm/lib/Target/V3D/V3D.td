include "llvm/Target/Target.td"

include "V3DRegisterInfo.td"
include "V3DInstrInfo.td"

def V3DInstrInfo : InstrInfo;

defm : RemapAllTargetPseudoPointerOperands<GPR32>;

def V3D : Target {
  let InstructionSet = V3DInstrInfo;
}
