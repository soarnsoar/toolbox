rm rootlogon.C
rm */*.so
rm */*.d
rm */*.pcm
echo "clean .rootrc"
pushd ~
#find . -name ".rootrc"  | xargs perl -pi -e 's/"Rint.Logon: $PWD\/rootlogon.C"//g'
cat ~/.rootrc | grep -v "Rint.Logon: $PWD\/rootlogon.C" > ~/.rootrc
popd
echo "FIN."