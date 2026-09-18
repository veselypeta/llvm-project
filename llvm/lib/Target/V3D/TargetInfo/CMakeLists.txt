add_llvm_component_library(LLVMV3DInfo
  V3DTargetInfo.cpp

  LINK_COMPONENTS
  Support
  MC

  ADD_TO_COMPONENT
  V3D
)
