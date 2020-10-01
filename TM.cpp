 #include "TM.h"
 #include "message.h"       // InternalMessage ....

 TM::TM( const std::string &name ) : Atomic( name )
 , In(addInputPort( "In" ))
 , Out(addOutputPort( "Out" ))
  , ProcessTime (00,00,00,5)
 {
 }

 Model &TM::initFunction()
  {
	this-> passivate();
	state=24;
	return *this ;
  }


 Model &TM::externalFunction( const ExternalMessage &msg )
  {

	if (msg.port() == In ){
		if (msg.value()==0)
			state=24;
		else
			if (msg.value()<16)
				state=16;
			else
				if (msg.value()>28)
					state=28;
				else
					state=msg.value();
	    cout<<"User set the temperature:"<<state<<endl;
	}
	holdIn(Atomic::active, ProcessTime);
	return *this;
  }


 Model &TM::internalFunction( const InternalMessage & )
 {
	this->passivate();
    return *this;
 }


 Model &TM::outputFunction( const InternalMessage &msg )
 {
	this->sendOutput( msg.time(), Out, state) ;
	return *this ;
 }

 /*********************************************************/
 TM::~TM()
 {
 }

