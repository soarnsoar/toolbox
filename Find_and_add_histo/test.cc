#include <iostream>
#include <TH1D.h>
#include <vector>
#include <TSystem.h>









class test{

public:
  test();

};
test::test(){
  //  std::vector<TH1D*> vH;
  //  Find_and_add_histo("/cms/ldap_home/jhchoi/generator_group/reweight_issue/plotter/histosets/242LO_false_pdfwgt.root","scale","Z_pt",&vH);
  //  gSystem->Load("/cms/ldap_home/jhchoi/test/shared_lib/print/src/print_cc.so");
  //  R__LOAD_LIBRARY("/cms/ldap_home/jhchoi/test/shared_lib/print/src/print_cc.so");
  print aa;
}
