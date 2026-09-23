
class V3DInst<dag outs, dag ins, string asmstr, list<dag> pattern> 
      : Instruction {
  let Namespace = "V3D";
  let OutOperandList = outs;
  let InOperandList = ins;
  let AsmString = asmstr;
  let Pattern = pattern;
  field bits<32> Inst;
  field bits<32> SoftFail = 0;
  let Size = 4;
}


def NOP : V3DInst<(outs), (ins), "nop", []> {
  let Inst = 0x00000000;
}
