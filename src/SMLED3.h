#ifndef SMLED3_H
#define SMLED3_H


typedef enum{
	INITIAL,
	STATEA, //LED TURN ON 
	STATEB, //LED TURN OFF 
	FINAL
}State;

int LED3_SM(State *state);

#endif // SMLED3_H
