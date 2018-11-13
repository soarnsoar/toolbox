#ref : https://root-forum.cern.ch/t/automatically-load-so-libraries-upon-entering-root/21007/2
#ref : https://root-forum.cern.ch/t/how-to-change-default-rootlogon-c-file/23883


echo "====Hello:) Welcome to jhchoi's tool box===="


#export ROOTETCDIR=$PWD:$ROOTETCDIR
echo "====Create \"rootlogon.C\"===="
echo """
{
  gSystem->Load(\"$PWD/Find_and_add_histo/Find_and_add_histo_cc.so\");
  gSystem->Load(\"$PWD/Get_envelop/Get_envelop_cc.so\");
  gSystem->Load(\"$PWD/Get_envelop_histo/Get_envelop_histo_cc.so\");
  gSystem->Load(\"$PWD/Get_variance/Get_variance_cc.so\");
  gSystem->Load(\"$PWD/Get_sys_hessian/Get_sys_hessian_cc.so\");
  gROOT->ProcessLine(\".include $PWD\");
}
""">rootlogon.C

echo "====compile my libraries==="
ARR=("Find_and_add_histo" "Get_envelop" "Get_sys_hessian" "Get_envelop_histo" "Get_variance")
#ARR=($(ls -d */))
for dir in ${ARR[@]}; do
    pushd $dir;source compile.sh;popd
done


echo "====add current path to link the toolbox and rootlogon.C===="
echo "Rint.Logon: $PWD/rootlogon.C" >> ~/.rootrc
echo "====Finish compiling my lib====Thanks :)"