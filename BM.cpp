 #include "BM.h"
 #include "message.h"       // InternalMessage ....

 BM::BM( const std::string &name ) : Atomic( name )
 , In(addInputPort( "In" ))
 , Out(addOutputPort( "Out" ))
 , ProcessTime (00,00,00,5)
 {
 }

 Model &BM::initFunction()
  {
	state = 1;
	return *this ;
  }


 Model &BM::externalFunction( const ExternalMessage &msg )
  {
	if (msg.port() == In){
		if (msg.value()<0)
			state=0;
		else
			if (msg.value()>6)
				state=6;
			else
				state=msg.value();
	    cout<<"User set the blow rate:"<<state<<endl;
	}
    holdIn(Atomic::active, ProcessTime);
	return *this;
  }


 Model &BM::internalFunction( const InternalMessage & )
 {
	this->passivate();
    return *this;
 }


 Model &BM::outputFunction( const InternalMessage &msg )
 {
	this->sendOutput( msg.time(), Out, state) ;
	return *this ;
 }

 /*********************************************************/
 BM::~BM()
 {
 }

