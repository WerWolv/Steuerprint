/*********************************************\
|	 _____      _   _   _                  	  |
|	/  ___|    | | | | (_)                 	  |
|	\ `--.  ___| |_| |_ _ _ __   __ _ ___  	  |
|	 `--. \/ _ \ __| __| | '_ \ / _` / __| 	  |
|	/\__/ /  __/ |_| |_| | | | | (_| \__ \ 	  |
|	\____/ \___|\__|\__|_|_| |_|\__, |___/ 	  |
|								 __/ |     	  |
|								|___/      	  |
|											  |
\*********************************************/


#define V
#define A * 1000
#define mA
#define Ohm

//LEISTUNGSTEIL
	#define UOUTMAX 15.0F V	//Maximale Ausgangsspannung des Netzger�tes
	#define IOUTMAX 1000.0F mA	//Maximaler Ausgamgsstrom des Netzger�tes

//ADC / DAC
	#define UREF 3.3F V		//Referenzspannung (Im Moment 3.3V von der Speissung)
	
	#define SPANNUNGSTEILER ((8200.0F Ohm + 1200.0F Ohm) / 1200.0F Ohm)	//Spannungsteiler f�r Spannungsr�ckkopplung
	
	#define VOLTS_PER_AMP 3.0F V //Einstellung des Instrumentenverst�rkers 

//ENCODER
	#define VOLTS_PER_STEP 0.1F V		//Ver�nderung der Spannung pro Encoder Step
	#define AMPS_PER_STEP 0.001F	A//Ver�nderung des Stromes pro Encoder Step
	
	#define FAST_STEP_FREQUENCY	5	//Wieviele Schritte pro Sekunde z�hlen als schnelles drehen
	#define FAST_MULTIPLICATOR 10	//Multiplikator bei schnellerem Drehen des Encoders
//SCREEN	
	#define UI_DISPLAY_FADEOUT_TIME 