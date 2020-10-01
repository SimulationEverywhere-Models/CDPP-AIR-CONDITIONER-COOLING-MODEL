 #ifndef __TM_H
 #define __TM_H

 #include "atomic.h"
 #include "string.h"

 class TM : public Atomic
 {
   public:
	       TM( const std::string &name = "TM" );
	       virtual std::string className() const {  return "TM" ;}
	       ~TM();

   protected:
	          Model &initFunction();
	          Model &externalFunction( const ExternalMessage & );
	          Model &internalFunction( const InternalMessage & );
	          Model &outputFunction( const InternalMessage & );

   private:
	          const Port &In;
	          Port &Out;
	          Time ProcessTime;
	          int state;
 };

#endif
