add_llvm_component_library(LLVMV3DAsmParser
  V3DAsmParser.cpp

  LINK_COMPONENTS
  MC
  MCParser
  V3DDesc
  V3DInfo
  Support
  TargetParser

  ADD_TO_COMPONENT
  V3D
)
