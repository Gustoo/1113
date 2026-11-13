/*
 * 蜂鸣器正极 → Pin 8，负极 → GND
 */

#define BUZZER_PIN 8

// ---------- 音符频率 ----------
#define REST     0
#define NOTE_G4  392  // 低音 5 (补充)
#define NOTE_A4  440  // 低音 6
#define NOTE_B4  494  // 低音 7 (补充)
#define NOTE_C5  523  // 1
#define NOTE_D5  587  // 2
#define NOTE_E5  659  // 3
#define NOTE_F5  698  // 4
#define NOTE_G5  784  // 5
#define NOTE_A5  880  // 6
#define NOTE_B5  988  // 7
#define NOTE_C6  1047 // 1̇ (高音)
#define NOTE_D6  1175 // 2̇
#define NOTE_E6  1319 // 3̇

int tempo = 90; 
int unit = 60000 / tempo / 2; // 八分音符时长

int melody[] = {
  // ================= 前奏 (8小节) =================
  NOTE_E5, NOTE_G5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_D5,
  NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_A5, NOTE_B5,
  NOTE_E5, NOTE_G5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_D5,
  NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_G5, NOTE_D5,
  NOTE_E5, NOTE_G5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_D5,
  NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_G5, NOTE_D5,
  NOTE_E5, NOTE_G5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_D5,
  NOTE_E5, NOTE_G5, NOTE_A5, NOTE_E5, NOTE_D5, NOTE_A5,

  // ================= 主歌 A (第9-15小节) =================
  NOTE_E5, NOTE_E5, NOTE_D5, NOTE_F5, NOTE_E5, NOTE_D5,
  NOTE_D5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_F5, NOTE_E5, NOTE_D5,
  NOTE_D5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E5,
  REST, NOTE_E5, NOTE_G5, NOTE_C6, NOTE_C6,
  NOTE_B5, NOTE_C6, NOTE_B5, NOTE_C6,
  NOTE_B5, NOTE_A5, NOTE_G5, REST, NOTE_G5, NOTE_D5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, REST, NOTE_G5,

  // ================= 主歌后半段 (第23-28小节) =================
  // 1 2 1 1 2 3.
  NOTE_C5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E5,
  // 3 0 3 5 1̇
  NOTE_E5, REST, NOTE_E5, NOTE_G5, NOTE_C6,
  // 7̇ 1̇ 7̇ 1̇
  NOTE_B5, NOTE_C6, NOTE_B5, NOTE_C6,
  // 7̇ 6̇ 5 0 5 2 4
  NOTE_B5, NOTE_A5, NOTE_G5, REST, NOTE_G5, NOTE_D5, NOTE_F5,
  // 4 3 3 0 5
  NOTE_F5, NOTE_E5, NOTE_E5, REST, NOTE_G5,
  // 4 2 2 3 5
  NOTE_F5, NOTE_D5, NOTE_D5, NOTE_E5, NOTE_G5,

  // ================= 主歌结尾 (第29-32小节) =================
  // 7̇ 1̇. 0 7 1
  NOTE_B5, NOTE_C6, REST, NOTE_B5, NOTE_C5,
  // 2 1 0 1 5 1
  NOTE_D5, NOTE_C5, REST, NOTE_C5, NOTE_G4, NOTE_C5,
  // 4 4 4 3 2 | 1 2 1 1
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_C5,
  // 7̇ 1̇. 0.
  NOTE_B5, NOTE_C6, REST,

  // ================= 导歌A (第33-41小节) =================
  // 6 5 5 5 4 4
  NOTE_A5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_F5,
  // 2 3 2 2 2 5
  NOTE_D5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_G5,
  // 5 4 4 4 4 3 2
  NOTE_G5, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
  
  // 2 1 1 7 1.
  NOTE_D5, NOTE_C5, NOTE_C5, NOTE_B4, NOTE_C5,
  // 6 5 5 5 4 4
  NOTE_A5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_F5,
  // 3 2 2 2 4
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_F5,
  // 3 3 3 3 3 2 3
  NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_E5,
  // 2̇ 1̇ 1̇ 0 1̇
  NOTE_D6, NOTE_C6, NOTE_C6, REST, NOTE_C6,
  // 7 6 6.
  NOTE_B5, NOTE_A5, NOTE_A5
};

float noteDurations[] = {
  // 前奏节奏
  1,1,1,1,1,1, 3,0.5,0.5,1,0.5,0.5,
  1,1,1,1,1,1, 3,0.5,0.5,1,0.5,0.5,
  1,1,1,1,1,1, 3,0.5,0.5,1,0.5,0.5,
  1,1,1,1,1,1, 1,1,1,1,1,1,

  // 主歌A节奏
  1,1,1,1,1,1,
  1,1,1,1,0.5,0.5,1,
  1,1,0.5,0.5,3,
  3,1,0.5,0.5,1,
  1,1,1,3,
  1,1,1,1,0.5,0.5,1,
  1,0.5,0.5,1,3,

  // 主歌后半段节奏
  0.5,0.5,0.5,0.5,0.5,3.0,       // 1 2 1 1 2 3.
  1.0,1.0,1.0,1.0,1.0,           // 3 0 3 5 1̇
  0.5,0.5,1.0,2.0,               // 7̇ 1̇ 7̇ 1̇ (连音延长)
  1.0,1.0,1.0,1.0,1.0,0.5,0.5,   // 7̇ 6̇ 5 0 5 2 4
  1.0,0.5,0.5,1.5,2.0,           // 4 3 3 0 5
  1.0,0.5,0.5,1.0,3.0,           // 4 2 2 3 5

  // 主歌结尾节奏
  1.0,3.0,1.0,0.5,0.5,           // 7̇ 1̇. 0 7 1
  1.0,1.0,1.0,1.0,1.0,1.0,       // 2 1 0 1 5 1
  1,1,0.5,0.5,1,0.5,0.5,1,3,     // 4 4 4 3 2 | 1 2 1 1
  1.0,3.0,2.0,                   // 7̇ 1̇. 0.

  // 导歌A节奏
  1.0,1.0,1.0,0.5,0.5,1.0,       // 6 5 5 5 4 4
  1.0,0.5,0.5,1.0,1.0,2.0,       // 2 3 2 2 2 5
  1.0,1.0,1.0,0.5,0.5,0.5,0.5,   // 5 4 4 4 4 3 2
  
  1.0,1.0,0.5,0.5,3.0,           // 2 1 1 7 1.
  1.0,1.0,1.0,0.5,0.5,1.0,       // 6 5 5 5 4 4
  1.0,0.5,0.5,1.0,3.0,           // 3 2 2 2 4
  1.0,1.0,1.0,1.0,0.5,0.5,1.0,   // 3 3 3 3 3 2 3
  1.0,1.0,0.5,0.5,3.0,           // 2̇ 1̇ 1̇ 0 1̇
  1.0,1.0,4.0                    // 7 6 6.
};

int melodyLength = sizeof(melody) / sizeof(melody[0]);

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < melodyLength; i++) {
    int noteDuration = (int)(unit * noteDurations[i]);

    if (melody[i] == REST) {
      noTone(BUZZER_PIN);
      delay(noteDuration);
    } else {
      int playTime = noteDuration * 0.85; // 稍微加长发声占比，让长音更饱满
      tone(BUZZER_PIN, melody[i], playTime);
      delay(noteDuration);
      noTone(BUZZER_PIN);
    }
  }
  delay(3000); // 弹完一遍，长停顿，情绪拉满
}