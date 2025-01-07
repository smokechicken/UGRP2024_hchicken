
// 자율 주행 장치를 제어하기 위한 코드 (라인 트레이싱 포함)

// 초기 변수 선언 및 초기화
int Rsensor = 6;  // 라인트레이싱 IR 센서의 R 값 입력 핀 지정
int Csensor = 10;  // 라인트레이싱 IR 센서의 C 값 입력 핀 지정
int Lsensor = 7;  // 라인트레이싱 IR 센서의 L 값 입력 핀 지정
int L = 0;  // L 입력 값 저장
int C = 0;  // C 입력 값 저장
int R = 0;  // R 입력 값 저장
char way = 'N'; // 방향 저장 변수 (N: 없음, L: 왼쪽, C: 중앙, R: 오른쪽)
int go = 0; // 자율 주행 활성화 여부 (0: 비활성화, 1: 활성화)

void setup() {
  // 시리얼 통신 활성화
  Serial.begin(9600);

  // 아두이노 핀 활성화
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(Rsensor, INPUT);
  pinMode(Csensor, INPUT);
  pinMode(Lsensor, INPUT);
}

// 모터 제어 함수
void controlMotor(int dirPin, int pwmPin, bool direction, int speed) {
  digitalWrite(dirPin, direction ? HIGH : LOW); // 방향 설정
  analogWrite(pwmPin, speed);
}

// 모든 모터 정지
void stopAllMotors() {
  controlMotor(2, 3, true, 0);
  controlMotor(4, 5, true, 0);
  controlMotor(8, 9, true, 0);
  controlMotor(12, 11, true, 0);
}

// 전진
void moveForward() {
  controlMotor(2, 3, false, 255); // 모터 1 정회전
  controlMotor(4, 5, false, 255); // 모터 2 정회전
  controlMotor(8, 9, true, 255);  // 모터 3 역회전
  controlMotor(12, 11, false, 255); // 모터 4 정회전
}

// 후진
void moveBackward() {
  controlMotor(2, 3, true, 255);  // 모터 1 역회전
  controlMotor(4, 5, true, 255);  // 모터 2 역회전
  controlMotor(8, 9, false, 255); // 모터 3 정회전
  controlMotor(12, 11, true, 255);  // 모터 4 역회전
}

// 좌로 회전
void turnLeft() {
  controlMotor(2, 3, true, 255); // 모터 1 정회전
  controlMotor(4, 5, false, 255); // 모터 2 정회전
  controlMotor(8, 9, true, 255);  // 모터 3 역회전
  controlMotor(12, 11, true, 255); // 모터 4 정회전
}

// 우로 회전
void turnRight() {
  controlMotor(2, 3, false, 255);  // 모터 1 역회전
  controlMotor(4, 5, true, 255);  // 모터 2 역회전
  controlMotor(8, 9, false, 255); // 모터 3 정회전
  controlMotor(12, 11, false, 255);  // 모터 4 역회전
}

// 왼쪽으로 전진
void moveLeftForward() {
  controlMotor(2, 3, false, 255); // 모터 1 정회전
  controlMotor(4, 5, false, 255); // 모터 2 정회전
  controlMotor(8, 9, true, 255);  // 모터 3 역회전
  controlMotor(12, 11, true, 255);  // 모터 4 역회전
}

// 오른쪽으로 전진
void moveRightForward() {
  controlMotor(2, 3, true, 255);  // 모터 1 역회전
  controlMotor(4, 5, true, 255);  // 모터 2 역회전
  controlMotor(8, 9, false, 255); // 모터 3 정회전
  controlMotor(12, 11, false, 255); // 모터 4 정회전
}

// IR 센서 데이터 읽기
void readIRSensors() {
  L = digitalRead(Lsensor);
  C = digitalRead(Csensor);
  R = digitalRead(Rsensor);

  // 센서 값에 따라 way 변수 설정
  if (C == 1 && L == 0 && R == 0) {
    way = 'C';
  } else if (L == 1 && C == 0 && R == 0) {
    way = 'L';
  } else if (R == 1 && C == 0 && L == 0) {
    way = 'R';
  } else {
    way = 'N'; // 센서 값이 특정 방향을 나타내지 않을 경우
  }
}

void loop() {
  /*
  // 라인 트레이싱 자율 주행 코드. 구현하였으나 아두이노 회로 문제로 테스트 진행이 어려웠음.
  if (go == 1) {
    readIRSensors(); // IR 센서 데이터 읽기

    // way 값에 따라 동작 수행
    if (way == 'C') {
      moveForward();
    } else if (way == 'L') {
      turnLeft();
    } else if (way == 'R') {
      turnRight();
    } else {
      stopAllMotors();
    }
  } else {
    stopAllMotors(); // go 값이 0일 경우 모든 모터 정지
  }
  */

  // 키보드 수동 컨트롤 코드
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'w') {
      moveForward();
    } else if (command == 'a') {
      turnLeft();
    } else if (command == 's') {
      moveBackward();
    } else if (command == 'd') {
      turnRight();
    } else if (command == 'q') {
      moveLeftForward();
    } else if (command == 'e') {
      moveRightForward();
    } else if (command == 'x') {
      stopAllMotors();
    }
    else if (command == '1') {
      // 자율주행 기능 on/off
      if(go==0){
        go = 1;
      }
      else{
        go = 0;
      }
    }
  }
}

// 본 코드 작성에는 Chat GPT가 활용 되었음.
