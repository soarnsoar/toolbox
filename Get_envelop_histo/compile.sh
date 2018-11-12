root -b -l <<EOF

gSystem->Load("../Get_envelop/Get_envelop_cc.so")
gSystem->Load("../Get_sys_hessian/Get_sys_hessian_cc.so")
.include ../
.L Get_envelop_histo.cc++
EOF