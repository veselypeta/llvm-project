add_llvm_component_library(LLVMV3DDesc
  V3DAsmBackend.cpp
  V3DELFObjectWriter.cpp
  V3DELFStreamer.cpp
  V3DInstPrinter.cpp
  V3DMCAsmInfo.cpp
  V3DMCCodeEmitter.cpp
  V3DMCTargetDesc.cpp
  V3DTargetStreamer.cpp

  LINK_COMPONENTS
  MC
  Support
  V3DInfo

  ADD_TO_COMPONENT
  V3D
)
