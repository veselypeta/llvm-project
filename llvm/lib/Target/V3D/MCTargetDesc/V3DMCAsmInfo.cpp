#include "MCTargetDesc/V3DMCAsmInfo.h"

using namespace llvm;

void V3DMCAsmInfo::anchor() {}

V3DMCAsmInfo::V3DMCAsmInfo(const Triple &T, const MCTargetOptions &Options)
    : MCAsmInfoELF(Options) {}
