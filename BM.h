 #ifndef __BM_H
 #define __BM_H

 #include "atomic.h"
 #include "string.h"

 class BM : public Atomic
 {
   public:
	       BM( const std::string &name = "BM" );
	       virtual std::string className() const {  return "BM" ;}
	       ~BM();

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
