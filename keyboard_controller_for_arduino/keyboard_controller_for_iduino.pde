
// 키보드로부터 입력을 받아 해당 키의 값을 아두이노의 시리얼 통신으로 전달하여 원하는 제어 명령을 실행하는 프로그램 입니다.

import processing.serial.*;

Serial myPort;

void setup() {
  size(200, 200);
  // 아두이노가 연결된 포트 이름을 직접 입력해야 프로그램이 정상적으로 작동합니다.
  String portName = "";  // Windows의 경우 "COM3" 형식, Mac/Linux의 경우 "/dev/tty.usbmodemXXXXX" 형식
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  // draw 함수는 비워두어도 됩니다.
}

void keyPressed(){
  // 특정 키보드의 키가 입력되면 해당 키의 값을 아두이노의 시리얼 통신으로 전송합니다.
  if (key == 'w') {
    myPort.write('w');
  } else if (key == 's') {
    myPort.write('s');
  }else if (key == 'q') {
    myPort.write('q');
  }else if (key == 'e') {
    myPort.write('e');
  }else if (key == 'r') {
    myPort.write('r');
  }else if (key == 'a') {
    myPort.write('a');
  }
  else if (key == 'd') {
    myPort.write('d');
  }
  else if (key == 'f') {
    myPort.write('f');
  }
  else if (key == 'j') {
    myPort.write('j');
  }
  else if (key == 'z') {
    myPort.write('z');
  }
  else if (key == 'c') {
    myPort.write('c');
  }
  else if (key == 'v') {
    myPort.write('v');
  }
  else if (key == 'b') {
    myPort.write('b');
  }
  else if (key == 'i') {
    myPort.write('i');
  }
  else if (key == 'o') {
    myPort.write('o');
  }
}

void keyReleased() {
  // 키가 릴리즈되면 'x'와 'k' 명령(중단 코드)을 아두이노에 전송 합니다.
  myPort.write('x');
  myPort.write('k');
}

// 본 코드 작성에는 Chat GPT가 활용 되었음.
