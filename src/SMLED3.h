#ifndef SMLED3_H
#define SMLED3_H


typedef enum{
	INITIAL,
	Led3On, //LED TURN ON 
	Led3Off, //LED TURN OFF 
	FINAL
}State;

int LED3_SM(State *state, int previousTime,int counter);


#endif // SMLED3_H
