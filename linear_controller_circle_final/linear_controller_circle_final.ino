
// 리니어 엑추에이터 로봇 팔의 x축과 y축을 이용하여 원 궤적의 일부를 그리는 코드입니다.

// 전역 변수 선언 및 초기화
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
  pinMode(2, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // y축이 작동해야 하는 시간을 계산한 뒤, 설정한 시간만큼 x축과 y축을 움직여 원 모양의 궤적을 그릴 수 있도록 작성한 코드입니다.
  tx += dtx;  // 누적 x축 이동 시간 추가
  px += dtx*v;  // x축 좌표 재설정
  y_n = R - sqrt((R*R) - (v*v)*(tx*tx));  // n번째 y 좌표 정보 재설정
  y_n1 = R - sqrt((R*R) - (v*v)*((tx+dtx)*(tx+dtx)));  // n+1번째 y 좌표 정보 재설정
  dty = (y_n1 - y_n)/v;  // 이번 loop의 y축 이동 시간 계산
  
  // x축과 y축이 동시에 움직이고, 더 많은 시간을 움직여야하는 축은 다른 축의 이동이 끝난 뒤 추가로 이동함.
  if(dty>dtx){
    moveActuators_xy(255, dtx);
    moveActuators_y(255, (dty-dtx));
  }
  else{
    moveActuators_xy(255, dty);
    moveActuators_x(255, (dtx-dty));
  }

  py += v*dty; // y축 좌표 재설정
  t_total += 10 + int(dty);  // 누적 실행 시간 업데이트
  Serial.println(t_total);  // 누적 실행 시간을 시리얼 통신으로 출력
}

// 리니어 액추에이터 제어 함수
void moveActuators_x(float vx, float time) {
    // 입력된 시간만큼 x축 증가
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    analogWrite(11, vx);
    delay(time);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    analogWrite(11, 0);
}

void moveActuators_y(float vy, float time) {
    // 입력된 시간만큼 y축 증가
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    analogWrite(10, vy);
    delay(time);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    analogWrite(10, 0);
}

void moveActuators_xy(float v, float time) {
    // 입력된 시간 만큼 x축과 y축이 동시에 증가
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

// 그리기 종료 코드
void stopActuators() {
    Serial.println("Drawing completed.");
    while (1); // 무한 대기
}

// 본 코드 작성에는 Chat GPT가 활용 되었음.
