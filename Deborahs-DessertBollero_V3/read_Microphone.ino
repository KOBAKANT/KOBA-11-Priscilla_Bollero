
int avg;
int sampleSize = 1;


int   read_Microphone() {
  
  // if the avarage was never filled
  if (avg==0){
    delay(100);
    avg = analogRead(micPin);
  }
  
  int val = analogRead(micPin);

//  //take the avarage of the sample size
  avg = (avg * (sampleSize - 1) + val) / sampleSize;
  val = avg;
  
  return val;
}
