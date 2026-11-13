/*
 * 蜂鸣器正极 → Pin 8，负极 → GND
 */

#define BUZZER_PIN 8

// ---------- 音符频率 (C调中高音区，清脆不刺耳) ----------
#define REST     0
#define NOTE_E5  659  // 3
#define NOTE_F5  698  // 4
#define NOTE_G5  784  // 5
#define NOTE_A5  880  // 6
#define NOTE_B5  988  // 7
#define NOTE_C6  1047 // 1̇
#define NOTE_D6  1175 // 2̇
#define NOTE_E6  1319 // 3̇

// ---------- 速度 ----------
int tempo = 109;  // 原曲节奏
int beat = 60000 / tempo;

// ---------- 旋律数组 (完全对照图片第一行) ----------
int melody[] = {
  // 第一句：1=bB
  // 1̇ 3̇ | 3̇ 2̇ 1̇ 6 1̇ 5 5
  NOTE_C6, NOTE_E6,
  NOTE_E6, NOTE_D6, NOTE_C6, NOTE_A5,
  NOTE_C6, NOTE_G5, NOTE_G5,

  // 1̇ 3̇ | 3̇ 2̇ 1̇ 6 1̇ -
  NOTE_C6, NOTE_E6,
  NOTE_E6, NOTE_D6, NOTE_C6, NOTE_A5,
  NOTE_C6, REST,

  // 第二句：1=G
  // 6 1̇ | 1̇ 7 6 4 6 3 3
  NOTE_A5, NOTE_C6,
  NOTE_C6, NOTE_B5, NOTE_A5, NOTE_F5,
  NOTE_A5, NOTE_E5, NOTE_E5,

  // 6 1̇ | 1̇ 7 6 4 6 -
  NOTE_A5, NOTE_C6,
  NOTE_C6, NOTE_B5, NOTE_A5, NOTE_F5,
  NOTE_A5, REST
};

// ---------- 节奏数组 ----------
float noteDurations[] = {
  // 第一句节奏
  0.5, 0.5,                  // 1̇ 3̇
  0.25, 0.25, 0.25, 0.25,    // 3̇ 2̇ 1̇ 6 (十六分音符)
  0.5, 0.5, 0.5,             // 1̇ 5 5
  
  0.5, 0.5,                  // 1̇ 3̇
  0.25, 0.25, 0.25, 0.25,    // 3̇ 2̇ 1̇ 6
  1.5, 0.5,                  // 1̇ - (拉长)

  // 第二句节奏
  0.5, 0.5,                  // 6 1̇
  0.25, 0.25, 0.25, 0.25,    // 1̇ 7 6 4 (十六分音符)
  0.5, 0.25, 0.75,           // 6 3 3
  
  0.5, 0.5,                  // 6 1̇
  0.25, 0.25, 0.25, 0.25,    // 1̇ 7 6 4
  1.5, 0.5                   // 6 - (拉长)
};

int melodyLength = sizeof(melody) / sizeof(melody[0]);

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < melodyLength; i++) {
    int noteDuration = (int)(beat * noteDurations[i]);

    if (melody[i] == REST) {
      noTone(BUZZER_PIN);
      delay(noteDuration);
    } else {
      int playTime = noteDuration * 0.8;   // 80%发声，20%留白，消除粘连杂音
      tone(BUZZER_PIN, melody[i], playTime);
      delay(noteDuration);
      noTone(BUZZER_PIN);
    }
  }
  delay(800);   // 段与段之间稍微停顿一下，然后自然进入下一遍循环
}