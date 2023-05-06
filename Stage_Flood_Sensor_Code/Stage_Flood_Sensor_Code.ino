uint16_t adc;
uint8_t avg;
const uint16_t TONE_DURATION = 500; //Duration of a single beep in multiples of 256µs
const uint8_t TONE_REP = 3; //Number ot times to repeat beep per sequence
const uint16_t TONE_PAUSE = 500; //How long to pause between beep sequences in ms
const uint8_t VOLUME = 128; //Beep volume - 0=off; 128 = full volume; 255 = off;
const uint8_t BEEP = 255-VOLUME;
const uint16_t THRESHOLD = 40000;

void setup() {
  Serial.begin(115200);
  //Clear ADC
  analogRead(A0);
  analogRead(A0);
  DDRD = B11111100;
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  playBeep();
}

void loop() {
  avg = 64;
  adc = 0;
  while(avg--) adc += analogRead(A0);
  if(adc < THRESHOLD){
    avg = TONE_REP;
    while(avg--) playBeep();
    delay(TONE_PAUSE);
  }
}

void playBeep(){
  adc = TONE_DURATION;
  digitalWrite(LED_BUILTIN, HIGH);
  while(adc--){ //Play tone
    PORTD = B01000000;
    delayMicroseconds(VOLUME);
    PORTD = B10000000;
    delayMicroseconds(BEEP);
  }
  adc = TONE_DURATION; //Pause tone
  digitalWrite(LED_BUILTIN, LOW);
  while(adc--) delayMicroseconds(255);
}
