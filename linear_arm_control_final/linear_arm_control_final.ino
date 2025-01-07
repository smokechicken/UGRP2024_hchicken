
// 리니어 엑추에이터 로봇 팔의 최종 테스트 때 사용한 코드로, 필터 회수 기능을 실행할 수 있습니다.

float tx = 0;
float dtx = 10;
float dty = 0;
float v = 0.01;
float px = 10;
float py = 10;
float R = 380;
float y_n;
float y_n1;
float t_total;

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
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  //circle_drawing();  // 원 궤적 그리기 코드로, 테스트에서는 안정성을 위해 코드를 분리하여 실행하였으므로 주석 처리함.
  //nomal_move_x(0, 28000);  // 원점 복귀 코드로, 테스트에서는 안정성을 위해 다른 코드를 실행하였으므로 주석 처리함.
  //nomal_move_y(0, 28000);  // 원점 복귀 코드로, 테스트에서는 안정성을 위해 다른 코드를 실행하였으므로 주석 처리함.
  
  // 필터 회수 동작을 실행하는 코드
  nomal_move_x(1, 6000);
  nomal_move_y(1, 14000);
  nomal_move_x(0, 6000);
  nomal_move_z(1, 25000);
  nomal_move_x(1, 6000);
  end();  // 프로그램 종료 코드
}

void circle_drawing(){
  // 원 궤적 그리기 코드
  tx += dtx;
  px += dtx*v;
  y_n = R - sqrt((R*R) - (v*v)*(tx*tx));
  y_n1 = R - sqrt((R*R) - (v*v)*((tx+dtx)*(tx+dtx)));
  dty = (y_n1 - y_n)/v;

  if(dty>dtx){
    moveActuators_xy(255, dtx);
    moveActuators_y(255, (dty-dtx));
  }
  else{
    moveActuators_xy(255, dty);
    moveActuators_x(255, (dtx-dty));
  }

  py += v*dty;
  t_total += 10 + int(dty);
  Serial.println(t_total);
}

// 원 궤적 그리기와 관련된 리니어 액추에이터 제어 함수들
void moveActuators_x(float vx, float time) {
    // 주어진 시간 동안 x축의 리니어 엑추에이터 작동
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    analogWrite(11, vx);
    delay(time);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    analogWrite(11, 0);
}

void moveActuators_y(float vy, float time) {
    // 주어진 시간 동안 y축의 리니어 엑추에이터 작동
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    analogWrite(10, vy);
    delay(time);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    analogWrite(10, 0);
}

void moveActuators_xy(float v, float time) {
    // x축과 y축 액추에이터를 주어진 시간 동안 동시에 작동
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    analogWrite(11, v);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    analogWrite(10, v);
    delay(time);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    analogWrite(11, 0);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    analogWrite(10, 0);
}

// 프로그램 종료 함수 (무한 대기)
void stopActuators() {
    Serial.println("Drawing completed.");
    while (1); // 무한 대기
}

// 기본적인 리니어 엑추에이터 제어 함수들
void nomal_move_x(int dir, int time){
    // 주어진 시간과 방향으로 x축 리니어 엑추에이터 작동
    if(dir==1){
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      analogWrite(11, 255);
      delay(time);
    }
    else{
      digitalWrite(4, HIGH);
      digitalWrite(3, LOW);
      analogWrite(11, 255);
      delay(time);
    }
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    analogWrite(11, 0);
}

void nomal_move_y(int dir, int time){
    // 주어진 시간과 방향으로 y축 리니어 엑추에이터 작동
    if(dir==1){
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      analogWrite(10, 255);
      delay(time);
    }
    else{
      digitalWrite(6, HIGH);
      digitalWrite(5, LOW);
      analogWrite(10, 255);
      delay(time);
    }
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    analogWrite(10, 0);
}

void nomal_move_z(int dir, int time){
    // 주어진 시간과 방향으로 z축 리니어 엑추에이터 작동
    if(dir==1){
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      analogWrite(9, 255);
      delay(time);
    }
    else{
      digitalWrite(8, HIGH);
      digitalWrite(7, LOW);
      analogWrite(9, 255);
      delay(time);
    }
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    analogWrite(9, 0);
}

// 종료 코드(무한 대기)
void end(){
  while(1){
    // 종료
  }
}

// 본 코드 작성에는 Chat GPT가 활용 되었음.
