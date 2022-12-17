#include <Keypad.h>

const int ROW_NUM = 4;
const int COLUMN_NUM = 4;
bool cd = true;
String temp = "";

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6};
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2};

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );
int patterns[] =
{
  1, 14, 12, 125, 15, 124, 1245, 145, 24, 245, 17, 147, 127, 1257, 157, 1247, 12457, 1457, 247, 2457, 178, 1478, 1458, 1278, 12578, 1578
};

char getCode(String userInput) {
      for (int i =0;i<26;i++)
      {
        if (userInput.length()==String(patterns[i]).length())
        {
          int v[userInput.length()];
          for (int u =0;u<userInput.length();u++)
          {
            for (int o =0;o<userInput.length();o++)
            {
              if (userInput[u]==String(patterns[i])[o]&&v[o]!=1)
                v[o]=1;
            }
          }
          for (int p =0;p<userInput.length();p++)
              {
                if (v[p] == 1&&p==userInput.length()-1)
                  return ((char)(97+i));
              else if (v[p] != 1)
                  break;
              }
        }
      }   
       
    return 1;
}

void setup(){
  Serial.begin(9600);
}

void loop(){
  char key = keypad.getKey();

  if (key == 'D')
  {
    cd = true;
    Serial.print("Enter");
    temp = "";
  }
  if (key == 'C')
  {
    cd = true;
    if (getCode(temp) != 1)
      Serial.print(getCode(temp));
    temp = "";
  }
  else if (key == 'B')
    {
      Serial.print("Backspace");
      temp="";
      }
  else if (key == '*')
    {
      Serial.print("Space");
      temp="";
      }
  else if (key&&cd){
    temp = "";
    cd = false;
    temp += key;
  }
  else if (key&&!cd)
    temp += key; 
    
}