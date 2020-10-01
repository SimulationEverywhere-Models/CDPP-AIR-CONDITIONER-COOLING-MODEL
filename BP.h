 #ifndef __BP_H
 #define __BP_H

 #include "atomic.h"
 #include "string.h"

 class BP : public Atomic
 {
   public:
	       BP( const std::string &name = "BP" );
	       virtual std::string className() const {  return "BP" ;}
	       ~BP();

   protected:
	          Model &initFunction();
	          Model &externalFunction( const ExternalMessage & );
	          Model &internalFunction( const InternalMessage & );
	          Model &outputFunction( const InternalMessage & );

   private:
	        const Port &InB;
	        const Port &InM;
	        const Port &Temp;
	        Port &Blow;
	        Port &Out;
	        Time ProcessTime;
	        int curtemp,settemp,blow;
 };

#endif
