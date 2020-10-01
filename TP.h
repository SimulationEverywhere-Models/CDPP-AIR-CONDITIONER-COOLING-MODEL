 #ifndef __TP_H
 #define __TP_H

 #include "atomic.h"
 #include "string.h"

 class TP : public Atomic
 {
   public:
	       TP( const std::string &name = "TP" );
	       virtual std::string className() const {  return "TP" ;}
	       ~TP();

   protected:
	          Model &initFunction();
	          Model &externalFunction( const ExternalMessage & );
	          Model &internalFunction( const InternalMessage & );
	          Model &outputFunction( const InternalMessage & );

   private:
	          const Port &InT;
	          const Port &InM;
	          const Port &Blow;
	          Port &Temp;
	          const Port &Out;
	          Time ProcessTime;
	          int curtemp,settemp,blow,outstate;
 };

#endif
