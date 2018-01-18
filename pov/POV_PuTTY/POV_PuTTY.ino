/*
(c) Rowan Sharman 2014
This script should write the characters it receives over serial to an array of
seven LEDs connected to a shift register as a Persistence of Vision display
*/


#define DATA 4 //These pins are connected to their respective pins on the shift register
#define LATCH 3
#define CLOCK 2

byte A[] = {B11111100, B00010010, B00010010, B11111100, B00000000, 0};
byte a[] = {B01001000, B10101000, B11110000, B10000000, B00000000, 0};
byte B[] = {B11111110, B10010010, B10010010, B01101100, B00000000, 0};
byte b[] = {B11111110, B10010000, B10010000, B01100000, B00000000, 0};
byte C[] = {B01111100, B10000010, B10000010, B01000100, B00000000, 0};
byte c[] = {B01100000, B10010000, B10010000, B00000000, B00000000, 0};
byte D[] = {B11111110, B10000010, B10000010, B01111100, B00000000, 0};
byte d[] = {B01100000, B10010000, B10010000, B11111110, B00000000, 0};
byte E[] = {B11111110, B10010010, B10010010, B10000010, B00000000, 0};
byte e[] = {B01110000, B10101000, B10110000, B00000000, B00000000, 0};
byte F[] = {B11111110, B00010010, B00010010, B00000010, B00000000, 0};
byte f[] = {B11111100, B00010010, B00000100, B00000000, B00000000, 0};
byte G[] = {B01111100, B10000010, B10100010, B01100100, B00000000, 0};
byte g[] = {B01001000, B10010100, B01111100, B00000000, B00000000, 0};
byte H[] = {B11111110, B00010000, B00010000, B11111110, B00000000, 0};
byte h[] = {B11111110, B00010000, B00010000, B11100000, B00000000, 0};
byte I[] = {B10000010, B11111110, B10000010, B00000000, B00000000, 0};
byte i[] = {B11110100, B00000000, B00000000, B00000000, B00000000, 0};
byte J[] = {B01000000, B01000010, B10000010, B01111110, B00000010, 0};
byte j[] = {B01000000, B10000000, B01111010, B00000000, B00000000, 0};
byte K[] = {B11111110, B00010000, B00101000, B11000110, B00000000, 0};
byte k[] = {B11111110, B00010000, B11101000, B00000000, B00000000, 0};
byte L[] = {B11111110, B10000000, B10000000, B10000000, B00000000, 0};
byte l[] = {B11111110, B00000000, B00000000, B00000000, B00000000, 0};
byte M[] = {B11111110, B00000100, B00001000, B00000100, B11111110, 0};
byte m[] = {B11110000, B00010000, B11100000, B00010000, B11100000, 0};
byte N[] = {B11111110, B00000100, B00111000, B01000000, B11111110, 0};
byte n[] = {B11110000, B00010000, B11100000, B00000000, B00000000, 0};
byte O[] = {B01111100, B10000010, B10000010, B01111100, B00000000, 0};
byte o[] = {B01100000, B10010000, B01100000, B00000000, B00000000, 0};
byte P[] = {B11111110, B00010010, B00010010, B00001100, B00000000, 0};
byte p[] = {B11111000, B00101000, B00010000, B00000000, B00000000, 0};
byte Q[] = {B00111100, B01000010, B11100010, B01000010, B00111100, 0};
byte q[] = {B00001000, B00010100, B11111100, B10000000, B00000000, 0};
byte R[] = {B11111110, B00010010, B00110010, B11001100, B00000000, 0};
byte r[] = {B11110000, B00010000, B00010000, B00000000, B00000000, 0};
byte S[] = {B01001100, B10010010, B10010010, B01100100, B00000000, 0};
byte s[] = {B10010000, B10101000, B01001000, B00000000, B00000000, 0};
byte T[] = {B00000010, B00000010, B11111110, B00000010, B00000010, 0};
byte t[] = {B01111110, B10010000, B01000000, B00000000, B00000000, 0};
byte U[] = {B11111110, B10000000, B10000000, B11111110, B00000000, 0};
byte u[] = {B11110000, B10000000, B11110000, B00000000, B00000000, 0};
byte V[] = {B00111110, B01000000, B10000000, B01000000, B00111110, 0};
byte v[] = {B01110000, B10000000, B01110000, B00000000, B00000000, 0};
byte W[] = {B01111110, B10000000, B01100000, B10000000, B01111110, 0};
byte w[] = {B01110000, B10000000, B01000000, B10000000, B01110000, 0};
byte X[] = {B11000110, B00101000, B00010000, B00101000, B11000110, 0};
byte x[] = {B11011000, B00100000, B11011000, B00000000, B00000000, 0};
byte Y[] = {B00000110, B00001000, B11110000, B00001000, B00000110, 0};
byte y[] = {B10001100, B01010000, B00110000, B00001100, B00000000, 0};
byte Z[] = {B11000010, B10100010, B10010010, B10001010, B10000110, 0};
byte z[] = {B11001000, B10101000, B10011000, B00000000, B00000000, 0};

byte n0[] = {B01111100, B10000010, B10000010, B01111100, B00000000, 0};
byte n1[] = {B10000100, B11111110, B10000000, B00000000, B00000000, 0};
byte n2[] = {B11000100, B10100010, B10010010, B10001100, B00000000, 0};
byte n3[] = {B01000100, B10000010, B10010010, B01101100, B00000000, 0};
byte n4[] = {B00011110, B00010001, B00010000, B11111110, B00000000, 0};
byte n5[] = {B01001110, B10001010, B10001010, B01110010, B00000000, 0};
byte n6[] = {B01111100, B10010010, B10010010, B01100100, B00000000, 0};
byte n7[] = {B00000010, B11100010, B00011010, B00000110, B00000000, 0};
byte n8[] = {B01101100, B10010010, B10010010, B01101100, B00000000, 0};
byte n9[] = {B01001100, B10010010, B10010010, B01111100, B00000000, 0};

byte space[]            = {B00000000, B00000000, B00000000, B00000000, B00000000, 1};
byte dot[]              = {B10000000, B00000000, B00000000, B00000000, B00000000, 0};
byte comma[]            = {B11000000, B00000000, B00000000, B00000000, B00000000, 0};
byte colon[]            = {B01000100, B00000000, B00000000, B00000000, B00000000, 0};
byte semicolon[]        = {B11000100, B00000000, B00000000, B00000000, B00000000, 0};
byte apostrophe[]       = {B00000110, B00000000, B00000000, B00000000, B00000000, 0};
byte quote[]            = {B00000110, B00000001, B00000110, B00000000, B00000000, 0};
byte lessThan[]         = {B00010000, B00101000, B01000100, B00000000, B00000000, 0};
byte greaterThan[]      = {B01000100, B00101000, B00010000, B00000000, B00000000, 0};
byte question[]         = {B00000100, B10110010, B00010010, B00001100, B00000000, 0};
byte slash[]            = {B11110000, B00001110, B00000000, B00000000, B00000000, 0};
byte backslash[]        = {B00001110, B11110000, B00000000, B00000000, B00000000, 0};
byte bar[]              = {B11111110, B00000000, B00000000, B00000000, B00000000, 0};
byte braceLeft[]        = {B11111110, B10000010, B00000000, B00000000, B00000000, 0};
byte braceRight[]       = {B10000010, B11111110, B00000000, B00000000, B00000000, 0};
byte curlyLeft[]        = {B00010000, B01111100, B10000010, B00000000, B00000000, 0};
byte curlyRight[]       = {B10000010, B01111100, B00010000, B00000000, B00000000, 0};
byte exclamation[]      = {B10111110, B00000000, B00000000, B00000000, B00000000, 0};
byte pound[]            = {B00101000, B11111110, B00101000, B11111110, B00101000, 0};
byte dollar[]           = {B01001000, B10010100, B11111110, B10100100, B01001000, 0};
byte up[]               = {B00001000, B00000100, B00000010, B00000100, B00001000, 0};
byte asterisk[]         = {B00001010, B00000100, B00001010, B00000000, B00000000, 0};
byte parenthesesLeft[]  = {B01111100, B10000010, B00000000, B00000000, B00000000, 0};
byte parenthesesRight[] = {B10000010, B01111100, B00000000, B00000000, B00000000, 0};
byte hyphen[]           = {B00010000, B00010000, B00010000, B00000000, B00000000, 0};
byte underscore[]       = {B10000000, B10000000, B10000000, B10000000, B10000000, 0};
byte plus[]             = {B00010001, B00111000, B00010000, B00000000, B00000000, 0};
byte equal[]            = {B00101000, B00101000, B00101000, B00101000, B00000000, 0};

byte currentCols[] = {0,0,0,0,0,0,0,0};
String currentString = "";

void setup(){
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  Serial.begin(9600);
}

void loop(){ 
  while(Serial.available()){ //If there is something waiting in the serial buffer, convert it to the series of arrays to flash to spell the text
    char cur = Serial.read();
    if((cur != '\r') && (cur != '\n')){
      char inChar = cur;
      currentString += inChar;
      delay(10);
    }
  
  }
  currentString += "  ";
  
  while(Serial.available() == 0){ //While not being told to change, continue repeating message
    printString(currentString); 
  } 
  
  currentString = "";
}

void assignToCurrent(byte arrayToAssign[]){
  for(int i = 0; i < 8; i ++)
    currentCols[i] = arrayToAssign[i];
}

void printString(String str){
  
  for(int current = 0; current < str.length() ; current ++){
    char currentChar = str.charAt(current);
    
    switch(currentChar){
      case 'A':
        assignToCurrent(A);
        break;
      case 'a':
        assignToCurrent(a);
        break;
      case 'B':
        assignToCurrent(B);
        break;
      case 'b':
        assignToCurrent(b);
        break;
      case 'C':
        assignToCurrent(C);
        break;
      case 'c':
        assignToCurrent(c);
        break;
      case 'D':
        assignToCurrent(D);
        break;
      case 'd':
        assignToCurrent(d);
        break;
      case 'E':
        assignToCurrent(E);
        break;
      case 'e':
        assignToCurrent(e);
        break;
      case 'F':
        assignToCurrent(F);
        break;
      case 'f':
        assignToCurrent(f);
        break;
      case 'G':
        assignToCurrent(G);
        break;
      case 'g':
        assignToCurrent(g);
        break;
      case 'H':
        assignToCurrent(H);
        break;
      case 'h':
        assignToCurrent(h);
        break;
      case 'I':
        assignToCurrent(I);
        break;
      case 'i':
        assignToCurrent(i);
        break;
      case 'J':
        assignToCurrent(J);
        break;
      case 'j':
        assignToCurrent(j);
        break;
      case 'K':
        assignToCurrent(K);
        break;
      case 'k':
        assignToCurrent(k);
        break;
      case 'L':
        assignToCurrent(L);
        break;
      case 'l':
        assignToCurrent(l);
        break;
      case 'M':
        assignToCurrent(M);
        break;
      case 'm':
        assignToCurrent(m);
        break;
      case 'N':
        assignToCurrent(N);
        break;
      case 'n':
        assignToCurrent(n);
        break;
      case 'O':
        assignToCurrent(O);
        break;
      case 'o':
        assignToCurrent(o);
        break;
      case 'P':
        assignToCurrent(P);
        break;
      case 'p':
        assignToCurrent(p);
        break;
      case 'Q':
        assignToCurrent(Q);
        break;
      case 'q':
        assignToCurrent(q);
        break;
      case 'R':
        assignToCurrent(R);
        break;
      case 'r':
        assignToCurrent(r);
        break;
      case 'S':
        assignToCurrent(S);
        break;
      case 's':
        assignToCurrent(s);
        break;
      case 'T':
        assignToCurrent(T);
        break;
      case 't':
        assignToCurrent(t);
        break;
      case 'U':
        assignToCurrent(U);
        break;
      case 'u':
        assignToCurrent(u);
        break;
      case 'V':
        assignToCurrent(V);
        break;
      case 'v':
        assignToCurrent(v);
        break;
      case 'W':
        assignToCurrent(W);
        break;
      case 'w':
        assignToCurrent(w);
        break;
      case 'X':
        assignToCurrent(X);
        break;
      case 'x':
        assignToCurrent(x);
        break;
      case 'Y':
        assignToCurrent(Y);
        break;
      case 'y':
        assignToCurrent(y);
        break;
      case 'Z':
        assignToCurrent(Z);
        break;
      case 'z':
        assignToCurrent(z);
        break;
        
      case '0':
        assignToCurrent(n0);
        break;
      case '1':
        assignToCurrent(n1);
        break;
      case '2':
        assignToCurrent(n2);
        break;
      case '3':
        assignToCurrent(n3);
        break;
      case '4':
        assignToCurrent(n4);
        break;
      case '5':
        assignToCurrent(n5);
        break;
      case '6':
        assignToCurrent(n6);
        break;
      case '7':
        assignToCurrent(n7);
        break;
      case '8':
        assignToCurrent(n8);
        break;
      case '9':
        assignToCurrent(n9);
        break;
        
      case ' ':
        assignToCurrent(space);
        break;
      case'.':
        assignToCurrent(dot);
        break;
      case',':
        assignToCurrent(comma);
        break;
      case':':
        assignToCurrent(colon);
        break;
      case';':
        assignToCurrent(semicolon);
        break;
      case'\'':
        assignToCurrent(apostrophe);
        break;
      case'"':
        assignToCurrent(quote);
        break;
      case'<':
        assignToCurrent(lessThan);
        break;
      case'>':
        assignToCurrent(greaterThan);
        break;
      case'?':
        assignToCurrent(question);
        break;
      case'/':
        assignToCurrent(slash);
        break;
      case'\\':
        assignToCurrent(backslash);
        break;
      case'|':
        assignToCurrent(bar);
        break;
      case'[':
        assignToCurrent(braceLeft);
        break;
      case']':
        assignToCurrent(braceRight);
        break;
      case'{':
        assignToCurrent(curlyLeft);
        break;
      case'}':
        assignToCurrent(curlyRight);
        break;
      case'!':
        assignToCurrent(exclamation);
        break;
      case'#':
        assignToCurrent(pound);
        break;
      case'$':
        assignToCurrent(dollar);
        break;
      case'^':
        assignToCurrent(up);
        break;
      case'*':
        assignToCurrent(asterisk);
        break;
      case'(':
        assignToCurrent(parenthesesLeft);
        break;
      case')':
        assignToCurrent(parenthesesRight);
        break;
      case'-':
        assignToCurrent(hyphen);
        break;
      case '_':
        assignToCurrent(underscore);
        break;
      case'+':
        assignToCurrent(plus);
        break;
      case'=':
        assignToCurrent(equal);
        break;
        
      default: //if character not found, write an underscore
        assignToCurrent(underscore);
        break;
    }
    
    for(int b = 0; currentCols[b] > 0; b ++){
      digitalWrite(LATCH, LOW);
      shiftOut(DATA, CLOCK, LSBFIRST, currentCols[b] >> 1);
      digitalWrite(LATCH, HIGH);
      delay(3);
    }
    
    
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, 0);
    digitalWrite(LATCH, HIGH);
    delay(6);
  }
}

