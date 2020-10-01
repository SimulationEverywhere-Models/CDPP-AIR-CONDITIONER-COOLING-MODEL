
 #include <modeladm.h>
 #include <mainsimu.h>

 #include "TM.h"
 #include "BM.h"
 #include "TP.h"
 #include "BP.h"

 void MainSimulator::registerNewAtomics()
 {
   SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<TM>() , "TM" ) ;
   SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<BM>() , "BM" ) ;
   SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<TP>() , "TP" ) ;
   SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<BP>() , "BP" ) ;
 }
