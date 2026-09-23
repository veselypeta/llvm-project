add_llvm_component_library(LLVMV3DDisassembler
  V3DDisassembler.cpp

  LINK_COMPONENTS
  MC
  MCDisassembler
  V3DDesc
  V3DInfo
  Support

  ADD_TO_COMPONENT
  V3D
)
