//This code monitors a stage flood sensor, and plays an alarm if liquid hits the sensor.
//Pin assignment: A0 to read the sensor, 6 and 7 to run the piezo alarm
//NOTE: This code requires port manipulations to play the alarm tone, so pin assignments are fixed.

//Alarm settings
const uint16_t TONE_DURATION = 500; //Duration of a single beep in multiples of 256µs
const uint8_t TONE_REP = 3; //Number ot times to repeat beep per sequence
const uint16_t TONE_PAUSE = 500; //How long to pause between beep sequences in ms
const uint8_t BOOT_VOLUME = 10; //Beep volume - 0=off; 128 = full volume; 255 = off;
const uint8_t ALARM_VOLUME = 128; //Beep volume - 0=off; 128 = full volume; 255 = off;
const uint16_t THRESHOLD = 60000; //Threshold adc value that triggers the alarm - 0-65472, higher values = more sensitive.

//Global variables
uint16_t adc; //Stores the recorded adc values
uint8_t avg; //Sample averaging counter
uint8_t beep; //Stores duration of second phase of beep cycle

void setup() {
  //Configure the digital pins
  DDRD = B11111100; //Set alarm pins as outputs
  pinMode(LED_BUILTIN, OUTPUT); //Set LED as output
  digitalWrite(LED_BUILTIN, LOW); //Turn off LED

  //Clear ADC
  analogRead(A0);
  analogRead(A0);

  //Play boot tone
  playBeep(BOOT_VOLUME);
}

void loop() {
  //Measure sensor plate resistivity
  avg = 64;
  adc = 0;
  while(avg--) adc += analogRead(A0); 

  //If resistivity is below threshold, play alarm
  if(adc < THRESHOLD){ 
    avg = TONE_REP;
    while(avg--) playBeep(ALARM_VOLUME);
    delay(TONE_PAUSE);
  }
}

void playBeep(uint8_t set_volume){
  adc = TONE_DURATION;
  beep = 255-set_volume;
  digitalWrite(LED_BUILTIN, HIGH); //Turn on LED
  while(adc--){ //Play tone
    PORTD = B10000000;
    delayMicroseconds(set_volume);
    PORTD = B01000000;
    delayMicroseconds(beep);
  }
  adc = TONE_DURATION; //Pause tone
  digitalWrite(LED_BUILTIN, LOW); //Turn off LED
  while(adc--) delayMicroseconds(255);
}
