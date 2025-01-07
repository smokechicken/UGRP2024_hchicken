
// Processing을 이용해 원 궤적 그리기 방법을 시뮬레이션한 코드입니다.

//전역 변수 설정
float tx = 0;
int t_total = 0;
float dtx = 10;
float dty = 0;
float v = 0.01;
float px = 10;
float py = 10;
float R = 380;
float y_n;
float y_n1;

void setup(){
  // 창 생성
  size(800, 800);
  background(255);
}

void draw(){
   point(100, 100);  // 시작점 표시
   // 마우스 클릭시 마우스 좌표에 점 생성(시뮬레이션엔 사용하지 않음)
   if (mousePressed){
      point(pmouseX, pmouseY);
   }
   // 일정 횟수 반복으로 코드를 제한함.
   for(int i=0;i<80;i++){
     line(px, py, px + dtx*v, py);  // x축 좌표 이동선 그리기
     tx += dtx;  // 
     px += dtx*v;  // x좌표를 이동(업데이트)
     y_n = R - sqrt((R*R) - (v*v)*(tx*tx));  // y좌표 n번째 계산
     y_n1 = R - sqrt((R*R) - (v*v)*((tx+dtx)*(tx+dtx)));  // y좌표 n+1번째 계산
     dty = (y_n1 - y_n)/v;  // y좌표 이동 시간 계산
     line(px, py, px, py + v*dty);  // y축 좌표 이동선 그리기
     line(px - dtx*v, py, px, py + v*dty);  // x축과 y축 모두 이동한 뒤의 좌표와 초기 좌표 사이의 선 그리기
     py += v*dty;  // y축 좌표를 이동(업데이트)
     t_total += 10 + int(dty);  // 전체 실행 시간 업데이트
     print(t_total);  // 실행 시간 출력
     print("\n");
     delay(3);  // 프로그램 실행 속도 조
 }
}
