// C++ code
//......edited
#define l 13
#define r 2
#define cl 10
#define cr 6
#define er 5
#define el 11
#define pl 12
#define pr 8
#define nl 7
#define nr 4

int L=0;
int R=0;
int CL=0;
int CR=0;
char turn[1000];

void left(){
    analogWrite(el,155);
    analogWrite(er,200);          
    digitalWrite(nr, LOW);
    digitalWrite(nl, LOW);
    delay(100);
  return;}

void right(){
    analogWrite(el,200);
    analogWrite(er,155);
    digitalWrite(nr, LOW);
    digitalWrite(nl, LOW);
    delay(100);
  return;}

void straight(){
    analogWrite(el,155);
    analogWrite(er,155);
    digitalWrite(pr, HIGH);
    digitalWrite(pl, HIGH);
    digitalWrite(nr, LOW);
    digitalWrite(nl, LOW);
  return;}

void stop(){
    digitalWrite(pr, LOW);
    digitalWrite(pl, LOW);
    digitalWrite(nr, LOW);
    digitalWrite(nl, LOW);
  return;}

void u(){
    digitalWrite(pr, LOW);
    digitalWrite(pl, HIGH);
    digitalWrite(nr, HIGH);
    digitalWrite(nl, LOW);
    delay(100);
  return;}

void arrange(char turn[],int n,int i){
  turn[i]=turn[i+1];
  i++;
  while(i<n-2){
    turn[i]=turn[i+2];
    if(turn[i]=='D') break;
    i++;
  }
  turn[i++]='D';
  turn[i]='D';
}

void short_path(char turn[],int n){
  for(int i = 0; i < n-1; i++){
    if(turn[i]=='U'){
      if(turn[i-1]=='L' && turn[i+1]=='R'){
        turn[i-1]=0;
        turn[i+1]=0;
        arrange(turn,n,i-1);
      }
      else if(turn[i-1]=='L' && turn[i+1]=='S'){
        turn[i]='R';
        turn[i-1]=0;
        turn[i+1]=0;
        arrange(turn,n,i-1);
      }
      else if(turn[i-1]=='R' && turn[i+1]=='L'){
        turn[i-1]=0;
        turn[i+1]=0;
        arrange(turn,n,i-1);
      }
      else if(turn[i-1]=='S' && turn[i+1]=='L'){
        turn[i]='R';
        turn[i-1]=0;
        turn[i+1]=0;
        arrange(turn,n,i-1);
      }
      else if(turn[i-1]=='S' && turn[i+1]=='S'){
        turn[i-1]=0;
        turn[i+1]=0;
        arrange(turn,n,i-1);
      }
      else if(turn[i-1]=='L' && turn[i+1]=='L'){
        turn[i]='S';
        turn[i-1]=0;
        turn[i+1]=0;
        arrange(turn,n,i-1);
      }
      i=-1;
    }
  }
}

void back(char turn[],int n){
  int i=0;
  short_path(turn,n);
  delay(2000);
  u();
  straight();
    
  while(turn[i]!='D'){        
    L=digitalRead(l);
    R=digitalRead(r);
    CL=digitalRead(cl);
    CR=digitalRead(cr); 
           
  if(L==1 && CL==0 && CR==0 && R==1){
    straight();
   }
  else{
    if(turn[i]=='L'){
      right();
      straight();
      i++;
    }
    else if(turn[i]=='R'){
      left();
      straight();
      i++;
    }
    else if(turn[i]=='S'){
      straight();
      i++;
    }
  }
  }
  stop();
  return;
  
}


void setup()
{
  pinMode(l, INPUT);
  pinMode(r, INPUT);
  
  pinMode(pl, OUTPUT);
  pinMode(pr, OUTPUT);
  pinMode(nl, OUTPUT);
  pinMode(nr, OUTPUT);
  pinMode(el, OUTPUT);
  pinMode(er, OUTPUT);
  Serial.begin(9600);
  delay(3000);
  
}

int i=0;
void loop()
{
  analogWrite(el,155);
  analogWrite(er,155);
  L=digitalRead(l);
  R=digitalRead(r);
  CL=digitalRead(cl);
  CR=digitalRead(cr);
  
  Serial.println(R);

  if(CL==0 && CR==1){
    analogWrite(el,100);
    analogWrite(er,155);
    digitalWrite(nr, LOW);
    digitalWrite(nl, LOW);
    delay(50);
    } 
  if(CL==1 && CR==0){
    analogWrite(el,155);
    analogWrite(er,100);    
    digitalWrite(nr, LOW);
    digitalWrite(nl, LOW);
    delay(50);
    }  
  if(L==1 && CL==0 && CR==0 && R==1){
    straight();
    }
  else if(L==0 && CL==0 && CR==0 && R==1){
    left();
    straight();
    turn[i++]='L';  }
  else if(L==1 && R==1 && CL==1 && CR==1){
    u();
    straight();
    turn[i++]='U';    }
  else if(L==1 && CL==0 && CR==0 && R==0){
    delay(10);
    L=digitalRead(l);
    R=digitalRead(r);
    CL=digitalRead(cl);
    CR=digitalRead(cr);
    if(L==1 && R==1 && CL==1 && CR==1){
      right();
      straight();
      turn[i++]='R';
    }
    else{
      straight();
      turn[i++]='S';}  }
  else if(L==0 && CL==0 && CR==0 && R==0){
    delay(10);
    if(L==0 && CL==0 && CR==0 && R==0){
      stop();
      back(turn,i);
      return;
    } else {
      left();
straight();
      turn[i++]='L';
    }
  }
}
