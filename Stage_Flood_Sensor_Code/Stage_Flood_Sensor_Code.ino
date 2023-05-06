const uint16_t TONE_DURATION = 500; //Duration of a single beep in multiples of 256µs
const uint8_t TONE_REP = 3; //Number ot times to repeat beep per sequence
const uint16_t TONE_PAUSE = 500; //How long to pause between beep sequences in ms
const uint8_t BOOT_VOLUME = 10; //Beep volume - 0=off; 128 = full volume; 255 = off;
const uint8_t ALARM_VOLUME = 128; //Beep volume - 0=off; 128 = full volume; 255 = off;
const uint16_t THRESHOLD = 60000; //Threshold adc value that triggers the alarm

uint16_t adc; //Stores the recorded adc values
uint8_t avg; //Sample averaging counter
uint8_t beep; //Stores duration of second phase of beep cycle

void setup() {
  Serial.begin(115200);
  //Clear ADC
  analogRead(A0);
  analogRead(A0);
  DDRD = B11111100;
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  playBeep(BOOT_VOLUME);
}

void loop() {
  avg = 64;
  adc = 0;
  while(avg--) adc += analogRead(A0);
  if(adc < THRESHOLD){
    avg = TONE_REP;
    while(avg--) playBeep(ALARM_VOLUME);
    delay(TONE_PAUSE);
  }
  Serial.println(adc);
}

void playBeep(uint8_t volume){
  adc = TONE_DURATION;
  beep = 255-volume;
  digitalWrite(LED_BUILTIN, HIGH);
  while(adc--){ //Play tone
    PORTD = B01000000;
    delayMicroseconds(volume);
    PORTD = B10000000;
    delayMicroseconds(beep);
  }
  adc = TONE_DURATION; //Pause tone
  digitalWrite(LED_BUILTIN, LOW);
  while(adc--) delayMicroseconds(255);
}
