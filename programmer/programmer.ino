uint8_t out_data = 0b00000000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

    //назначим режим работы пинов:
    pinMode(22, OUTPUT);
    pinMode(23, OUTPUT);
    pinMode(24, OUTPUT);
    pinMode(25, OUTPUT);
    pinMode(26, INPUT);
    pinMode(27, INPUT);
    pinMode(28, INPUT);
    pinMode(29, INPUT);
    // можно еще задать режим INPUT_PULLUP - вход с подтяжкой
}

void loop() {
  
  if (Serial.available() > 0){

    uint8_t in_data = Serial.read(); //читаем байт

    bool pb0 = bitRead(in_data, 0);
    bool pb1 = bitRead(in_data, 1);
    bool pb2 = bitRead(in_data, 2);
    bool power = bitRead(in_data, 3);

    //выводим биты на соответствующие пины
    digitalWrite(22, pb0);
    digitalWrite(23, pb1);
    digitalWrite(24, pb2);
    digitalWrite(25, power);

    
    //заполняем выходной байт с соответствующих пинов
    bitWrite(out_data, 0, digitalRead(26));
    bitWrite(out_data, 1, digitalRead(27));
    bitWrite(out_data, 2, digitalRead(28));
    bitWrite(out_data, 3, digitalRead(29));
    
    //Serial.print(out_data);
    Serial.write(out_data);

    //Serial.print(pb0);
    //Serial.print(pb1);
    //Serial.print(pb2);
    //Serial.print(power);

      }

}
