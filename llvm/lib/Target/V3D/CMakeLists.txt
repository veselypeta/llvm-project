add_llvm_component_group(V3D)

set(LLVM_TARGET_DEFINITIONS V3D.td)

tablegen(LLVM V3DGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM V3DGenDisassemblerTables.inc -gen-disassembler)
tablegen(LLVM V3DGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM V3DGenMCCodeEmitter.inc -gen-emitter)
tablegen(LLVM V3DGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM V3DGenSubtargetInfo.inc -gen-subtarget)

add_public_tablegen_target(V3DCommonTableGen)

add_llvm_target(V3DCodeGen
  V3DTargetMachine.cpp

  LINK_COMPONENTS
  MC
  Support
  Target
  TargetParser
  V3DInfo

  ADD_TO_COMPONENT
  V3D
)

add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)
