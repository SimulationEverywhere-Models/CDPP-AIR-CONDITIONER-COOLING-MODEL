 #include "TP.h"
 #include "message.h"
 #include "math.h"

 TP::TP( const std::string &name ) : Atomic( name )
 , InT(addInputPort( "InT" ))
 , InM(addInputPort( "InM" ))
 , Blow(addInputPort( "Blow" ))
 , Temp(addOutputPort( "Temp" ))
 , Out(addOutputPort( "Out" ))
 , ProcessTime (00,00,00,5)
 {
 }

 Model &TP::initFunction()
  {
	this-> passivate();
	curtemp=24;
	blow=1;
	settemp=24;
	outstate=0;
	return *this ;
  }


 Model &TP::externalFunction( const ExternalMessage &msg )
  {
	if (msg.port() == InT ){
		settemp=msg.value();
		outstate=1;
		cout<<"TP recieve data from INT"<<endl;
		holdIn(Atomic::active, ProcessTime);
	}
	if (msg.port() == InM){
		curtemp=msg.value();
		holdIn(Atomic::active, ProcessTime);
		cout<<"TP recieve data from INM"<<endl;
	}
	if (msg.port()== Blow){
		blow=msg.value();
		holdIn(Atomic::active, ProcessTime);
		cout<<"TP recieve data from BP"<<endl;
	}
	cout<<"TP state: "<<settemp<<" "<<curtemp<<" "<<blow<<" at "<<msg.time()<<endl;
	return *this;
  }


 Model &TP::internalFunction( const InternalMessage & )
 {
    passivate();
    return *this;
 }


 Model &TP::outputFunction( const InternalMessage &msg )
 {
	 cout<<"TP outstate="<<outstate<<endl;
	if (outstate == 1){
		sendOutput(msg.time(),Temp,settemp);
		outstate=0;
		holdIn(Atomic::active, ProcessTime);
	}
	else{
		int difftemp=curtemp-settemp;
		if (difftemp<0) difftemp=0;
		int outtemp=(int)(difftemp*sqrt(blow)/3+settemp);
		cout<<"Temperature Output: "<<outtemp<<" at "<<msg.time()<<endl;
		sendOutput( msg.time(), Out, outtemp) ;
	}
	return *this ;
 }

 /*********************************************************/
 TP::~TP()
 {
 }

