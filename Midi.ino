

int pot1Valor=0;
int pot2Valor=0;

void setup() {
pot1Valor=0;
pot2Valor=0;
  
  Serial.begin(31250);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  digitalWrite(52,LOW);
  

}

void loop() {
int pot1ValorPrevio=pot1Valor;
pot1Valor= analogRead(A1)/8;
txMidi(1,pot1Valor,pot1ValorPrevio);

 
int pot2ValorPrevio=pot2Valor;
pot2Valor= analogRead(A2)/8;
txMidi(2,pot2Valor,pot2ValorPrevio);


}

void txMidi(int canal,int valorActual,int valorPrevio){
  
  if(valorPrevio!=valorActual){
    midiSend(0xB0,canal,valorActual); //envia codigo midi continuous controller(176)
    digitalWrite(52,HIGH);
    }
    else{
      digitalWrite(52,LOW);
      }
  
  }
  void midiSend(int message,int control,int value){
  
 Serial.write(message+control);//BYTE
 Serial.write(7);// controlador volumen
  Serial.write(value);
  }

