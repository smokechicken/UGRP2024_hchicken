
// 리니어 엑추에이터 로봇 팔을 수동으로 조작하기 위한 제어 코드

void setup() {
  // 시리얼 통신 활성화
  Serial.begin(9600);

  // 아두이노 핀 활성화
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // 시리얼 통신 신호 확인
  if (Serial.available() > 0) {
    char command = Serial.read();

    // 각 키보드의 자판이 눌렸을 때의 동작 (아무 버튼도 누르지 않으면 Processing이 x를 입력함)
    if (command == 'w') {
      // y축 증가
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      analogWrite(10, 255);
    } 
    else if (command == 's') {
      // y축 감소
      digitalWrite(6, HIGH);
      digitalWrite(5, LOW);
      analogWrite(10, 255);
    }
    else if (command == 'v') {
      // x축 증가
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      analogWrite(11, 255);
      }
    else if (command == 'b') {
      // x축 감소
      digitalWrite(4, HIGH);
      digitalWrite(3, LOW);
      analogWrite(11, 255);
      }
    else if (command == 'i') {
      // z축 증가
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      analogWrite(9, 255);
    }
    else if (command == 'o') {
      // z축 감소
      digitalWrite(8, HIGH);
      digitalWrite(7, LOW);
      analogWrite(9, 255);
    }
    else if (command == 'x') {
      // 멈춤 (아무 입력이 없는 경우)
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      analogWrite(10, 0);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      analogWrite(11, 0);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      analogWrite(9, 0);
    }
  }
}

// 본 코드 작성에는 Chat GPT가 활용 되었음.
