int d;
#define hall_light 13
#define kit_light 7
#define bed_light 8
#define stu_light 12
#define hall_fan 5
#define bath_light 11

void hall_light_on() {
 digitalWrite(hall_light, HIGH);
    delay(200); 
}
void hall_light_off() {
  digitalWrite(hall_light, LOW);
  delay(200);
}

void kit_light_on() {
  digitalWrite(kit_light, HIGH);
    delay(200);
}
void kit_light_off() {
  digitalWrite(kit_light,LOW);
  delay(200);
}

void stu_light_on() {
  digitalWrite(stu_light, HIGH);
    delay(200);
}
void stu_light_off() {
  digitalWrite(stu_light,LOW);
  delay(200);
}

void bed_light_on() {
  digitalWrite(bed_light, HIGH);
    delay(200);
}
void bed_light_off() {
  digitalWrite(bed_light,LOW);
  delay(200);
}

void hall_fan_on() {
  analogWrite(hall_fan, 130);
  
}

void hall_fan_off() {
  analogWrite(hall_fan, LOW);
  delay(200);
}

void bath_light_on() {
  digitalWrite(bath_light, HIGH);
  delay(200);
}
void bath_light_off() {
  digitalWrite(bath_light, LOW);
  delay(200);
}
void setup() {
Serial.begin(9600);
pinMode(hall_light, OUTPUT); 
pinMode(bed_light, OUTPUT); 
pinMode(stu_light, OUTPUT); 
pinMode(kit_light, OUTPUT); 
pinMode(hall_fan, OUTPUT);
pinMode(bath_light, OUTPUT);
}
void loop() {
  String voice="";
while(Serial.available()) {
  delay(10);
  char c = Serial.read();
  if(c=="#") {
    break;
  }

voice+=c;
}
if(voice.length()>0) { 
  if(voice=="hall light on"||voice=="turn on the hall light"||voice=="hall lights on"||voice=="turn on the hall lights"||voice=="turn on the lights of hall"||voice=="turn on the light of hall") {
    d=1;
  }
  if(voice=="hall light off"||voice=="turn off the hall light"||voice=="hall lights off"||voice=="turn off the hall lights"||voice=="turn off the lights of hall"||voice=="turn off the light of hall") {
    d=2;
  }
  if(voice=="bedroom light on"||voice=="turn on the bedroom light"||voice=="bedroom lights on"||voice=="turn on the bedroom lights"||voice=="turn on the light of bedroom"||voice=="turn on the lights of bedroom") {
    d=3;
  }
  if(voice=="bedroom light off"||voice=="turn off the bedroom light"||voice=="bedroom lights off"||voice=="turn off the bedroom lights"||voice=="turn off the light of bedroom"||voice=="turn off the lights of bedroom") {
    d=4;
  }
  if(voice=="kitchen light on"||voice=="turn on the kitchen light"||voice=="kitchen lights on"||voice=="turn on the kitchen lights"||voice=="turn on the light of kitchen"||voice=="turn on the lights of kitchen") {
    d=5;
  }
  if(voice=="kitchen light off"||voice=="turn off the kitchen light"||voice=="bedroom lights off"||voice=="turn off the bedroom lights"||voice=="turn off the light of bedroom"||voice=="turn off the lights of bedroom") {
    d=6;
  }
  if(voice=="study room light on"||voice=="turn on the study room light"||voice=="study room lights on"||voice=="turn on the study room lights"||voice=="turn on the light of study room"||voice=="turn on the lights of study room") {
    d=7;
  }
  if(voice=="study room light off"||voice=="turn off the study room light"||voice=="study room lights off"||voice=="turn off the study room lights"||voice=="turn off the light of study room"||voice=="turn off the lights of study room") {
    d=8;
  }
  if(voice=="turn on the hall fan"||voice=="turn on the fan of hall"||voice=="turn on the fan of Hall"||voice=="turn on the fan of all") {
    d=9;
    
  }
  if(voice=="hall fan off"||voice=="turn off the hall fan"||voice=="turn off the fan of hall") {
    d=10;
  }
  if(voice=="bathroom light on"||voice=="turn on the bathroom light"||voice=="bathroom lights on"||voice=="turn on the bathroom lights"||voice=="turn on the light of bathroom"||voice=="turn on the lights of bathroom") {
    d=11;
  }
  if(voice=="bathroom light off"||voice=="turn off the bathroom light"||voice=="bathroom lights off"||voice=="turn off the bathroom lights"||voice=="turn off the light of bathroom"||voice=="turn off the lights of bathroom") {
    d=12;
  }
  
  if(voice=="All light off"||voice=="All lights off"||voice=="turn off all lights"||voice=="turn all lights off"||voice=="turn off all light"||voice=="turn all light off") {
    d=14;
  }
}
switch(d) {
  case 1: hall_light_on(); break;
  case 2: hall_light_off(); break;
  case 3: bed_light_on(); break;
  case 4: bed_light_off(); break;
  case 5: kit_light_on(); break;
  case 6: kit_light_off(); break;
  case 7: stu_light_on(); break;
  case 8: stu_light_off(); break;
  case 9: hall_fan_on(); break;
  case 10: hall_fan_off(); break;
  case 11: bath_light_on(); break;
  case 12: bath_light_off(); break;
  case 14: hall_light_off();
           delay(200);
           bed_light_off();
           delay(200);
           kit_light_off();
           delay(200);
           stu_light_off();
           delay(200);
           bath_light_off();
           delay(200);
           break;
}
voice="";
}
