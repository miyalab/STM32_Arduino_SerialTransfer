//----------------------------
// シンボル定義
//----------------------------
// シリアル通信関連
constexpr uint8_t SERIAL_READDATA_BUFF_SIZE = 64;
constexpr uint32_t SERIAL_BAUDRATE = 115200;

//--------------------------------------------------------------
// マイコン初期化
//--------------------------------------------------------------
void setup()
{
    // シリアル通信関連
    Serial.flush();
    Serial.begin(SERIAL_BAUDRATE);
}

//--------------------------------------------------------------
// ループ処理
//--------------------------------------------------------------
void loop()
{
    static int wheelFL, wheelFR, wheelBL, wheelBR;
    static uint8_t serialDataIndex;
    static char serialReadData[SERIAL_READDATA_BUFF_SIZE];

    // シリアルデータ読み込み
    while(Serial.available()){
        serialReadData[serialDataIndex] = Serial.read();
        if(serialReadData[serialDataIndex] == '\n'){
            sscanf(serialReadData, "%d %d %d %d", 
                &wheelFL, &wheelFR, &wheelBL, &wheelBR);
            sprintf(serialReadData, "");
            serialDataIndex = 0;
            Serial.print(wheelFL);
            Serial.print(",");
            Serial.print(wheelFR);
            Serial.print(",");
            Serial.print(wheelBL);
            Serial.print(",");
            Serial.println(wheelBR);
        }
        else{
            serialDataIndex++;
        }
    }
}

//--------------------------------------------------------------
// end of file
//--------------------------------------------------------------
