 #include "BP.h"
 #include "message.h"       // InternalMessage ....

 BP::BP( const std::string &name ) : Atomic( name )
 , InB(addInputPort( "InB" ))
 , InM(addInputPort( "InM" ))
 , Temp(addInputPort( "Temp" ))
 , Blow(addOutputPort( "Blow" ))
 , Out(addOutputPort( "Out" ))
 , ProcessTime (00,00,00,5)
 {
 }

 Model &BP::initFunction()
  {
	curtemp=24;
	blow=1;
	settemp=24;
	return *this ;
  }


 Model &BP::externalFunction( const ExternalMessage &msg )
  {
	if (msg.port() == InB){
		cout<<"BP recieve data from INB"<<endl;
		blow=msg.value();
	    holdIn(active, ProcessTime);
	}
	if (msg.port() == InM){
		cout<<"BP recieve data from INM"<<endl;
		curtemp=msg.value();
	    holdIn(active, ProcessTime);
	}
	if (msg.port() == Temp){
		cout<<"BP recieve data from TP"<<endl;
		settemp=msg.value();
	    holdIn(Atomic::active, ProcessTime);
	}
	cout<<"BP state: "<<settemp<<" "<<curtemp<<" "<<blow<<" at "<<msg.time()<<endl;
	return *this;
  }


 Model &BP::internalFunction( const InternalMessage & )
 {
	this->passivate();
    return *this;
 }


 Model &BP::outputFunction( const InternalMessage &msg )
 {
	int outblow,difftemp;
	difftemp=curtemp-settemp;
	if (difftemp<0) difftemp=0;
	if (blow!=0) outblow=blow;
	else
		if (difftemp==0) outblow=1;
		else
			if (difftemp<3) outblow=2;
			else
				if (difftemp<6) outblow=3;
				else
					if (difftemp<9) outblow=4;
					else
						if (difftemp<12) outblow=5;
						else
							outblow=6;
	cout<<"Blow Rate: "<<outblow<<" at "<<msg.time()<<endl;
	this->sendOutput( msg.time(), Blow, outblow) ;
	this->sendOutput( msg.time(), Out, outblow) ;
	return *this ;
 }

 /*********************************************************/
 BP::~BP()
 {
 }

