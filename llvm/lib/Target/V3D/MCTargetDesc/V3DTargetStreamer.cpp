#include "MCTargetDesc/V3DTargetStreamer.h"
#include "llvm/MC/MCStreamer.h"

using namespace llvm;

V3DTargetStreamer::V3DTargetStreamer(MCStreamer &S) : MCTargetStreamer(S) {}

V3DTargetAsmStreamer::V3DTargetAsmStreamer(MCStreamer &S,
                                           formatted_raw_ostream &OS)
    : V3DTargetStreamer(S), OS(OS) {}
