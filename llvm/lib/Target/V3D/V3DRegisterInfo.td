
class V3DReg<bits<16> enc, string n> : Register<n> {
  let HWEncoding = enc;
  let Namespace = "V3D";
}

foreach i = 0-31 in {
  def R#i : V3DReg<i, "r"#i>;
}

def GPR32 : RegisterClass<"V3D", [i32], 32, (sequence "R%u", 0, 31)>;
