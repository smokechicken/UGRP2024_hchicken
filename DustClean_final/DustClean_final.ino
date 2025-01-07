
// 건조기 먼지필터 청소장치의 실행 코드입니다.

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
  // 시리얼 통신을 통해 키보드 명령을 입력받고, 명령에 맞는 동작을 실행합니다.
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == 'w') {
      // y축 제어(증가)
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      analogWrite(9, 255);
    } 
    else if (command == 's') {
      // y축 제어(감소)
      digitalWrite(6, HIGH);
      digitalWrite(5, LOW);
      analogWrite(9, 255);
    }
    else if (command == 'v') {
      // x축 제어(감소)
      digitalWrite(4, HIGH);
      digitalWrite(3, LOW);
      analogWrite(11, 255);

      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);
      analogWrite(10, 255);
      }
    else if (command == 'b') {
      // x축 제어(증가)
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      analogWrite(11, 255);

      digitalWrite(2, HIGH);
      digitalWrite(7, LOW);
      analogWrite(10, 255);
      }
    else if (command == 'x') {
      // 정지 코드
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      analogWrite(10, 0);
    }
    else if (command == 'j') {
      // x축 좌우 이동 10회 실행
      for(int i=0;i<10;i++){
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      analogWrite(11, 255);

      digitalWrite(2, HIGH);
      digitalWrite(7, LOW);
      analogWrite(10, 255);

      delay(400);

      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      analogWrite(11, 0);

      digitalWrite(2, LOW);
      digitalWrite(7, LOW);
      analogWrite(10, 0);

      delay(400);

      digitalWrite(4, HIGH);
      digitalWrite(3, LOW);
      analogWrite(11, 255);

      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);
      analogWrite(10, 255);

      delay(400);

      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      analogWrite(11, 0);

      digitalWrite(2, LOW);
      digitalWrite(7, LOW);
      analogWrite(10, 0);

      delay(400);
      }
    } 
    // 메인 코드로, 먼지 필터 전체를 청소할 수 있는 코드입니다.
    else if (command == 'i') {
      // x축 좌우 이동 1회 선 실행 후 반복문 실행
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      analogWrite(11, 255);

      digitalWrite(2, HIGH);
      digitalWrite(7, LOW);
      analogWrite(10, 255);

      delay(400);

      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      analogWrite(11, 0);

      digitalWrite(2, LOW);
      digitalWrite(7, LOW);
      analogWrite(10, 0);

      delay(300);

      digitalWrite(4, HIGH);
      digitalWrite(3, LOW);
      analogWrite(11, 255);

      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);
      analogWrite(10, 255);

      delay(400);

      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      analogWrite(11, 0);

      digitalWrite(2, LOW);
      digitalWrite(7, LOW);
      analogWrite(10, 0);

      // y축 증가 후 x축 좌우 이동을 반복하며 필터를 청소함.
      for(int i=0;i<6;i++){
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      analogWrite(9, 255);

      delay(2000);

      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      analogWrite(9, 0);

      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      analogWrite(11, 255);

      digitalWrite(2, HIGH);
      digitalWrite(7, LOW);
      analogWrite(10, 255);

      delay(400);

      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      analogWrite(11, 0);

      digitalWrite(2, LOW);
      digitalWrite(7, LOW);
      analogWrite(10, 0);

      delay(300);

      digitalWrite(4, HIGH);
      digitalWrite(3, LOW);
      analogWrite(11, 255);

      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);
      analogWrite(10, 255);

      delay(400);

      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      analogWrite(11, 0);

      digitalWrite(2, LOW);
      digitalWrite(7, LOW);
      analogWrite(10, 0);
      }
    } 
    else if (command == 'k') {
      // 정지 코드
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      analogWrite(11, 0);
      digitalWrite(6, LOW);
      digitalWrite(2, LOW);
      analogWrite(9, 0);
    }
  }
}

// 본 코드 작성에는 Chat GPT가 활용 되었음.
