
#include <Keypad.h>
#include <LiquidCrystal.h>


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte LINHAS = 4;
const byte COLUNAS = 4;

char teclas[LINHAS][COLUNAS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};


byte pinosLinhas[LINHAS] = {A0, A1, A2, A3}; 
byte pinosColunas[COLUNAS] = {A4, A5, A6, A7};

Keypad teclado = Keypad(makeKeymap(teclas), pinosLinhas, pinosColunas, LINHAS, COLUNAS);


String senhaCorreta = "1234";
String senhaDigitada = "";

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Digite a senha:");
  lcd.setCursor(0, 1);
}

void loop() {
  char tecla = teclado.getKey();

  if (tecla) {
    if (tecla == '#') {
      lcd.clear();
      if (senhaDigitada == senhaCorreta) {
        lcd.print("Seja bem-vindo!");
      } else {
        lcd.print("Senha incorreta");
      }
      delay(2000);
      lcd.clear();
      lcd.print("Digite a senha:");
      senhaDigitada = "";
    } else if (tecla == '*') {
      senhaDigitada = "";
      lcd.clear();
      lcd.print("Digite a senha:");
    } else if (senhaDigitada.length() < 4) {
      senhaDigitada += tecla;
      lcd.setCursor(senhaDigitada.length() - 1, 1);
      lcd.print('*'); 
    }
  }
}