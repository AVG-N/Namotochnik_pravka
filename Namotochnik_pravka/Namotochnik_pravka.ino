#include "GyverStepper.h"
#include "GyverTimers.h"
#include "GyverStepper.h"
#include "GyverTimers.h"
//Время шага, мкс
#define DRIVER_STEP_TIME 4
//Время шага, мкс
#define DRIVER_STEP_TIME 4
//Подключаем мотор
GStepper<STEPPER2WIRE> stepper56724086(200, 60, 61);
// 60 - STEP
// 61 - DIR
volatile bool Ready56724086;
bool curCCW56724086;
bool curAutoPower56724086;
float curMaxSpeed56724086 = 1000;
float curAcceleration56724086 = 0;
float curEndlessSpeed56724086;
//Подключаем мотор
GStepper<STEPPER2WIRE> stepper69894407(200, 54, 55);
// 54 - STEP
// 55 - DIR
volatile bool Ready69894407;
bool curCCW69894407;
bool curAutoPower69894407;
float curMaxSpeed69894407 = 1000;
float curAcceleration69894407 = 0;
float curEndlessSpeed69894407;
#include <LiquidCrystal.h>
#include <EEPROM.h>
LiquidCrystal _lcd1(16, 17, 23, 25, 27, 29);
int _dispTempLength1=0;
boolean _isNeedClearDisp1;
bool in_182541836_1;
bool rst_182541836_1;
bool out_182541836_1;
bool tmp_182541836_1=0;
bool in_182541836_3;
bool rst_182541836_3;
bool out_182541836_3;
bool tmp_182541836_3=0;
const int _menuParametrsArray[]  PROGMEM =  {1, 2, 1, 0, 0, 0, 2, 3, 1, 4, 2, 0, 2, 8, 1, 0, 0, 0, 2, 3, 1, 2, 1, 0, 3, 4, 1, 0, 0, 0, 2, 4, 1, 4, 3, 0, 4, 4, 2, 0, 0, 0, 3, 1, 1, 4, 4, 0};
byte _menuValueArray_byte[1];
const byte _menuConstantValuesArray_byte[]  PROGMEM =  {1, 80, 60};
int _menuValueArray_int[2];
const int _menuConstantValuesArray_int[]  PROGMEM =  {1, 10000, 200, 300};
float _menuValueArray_float[1];
const float _menuConstantValuesArray_float[]  PROGMEM =  {0.01, 0.3, 0.1};
const char _flprogMenuNameString1[] PROGMEM = "\xE0\xB8\x61\xBC\x65\xBF\x70:";
const char _flprogMenuNameString2[] PROGMEM = "\x42\xB8\xBF\xBA\xB8:";
const char _flprogMenuNameString3[] PROGMEM = "\x43\xBA\x6F\x70\x6F\x63\xBF\xC4:";
const char _flprogMenuNameString4[] PROGMEM = "Step karetky:";
const char* const _flprogMenuStringsArray[] PROGMEM = { _flprogMenuNameString1,  _flprogMenuNameString2,  _flprogMenuNameString3,  _flprogMenuNameString4};
struct _menuItemStricture 
{
     int startInArrayIndex;
}
;
struct _menuMainStricture 
{
    int startIndex;
    int stopIndex;
    bool isSwitchMenuAroundRing;
    _menuItemStricture  currentItem;
}
;
_menuItemStricture _MenuItems[4];
_menuMainStricture _MainMenus[1];
bool _gtv1 = 0; //СТОП X
bool _gtv2 = 0; //Старт на исходню X
bool _gtv19 = 0; //СТОП на исходню X
bool _gtv22 = 0; //Реверс X , FALSE
long _gtv15; //Количество шагов - задаем количество шагов для мотора X, на которе будет сдвигатся каретка.
long _gtv23; //Шаги на X - сколько шагов отшагал мотор X (каретка)
bool _gtv24 = 0; //Откатились от кнцевика Х
bool _gtv25 = 0; //Старт каретка-мотор Х
bool _gtv26 = 0; //Откатывемся Х
bool _gtv30 = 0; //На исходную Х
bool _gtv31 = 0; //Встал на исходную Х
bool _gtv5 = 0; //СТОП намотка Y
bool _gtv3 = 0; //Питание ВКЛ-Старт Y
float _gtv6; //Скорость Y
float _gtv10; //Ускорение Y
bool _gtv18 = 0; //СТОП на исходню Y
bool _gtv12 = 0; //СТОП намотка Y после намотки каждого слоя
bool _gtv32 = 0; //Встал на исходную Y
bool _gtv11 = 0; //Заставка стоп
bool _gtv13 = 0; //Первое включение СТОП Y
bool _gtv8 = 0; //Меню ВКЛ/ВЫКЛ
byte _gtv9 = 0;
bool _gtv14 = 0; //ПУСК намотка - переменная принимает значение TRUE - включает намотку
bool _gtv16 = 0; //Витки один слой R - обнуляем счетчик количества витков после намотки каждого слоя
bool _gtv17 = 0; //Режим работы станка ВКЛ
bool _gtv20 = 0; //Пауза намотка
bool _gtv21 = 0; //Снять с паузы/старт
byte _gtv29; //Количество проходов со счетчика проходов
bool _trgrt24 = 0;
bool _trgrt24I = 0;
String _MenuBlock_18613862_MNO;
String _MenuBlock_18613862_VNO;
bool _MenuBlock_18613862_OEIS = 0;
bool _MenuBlock_18613862_OMUIS = 0;
bool _MenuBlock_18613862_OMDIS = 0;
bool _MenuBlock_18613862_OVUIS = 0;
bool _MenuBlock_18613862_OVDIS = 0;
unsigned long _MenuBlock_18613862_VUDST = 0UL;
unsigned long _MenuBlock_18613862_VUDSPT = 0UL;
int _MenuBlock_18613862_VUDSM = 0;
int _MenuBlock_18613862_VUDPT = 0;
int _disp20oldLength = 0;
bool _trgrt10 = 0;
bool _trgrt10I = 0;
bool _trgt1 = 0;
bool _trgt1I = 0;
bool _trgrt1 = 0;
bool _trgrt1I = 0;
bool _trgrt3 = 0;
bool _trgrt3I = 0;
int _disp13oldLength = 0;
bool _count4I = 0;
int _count4_Value = 0;
bool _count4MaxLO = 0;
bool _bounseInputD37S = 0;
bool _bounseInputD37O = 0;
unsigned long _bounseInputD37P = 0UL;
bool _count1I = 0;
int _count1_Value = 0;
int _disp3oldLength = 0;
bool _bounseInputD31S = 0;
bool _bounseInputD31O = 0;
unsigned long _bounseInputD31P = 0UL;
bool _trgrt27 = 0;
bool _trgrt27I = 0;
bool _dms2Q0 = 0;
bool _dms2Q1 = 0;
bool Out_155084832_69894407;
long Out_123216258_69894407;
bool _trgrt17 = 0;
bool _trgrt17I = 0;
bool _trgrt2 = 0;
bool _trgrt2I = 0;
bool _trgrt15 = 0;
bool _trgrt15I = 0;
bool _trgrt31 = 0;
bool _trgrt31I = 0;
bool _trgrt7 = 0;
bool _trgrt7I = 0;
int _disp11oldLength = 0;
bool _bounseInputD39S = 0;
bool _bounseInputD39O = 0;
unsigned long _bounseInputD39P = 0UL;
int _disp1oldLength = 0;
bool _trgrt23 = 0;
bool _trgrt23I = 0;
bool _count2I = 0;
int _count2_Value = 0;
int _disp12oldLength = 0;
int _disp18oldLength = 0;
int _disp6oldLength = 0;
int _disp4oldLength = 0;
bool _trgrt6 = 0;
bool _trgrt6I = 0;
bool _trgrt4 = 0;
bool _trgrt4I = 0;
int _disp2oldLength = 0;
bool _trgrt9 = 0;
bool _trgrt9I = 0;
int _disp8oldLength = 0;
bool _trgrt26 = 0;
bool _trgrt26I = 0;
bool _bounseInputD33S = 0;
bool _bounseInputD33O = 0;
unsigned long _bounseInputD33P = 0UL;
int _disp9oldLength = 0;
bool Out_155084832_56724086;
bool _trgrt18 = 0;
bool _trgrt18I = 0;
bool _trgrt16 = 0;
bool _trgrt16I = 0;
bool _trgrt19 = 0;
bool _trgrt19I = 0;
bool _tim1I = 0;
bool _tim1O = 0;
unsigned long _tim1P = 0UL;
int _disp19oldLength = 0;
bool _trgrt25 = 0;
bool _trgrt25I = 0;
int _disp17oldLength = 0;
bool _trgrt29 = 0;
bool _trgrt29I = 0;
bool _trgrt14 = 0;
bool _trgrt14I = 0;
int _disp14oldLength = 0;
int _disp15oldLength = 0;
int _disp16oldLength = 0;
bool _trgrt5 = 0;
bool _trgrt5I = 0;
bool _bounseInputD35S = 0;
bool _bounseInputD35O = 0;
unsigned long _bounseInputD35P = 0UL;
bool _trgrt11 = 0;
bool _trgrt11I = 0;
bool _trgs1 = 0;
bool _trgrt13 = 0;
bool _trgrt13I = 0;
byte _swi2;
bool _trgrt20 = 0;
bool _trgrt20I = 0;
bool _trgrt8 = 0;
bool _trgrt8I = 0;
bool _dms1Q0 = 0;
bool _dms1Q1 = 0;
bool _trgrt28 = 0;
bool _trgrt28I = 0;
bool _tim2I = 0;
bool _tim2O = 0;
unsigned long _tim2P = 0UL;
byte _swi1;
bool _trgrt21 = 0;
bool _trgrt21I = 0;
int _disp5oldLength = 0;
bool _trgrt12 = 0;
bool _trgrt12I = 0;
int _disp10oldLength = 0;
bool _tempVariable_bool;
int _tempVariable_int;
void setup()
{
    pinMode(31, INPUT_PULLUP);
    pinMode(33, INPUT_PULLUP);
    pinMode(35, INPUT_PULLUP);
    pinMode(37, INPUT_PULLUP);
    pinMode(39, INPUT_PULLUP);
    pinMode(3, INPUT);
    pinMode(14, INPUT);
    pinMode(13, OUTPUT);
    digitalWrite(13, 0);
    pinMode(38, OUTPUT);
    digitalWrite(38, 0);
    pinMode(56, OUTPUT);
    digitalWrite(56, 0);
    if(((readByteFromEEPROM(0, 0, 0x0))) != 6) 
    {
        (updateByteToEEPROM(0, 0, 0x0, (6)));
        (updateFloatToEEPROM(1, 0, 0x0, (0.1)));
        (updateByteToEEPROM(5, 0, 0x0, (70)));
        (updateIntegerToEEPROM(6, 0, 0x0, (1555)));
        (updateIntegerToEEPROM(8, 0, 0x0, (50)));
    }
    _lcd1.begin(16, 4);
    _bounseInputD31O =  digitalRead(31);
    _bounseInputD35O =  digitalRead(35);
    _bounseInputD33O =  digitalRead(33);
    _bounseInputD39O =  digitalRead(39);
    _bounseInputD37O =  digitalRead(37);
    _MenuItems[0].startInArrayIndex = 0;
    _MenuItems[1].startInArrayIndex = 12;
    _MenuItems[2].startInArrayIndex = 24;
    _MenuItems[3].startInArrayIndex = 36;
    _MainMenus[0].startIndex = 1;
    _MainMenus[0].isSwitchMenuAroundRing = 1;
    _MainMenus[0].stopIndex = 4;
    _MainMenus[0].currentItem = _MenuItems[0];
    _menuValueArray_float[0] = (readFloatFromEEPROM(1, 0, 0x0));
    _menuValueArray_byte[0] = (readByteFromEEPROM(5, 0, 0x0));
    _menuValueArray_int[0] = (readIntegerFromEEPROM(6, 0, 0x0));
    _menuValueArray_int[1] = (readIntegerFromEEPROM(8, 0, 0x0));
    // настраиваем прерывания с периодом, при котором 
      // система сможет обеспечить максимальную скорость мотора.
      // Для большей плавности лучше лучше взять период чуть меньше, например в два раза
      Timer1.setPeriod(70);
    // взводим прерывание
      Timer1.enableISR(CHANNEL_A);
    // настраиваем прерывания с периодом, при котором 
      // система сможет обеспечить максимальную скорость мотора.
      // Для большей плавности лучше лучше взять период чуть меньше, например в два раза
      Timer3.setPeriod(100);
    // взводим прерывание
      Timer3.enableISR(CHANNEL_A);
}
void loop()
{
    Out_155084832_56724086 = Ready56724086;
    Out_155084832_69894407 = Ready69894407;
    if (_isNeedClearDisp1) 
    {
        _lcd1.clear();
        _isNeedClearDisp1= 0;
    }
    bool  _bounceInputTmpD35 =  (digitalRead (35));
    if (_bounseInputD35S)
    {
        if (millis() >= (_bounseInputD35P + 40))
        {
            _bounseInputD35O= _bounceInputTmpD35;
            _bounseInputD35S=0;
        }
    }
    else
    {
        if (_bounceInputTmpD35 != _bounseInputD35O)
        {
            _bounseInputD35S=1;
            _bounseInputD35P = millis();
        }
    }
    bool  _bounceInputTmpD33 =  (digitalRead (33));
    if (_bounseInputD33S)
    {
        if (millis() >= (_bounseInputD33P + 40))
        {
            _bounseInputD33O= _bounceInputTmpD33;
            _bounseInputD33S=0;
        }
    }
    else
    {
        if (_bounceInputTmpD33 != _bounseInputD33O)
        {
            _bounseInputD33S=1;
            _bounseInputD33P = millis();
        }
    }
    bool  _bounceInputTmpD31 =  (digitalRead (31));
    if (_bounseInputD31S)
    {
        if (millis() >= (_bounseInputD31P + 40))
        {
            _bounseInputD31O= _bounceInputTmpD31;
            _bounseInputD31S=0;
        }
    }
    else
    {
        if (_bounceInputTmpD31 != _bounseInputD31O)
        {
            _bounseInputD31S=1;
            _bounseInputD31P = millis();
        }
    }
    bool  _bounceInputTmpD37 =  (digitalRead (37));
    if (_bounseInputD37S)
    {
        if (millis() >= (_bounseInputD37P + 40))
        {
            _bounseInputD37O= _bounceInputTmpD37;
            _bounseInputD37S=0;
        }
    }
    else
    {
        if (_bounceInputTmpD37 != _bounseInputD37O)
        {
            _bounseInputD37S=1;
            _bounseInputD37P = millis();
        }
    }
    bool  _bounceInputTmpD39 =  (digitalRead (39));
    if (_bounseInputD39S)
    {
        if (millis() >= (_bounseInputD39P + 40))
        {
            _bounseInputD39O= _bounceInputTmpD39;
            _bounseInputD39S=0;
        }
    }
    else
    {
        if (_bounceInputTmpD39 != _bounseInputD39O)
        {
            _bounseInputD39S=1;
            _bounseInputD39P = millis();
        }
    }
    //Плата:2
//Наименование:Старт
//Комментарии:Первое включекние.
    if (_gtv11 != 1) 
    {
        if (!(0)) 
        {
            _dispTempLength1 = ((String("\x48\x61\xBC\x6F\xBF\xC0\xB8\xBA"))).length();
            if (_disp1oldLength > _dispTempLength1) 
            {
                _isNeedClearDisp1 = 1;
            }
            _disp1oldLength = _dispTempLength1;
            _lcd1.setCursor(int((16 - _dispTempLength1)/2), 0);
            _lcd1.print((String("\x48\x61\xBC\x6F\xBF\xC0\xB8\xBA")));
        }
         else 
        {
            if (_disp1oldLength > 0) 
            {
                _isNeedClearDisp1 = 1;
                _disp1oldLength = 0;
            }
        }
        if (!(0)) 
        {
            _dispTempLength1 = ((String("\xBA\x61\xBF\x79\xC1\x65\xBA"))).length();
            if (_disp18oldLength > _dispTempLength1) 
            {
                _isNeedClearDisp1 = 1;
            }
            _disp18oldLength = _dispTempLength1;
            _lcd1.setCursor(int((16 - _dispTempLength1)/2), 1);
            _lcd1.print((String("\xBA\x61\xBF\x79\xC1\x65\xBA")));
        }
         else 
        {
            if (_disp18oldLength > 0) 
            {
                _isNeedClearDisp1 = 1;
                _disp18oldLength = 0;
            }
        }
        if (!(0)) 
        {
            _dispTempLength1 = ((String("\xE3\xBB\xC7\x20\xB3\x65\x63\x6F\xB3"))).length();
            if (_disp19oldLength > _dispTempLength1) 
            {
                _isNeedClearDisp1 = 1;
            }
            _disp19oldLength = _dispTempLength1;
            _lcd1.setCursor(int((16 - _dispTempLength1)/2), 2);
            _lcd1.print((String("\xE3\xBB\xC7\x20\xB3\x65\x63\x6F\xB3")));
        }
         else 
        {
            if (_disp19oldLength > 0) 
            {
                _isNeedClearDisp1 = 1;
                _disp19oldLength = 0;
            }
        }
        if (!(0)) 
        {
            _dispTempLength1 = ((String("AVG V6_0R 161026"))).length();
            if (_disp17oldLength > _dispTempLength1) 
            {
                _isNeedClearDisp1 = 1;
            }
            _disp17oldLength = _dispTempLength1;
            _lcd1.setCursor(int((16 - _dispTempLength1)/2), 3);
            _lcd1.print((String("AVG V6_0 161026")));
        }
         else 
        {
            if (_disp17oldLength > 0) 
            {
                _isNeedClearDisp1 = 1;
                _disp17oldLength = 0;
            }
        }
        delay (3000);
        if (!(0)) 
        {
             if (_trgrt1I) 
            {
                 _trgrt1 = 0;
            }
             else 
            {
                _trgrt1 = 1;
                _trgrt1I = 1;
            }
        }
         else 
        {
            _trgrt1 = 0;
            _trgrt1I = 0;
        }
        ;
        if (_trgrt1) 
        {
            _dispTempLength1 = ((String("                "))).length();
            if (_disp2oldLength > _dispTempLength1) 
            {
                _isNeedClearDisp1 = 1;
            }
            _disp2oldLength = _dispTempLength1;
            _lcd1.setCursor(int((16 - _dispTempLength1)/2), 0);
            _lcd1.print((String("                ")));
        }
         else 
        {
            if (_disp2oldLength > 0) 
            {
                _isNeedClearDisp1 = 1;
                _disp2oldLength = 0;
            }
        }
        if (_trgrt1) 
        {
            _dispTempLength1 = ((String("                "))).length();
            if (_disp14oldLength > _dispTempLength1) 
            {
                _isNeedClearDisp1 = 1;
            }
            _disp14oldLength = _dispTempLength1;
            _lcd1.setCursor(int((16 - _dispTempLength1)/2), 1);
            _lcd1.print((String("                ")));
        }
         else 
        {
            if (_disp14oldLength > 0) 
            {
                _isNeedClearDisp1 = 1;
                _disp14oldLength = 0;
            }
        }
        if (_trgrt1) 
        {
            _dispTempLength1 = ((String("                "))).length();
            if (_disp15oldLength > _dispTempLength1) 
            {
                _isNeedClearDisp1 = 1;
            }
            _disp15oldLength = _dispTempLength1;
            _lcd1.setCursor(int((16 - _dispTempLength1)/2), 2);
            _lcd1.print((String("                ")));
        }
         else 
        {
            if (_disp15oldLength > 0) 
            {
                _isNeedClearDisp1 = 1;
                _disp15oldLength = 0;
            }
        }
        if (_trgrt1) 
        {
            _dispTempLength1 = ((String("                "))).length();
            if (_disp16oldLength > _dispTempLength1) 
            {
                _isNeedClearDisp1 = 1;
            }
            _disp16oldLength = _dispTempLength1;
            _lcd1.setCursor(int((16 - _dispTempLength1)/2), 3);
            _lcd1.print((String("                ")));
        }
         else 
        {
            if (_disp16oldLength > 0) 
            {
                _isNeedClearDisp1 = 1;
                _disp16oldLength = 0;
            }
        }
        _gtv11 = 1;
    }
    //Плата:5
//Наименование:X Старт на исходную если шторка закрыта на концевике X-MIN
//Комментарии:Выполнять - Первое включение. Отключаем перменной "Первое включение СТОП"
    if (_gtv31 != 1) 
    {
        if (((!(_gtv30)) && ((digitalRead (3))))) 
        {
            _gtv26 = 1;
        }
        if (((!(_gtv26)) && (!((digitalRead (3)))))) 
        {
            _gtv30 = 1;
        }
        if (_gtv26) 
        {
             if (_trgrt15I) 
            {
                 _trgrt15 = 0;
            }
             else 
            {
                _trgrt15 = 1;
                _trgrt15I = 1;
            }
        }
         else 
        {
            _trgrt15 = 0;
            _trgrt15I = 0;
        }
        ;
        if (_trgrt15) 
        {
            _gtv22 = 1;
        }
        if (_trgrt15) 
        {
            _gtv2 = 1;
        }
        if (_trgrt15) 
        {
            _gtv15 = 2000L;
        }
        if ((_gtv23) == (_gtv15)) 
        {
             if (_trgrt28I) 
            {
                 _trgrt28 = 0;
            }
             else 
            {
                _trgrt28 = 1;
                _trgrt28I = 1;
            }
        }
         else 
        {
            _trgrt28 = 0;
            _trgrt28I = 0;
        }
        ;
        if (((_trgrt28) && (_gtv26))) 
        {
            _gtv24 = 1;
        }
        if (_gtv24) 
        {
             if (_trgrt25I) 
            {
                 _trgrt25 = 0;
            }
             else 
            {
                _trgrt25 = 1;
                _trgrt25I = 1;
            }
        }
         else 
        {
            _trgrt25 = 0;
            _trgrt25I = 0;
        }
        ;
        if (_trgrt25) 
        {
            _gtv1 = 1;
        }
        if (_gtv30) 
        {
             if (_trgrt24I) 
            {
                 _trgrt24 = 0;
            }
             else 
            {
                _trgrt24 = 1;
                _trgrt24I = 1;
            }
        }
         else 
        {
            _trgrt24 = 0;
            _trgrt24I = 0;
        }
        ;
        if (((_trgrt25) || (_trgrt24))) 
        {
            _gtv2 = 1;
        }
        if (((_trgrt25) || (_trgrt24))) 
        {
            _gtv22 = 0;
        }
        if (((_trgrt25) || (_trgrt24))) 
        {
            _gtv15 = 5000L;
        }
        if (((((_gtv24) && ((digitalRead (3))))) || (((_gtv30) && ((digitalRead (3))))))) 
        {
            _gtv19 = 1;
        }
        if (((((_gtv24) && ((digitalRead (3))))) || (((_gtv30) && ((digitalRead (3))))))) 
        {
            _gtv31 = 1;
        }
    }
    //Плата:6
//Наименование:Y Старт на исходную. Первое включение.
//Комментарии:Старт на исходную. Первое включение - ставим моторы в исходное положение.
    if (_gtv32 != 1) 
    {
        if ((digitalRead (14))) 
        {
            _gtv18 = 1;
        }
        if (!(0)) 
        {
             if (_trgrt18I) 
            {
                 _trgrt18 = 0;
            }
             else 
            {
                _trgrt18 = 1;
                _trgrt18I = 1;
            }
        }
         else 
        {
            _trgrt18 = 0;
            _trgrt18I = 0;
        }
        ;
        if (_trgrt18) 
        {
            _gtv10 = 500.00;
        }
        if (_trgrt18) 
        {
            _gtv6 = 1500.00;
        }
        if (((!(_gtv18)) && (_trgrt18))) 
        {
            _gtv3 = 1;
        }
        if ((digitalRead (14))) 
        {
            _gtv3 = 0;
        }
        if ((digitalRead (14))) 
        {
            _gtv32 = 1;
        }
    }
    //Плата:7
//Наименование:Первое включение СТОП
//Комментарии:Первое включение СТОП
    if (((_gtv31) && (_gtv32))) 
    {
        _gtv13 = 1;
    }
    //Плата:8
//Наименование:Меню
    if (!(_bounseInputD33O)) 
    {
         if (_trgrt23I) 
        {
             _trgrt23 = 0;
        }
         else 
        {
            _trgrt23 = 1;
            _trgrt23I = 1;
        }
    }
     else 
    {
        _trgrt23 = 0;
        _trgrt23I = 0;
    }
    ;
    if((_gtv9 == 0))
    {
        _dms2Q0 = _trgrt23;
    }
    else 
    {
        _dms2Q0 = 0;
    }
    if((_gtv9 == 1))
    {
        _dms2Q1 = _trgrt23;
    }
    else 
    {
        _dms2Q1 = 0;
    }
    if (((!(_bounseInputD31O)) && (_gtv8))) 
    {
         if (_trgrt2I) 
        {
             _trgrt2 = 0;
        }
         else 
        {
            _trgrt2 = 1;
            _trgrt2I = 1;
        }
    }
     else 
    {
        _trgrt2 = 0;
        _trgrt2I = 0;
    }
    ;
    if(_trgrt2) 
    {
        _tim2O = 1;
        _tim2I = 1;
    }
     else 
    {
         if(_tim2I) 
        {
            _tim2I = 0;
            _tim2P = millis();
        }
         else 
        {
             if (_tim2O) 
            {
                if (_isTimer(_tim2P, 800)) _tim2O = 0;
            }
        }
    }
    if (_tim2O) 
    {
        _dispTempLength1 = ((String("\x43\x4F\x58\x50\x41\x48\x45\x48\x4F"))).length();
        if (_disp13oldLength > _dispTempLength1) 
        {
            _isNeedClearDisp1 = 1;
        }
        _disp13oldLength = _dispTempLength1;
        _lcd1.setCursor(int((16 - _dispTempLength1)/2), 1);
        _lcd1.print((String("\x43\x4F\x58\x50\x41\x48\x45\x48\x4F")));
    }
     else 
    {
        if (_disp13oldLength > 0) 
        {
            _isNeedClearDisp1 = 1;
            _disp13oldLength = 0;
        }
    }
    if(_dms2Q0) _trgs1 = 1;
    if(((!(_bounseInputD31O)) && (_gtv8))) _trgs1 = 0;
    if(_trgs1)
    {
        _swi2=1;
    }
    else
    {
        _swi2=0;
    }
    _gtv9 = _swi2;
    if (_trgs1) 
    {
        _tempVariable_bool  =  1;
        if (! _MenuBlock_18613862_OEIS) 
        {
            _MenuBlock_18613862_OEIS = 1;
            _MainMenus[0].currentItem = _MenuItems[0];
        }
        _tempVariable_int = pgm_read_byte(&_menuParametrsArray[((_MainMenus[0].currentItem).startInArrayIndex)+10]);
        _MenuBlock_18613862_MNO = _readStringFromProgmem ((char*)pgm_read_word(&(_flprogMenuStringsArray[_tempVariable_int - 1])));
        _MenuBlock_18613862_VNO = _menuOutputValueString (0);
    }
     else 
    {
        _tempVariable_bool  =  0;
        if (_MenuBlock_18613862_OEIS)
        {
            _MenuBlock_18613862_OEIS = 0;
            _menuUpdateToEEpromItems();
        }
        _MenuBlock_18613862_MNO = "";
        _MenuBlock_18613862_VNO = "";
    }
    if(0) 
    {
         if (! _MenuBlock_18613862_OMUIS) 
        {
            _MenuBlock_18613862_OMUIS = 1;
            if(_tempVariable_bool)
            {
                _menuUpEvents(0);
                _menuUpdateToEEpromItems();
            }
        }
    }
     else 
    {
        _MenuBlock_18613862_OMUIS = 0;
    }
    if(_dms2Q1) 
    {
         if (! _MenuBlock_18613862_OMDIS) 
        {
            _MenuBlock_18613862_OMDIS = 1;
            if(_tempVariable_bool)
            {
                _menuDownEvents(0);
                _menuUpdateToEEpromItems();
            }
        }
    }
     else 
    {
        _MenuBlock_18613862_OMDIS = 0;
    }
    if(!(_bounseInputD37O)) 
    {
         if (! _MenuBlock_18613862_OVUIS) 
        {
            _MenuBlock_18613862_OVUIS = 1;
            if(_tempVariable_bool)
            {
                  _valueUpEvents(0);
                _MenuBlock_18613862_VUDST = millis();
            }
        }
        if (_tempVariable_bool)
        {
            if (_MenuBlock_18613862_VUDSM == 0) 
            {
                 if (_isTimer(_MenuBlock_18613862_VUDST , 250)) 
                {
                    _MenuBlock_18613862_VUDSM = 1;
                    _MenuBlock_18613862_VUDSPT = millis();
                    _MenuBlock_18613862_VUDPT  = 50;
                }
            }
              else 
            {
                 if (_MenuBlock_18613862_VUDSM == 1) 
                {
                     if (_isTimer(_MenuBlock_18613862_VUDST , 1000)) 
                    {
                        _MenuBlock_18613862_VUDSM = 2;
                        _MenuBlock_18613862_VUDPT  = 10;
                    }
                }
                 if (_isTimer(_MenuBlock_18613862_VUDSPT , _MenuBlock_18613862_VUDPT)) 
                {
                     _valueUpEvents(0);
                    _MenuBlock_18613862_VUDSPT = millis();
                }
            }
        }
    }
     else 
    {
        _MenuBlock_18613862_OVUIS = 0;
        if(! (!(_bounseInputD35O)))
        {
            _MenuBlock_18613862_VUDSM = 0;
        }
    }
    if(!(_bounseInputD35O)) 
    {
         if (! _MenuBlock_18613862_OVDIS) 
        {
            _MenuBlock_18613862_OVDIS = 1;
            if(_tempVariable_bool)
            {
                  _valueDownEvents(0);
                _MenuBlock_18613862_VUDST = millis();
            }
        }
         if (_tempVariable_bool)
        {
            if (_MenuBlock_18613862_VUDSM == 0) 
            {
                 if (_isTimer(_MenuBlock_18613862_VUDST , 250)) 
                {
                    _MenuBlock_18613862_VUDSM = 1;
                    _MenuBlock_18613862_VUDSPT = millis();
                    _MenuBlock_18613862_VUDPT  = 50;
                }
            }
              else 
            {
                 if (_MenuBlock_18613862_VUDSM == 1) 
                {
                     if (_isTimer(_MenuBlock_18613862_VUDST , 1000)) 
                    {
                        _MenuBlock_18613862_VUDSM = 2;
                        _MenuBlock_18613862_VUDPT  = 10;
                    }
                }
                 if (_isTimer(_MenuBlock_18613862_VUDSPT , _MenuBlock_18613862_VUDPT)) 
                {
                     _valueDownEvents(0);
                    _MenuBlock_18613862_VUDSPT = millis();
                }
            }
        }
    }
     else 
    {
        _MenuBlock_18613862_OVDIS = 0;
        if(! (!(_bounseInputD37O)))
        {
            _MenuBlock_18613862_VUDSM = 0;
        }
    }
    if (_gtv8) 
    {
        _dispTempLength1 = ((((_MenuBlock_18613862_MNO) + (_MenuBlock_18613862_VNO)))).length();
        if (_disp20oldLength > _dispTempLength1) 
        {
            _isNeedClearDisp1 = 1;
        }
        _disp20oldLength = _dispTempLength1;
        _lcd1.setCursor(0, 0);
        _lcd1.print((((_MenuBlock_18613862_MNO) + (_MenuBlock_18613862_VNO))));
    }
     else 
    {
        if (_disp20oldLength > 0) 
        {
            _isNeedClearDisp1 = 1;
            _disp20oldLength = 0;
        }
    }
    _gtv8 = _trgs1;
    if (0) 
    {
        _dispTempLength1 = ((String("3"))).length();
        if (_disp4oldLength > _dispTempLength1) 
        {
            _isNeedClearDisp1 = 1;
        }
        _disp4oldLength = _dispTempLength1;
        _lcd1.setCursor(0, 2);
        _lcd1.print((String("3")));
    }
     else 
    {
        if (_disp4oldLength > 0) 
        {
            _isNeedClearDisp1 = 1;
            _disp4oldLength = 0;
        }
    }
    if (0) 
    {
        _dispTempLength1 = ((String("4"))).length();
        if (_disp8oldLength > _dispTempLength1) 
        {
            _isNeedClearDisp1 = 1;
        }
        _disp8oldLength = _dispTempLength1;
        _lcd1.setCursor(0, 3);
        _lcd1.print((String("4")));
    }
     else 
    {
        if (_disp8oldLength > 0) 
        {
            _isNeedClearDisp1 = 1;
            _disp8oldLength = 0;
        }
    }
    //Плата:9
    if (_gtv13)
    {
         if (_tim1I) 
        {
             if (_isTimer(_tim1P, 2000)) 
            {
                _tim1O = 1;
            }
        }
         else 
        {
            _tim1I =1;
            _tim1P = millis();
        }
    }
     else 
    {
        _tim1O = 0;
        _tim1I = 0;
    }
    _gtv17 = _tim1O;
    //Плата:10
//Наименование:ПУСК
//Комментарии:ПУСК - запускает намотку.
    if (_gtv17 == 1) 
    {
        if (((!(_gtv8)) && (!(_bounseInputD31O)))) 
        {
            _gtv14 = 1;
        }
    }
    //Плата:11
//Наименование:Сбросить счетчик количества витков
//Комментарии:После первого нажатия кнопки ПУСК сбросить счетчик.
    //Плата:12
//Наименование:Счетчик витков
//Комментарии:Счетчик витков
    if (_gtv14 == 1) 
    {
        if ((digitalRead (14))) 
        {
             if (_trgrt27I) 
            {
                 _trgrt27 = 0;
            }
             else 
            {
                _trgrt27 = 1;
                _trgrt27I = 1;
            }
        }
         else 
        {
            _trgrt27 = 0;
            _trgrt27I = 0;
        }
        ;
        if (_gtv17) 
        {
             if (_trgrt8I) 
            {
                 _trgrt8 = 0;
            }
             else 
            {
                _trgrt8 = 1;
                _trgrt8I = 1;
            }
        }
         else 
        {
            _trgrt8 = 0;
            _trgrt8I = 0;
        }
        ;
        if (_trgrt8)
        {
            _count1_Value = 0;
        }
         else 
        {
            if (_trgrt27)
            {
                if (! _count1I) 
                {
                    _count1I = 1;
                    _count1_Value = _count1_Value + 1;
                }
            }
             else 
            {
                _count1I = 0;
            }
        }
        if ((digitalRead (14))) 
        {
             if (_trgrt26I) 
            {
                 _trgrt26 = 0;
            }
             else 
            {
                _trgrt26 = 1;
                _trgrt26I = 1;
            }
        }
         else 
        {
            _trgrt26 = 0;
            _trgrt26I = 0;
        }
        ;
        if (_gtv17) 
        {
             if (_trgrt17I) 
            {
                 _trgrt17 = 0;
            }
             else 
            {
                _trgrt17 = 1;
                _trgrt17I = 1;
            }
        }
         else 
        {
            _trgrt17 = 0;
            _trgrt17I = 0;
        }
        ;
        if (_gtv14) 
        {
             if (_trgrt5I) 
            {
                 _trgrt5 = 0;
            }
             else 
            {
                _trgrt5 = 1;
                _trgrt5I = 1;
            }
        }
         else 
        {
            _trgrt5 = 0;
            _trgrt5I = 0;
        }
        ;
        if (((_trgrt17) || (_trgrt5) || (_gtv16)))
        {
            _count4_Value = 0;
        }
         else 
        {
            if (_trgrt26)
            {
                if (! _count4I) 
                {
                    _count4I = 1;
                    if(_count4_Value < ((_menuValueArray_byte[0]))) 
                    {
                        _count4_Value = _count4_Value + 1;
                    }
                }
            }
             else 
            {
                _count4I = 0;
            }
        }
        _count4MaxLO = _count4_Value >= ((_menuValueArray_byte[0]));
        _gtv16 = _count4MaxLO;
        if (_gtv14) 
        {
            _dispTempLength1 = (((((String(_count4_Value, DEC))) + (String(" \x2D\x3E ")) + ((String((_menuValueArray_byte[0]), DEC))) + (String(" ")) + ((String(_count1_Value, DEC)))))).length();
            if (_disp9oldLength > _dispTempLength1) 
            {
                _isNeedClearDisp1 = 1;
            }
            _disp9oldLength = _dispTempLength1;
            _lcd1.setCursor(0, 2);
            _lcd1.print(((((String(_count4_Value, DEC))) + (String(" \x2D\x3E ")) + ((String((_menuValueArray_byte[0]), DEC))) + (String(" ")) + ((String(_count1_Value, DEC))))));
        }
         else 
        {
            if (_disp9oldLength > 0) 
            {
                _isNeedClearDisp1 = 1;
                _disp9oldLength = 0;
            }
        }
        if (_gtv16) 
        {
             if (_trgrt19I) 
            {
                 _trgrt19 = 0;
            }
             else 
            {
                _trgrt19 = 1;
                _trgrt19I = 1;
            }
        }
         else 
        {
            _trgrt19 = 0;
            _trgrt19I = 0;
        }
        ;
        if (_gtv17) 
        {
             if (_trgrt14I) 
            {
                 _trgrt14 = 0;
            }
             else 
            {
                _trgrt14 = 1;
                _trgrt14I = 1;
            }
        }
         else 
        {
            _trgrt14 = 0;
            _trgrt14I = 0;
        }
        ;
        if (_trgrt14)
        {
            _count2_Value = 1;
        }
         else 
        {
            if (_trgrt14)
            {
                _count2_Value = 0;
            }
             else 
            {
                if (_trgrt19)
                {
                    if (! _count2I) 
                    {
                        _count2I = 1;
                        _count2_Value = _count2_Value + 1;
                    }
                }
                 else 
                {
                    _count2I = 0;
                }
            }
        }
        _gtv29 = _count2_Value;
        if (_gtv14) 
        {
            _dispTempLength1 = ((((String("\xA8\x70\x6F\x78\x6F\xE3: ")) + ((String(_count2_Value, DEC)))))).length();
            if (_disp5oldLength > _dispTempLength1) 
            {
                _isNeedClearDisp1 = 1;
            }
            _disp5oldLength = _dispTempLength1;
            _lcd1.setCursor(0, 3);
            _lcd1.print((((String("\xA8\x70\x6F\x78\x6F\xE3: ")) + ((String(_count2_Value, DEC))))));
        }
         else 
        {
            if (_disp5oldLength > 0) 
            {
                _isNeedClearDisp1 = 1;
                _disp5oldLength = 0;
            }
        }
        if (_gtv17) 
        {
             if (_trgrt9I) 
            {
                 _trgrt9 = 0;
            }
             else 
            {
                _trgrt9 = 1;
                _trgrt9I = 1;
            }
        }
         else 
        {
            _trgrt9 = 0;
            _trgrt9I = 0;
        }
        ;
        in_182541836_1 = _gtv16;
        rst_182541836_1 = _trgrt9;
        if((in_182541836_1)&&(!tmp_182541836_1)) 
        {
            out_182541836_1=!out_182541836_1;
        }
        if(rst_182541836_1) 
        {
            out_182541836_1=0;
        }
        tmp_182541836_1=in_182541836_1;
        _gtv22 = out_182541836_1;
    }
    //Плата:13
//Наименование:Режим работы станка.
//Комментарии:Берем данные из МЕНЮ для работы станка.
    if (_gtv17 != 0) 
    {
        if (_gtv14) 
        {
             if (_trgrt11I) 
            {
                 _trgrt11 = 0;
            }
             else 
            {
                _trgrt11 = 1;
                _trgrt11I = 1;
            }
        }
         else 
        {
            _trgrt11 = 0;
            _trgrt11I = 0;
        }
        ;
        if (_trgrt11) 
        {
            _gtv6 = (_menuValueArray_int[0]);
        }
        _gtv10 = 500.00;
    }
    //Плата:14
//Наименование:Стоп моторы -прошли один слой
//Комментарии:Проход
    if (_gtv16) 
    {
        _gtv12 = 0;
    }
    _gtv5 = 0;
    //Плата:15
//Наименование:Пауза
    if (_gtv16) 
    {
         if (_trgrt12I) 
        {
             _trgrt12 = 0;
        }
         else 
        {
            _trgrt12 = 1;
            _trgrt12I = 1;
        }
    }
     else 
    {
        _trgrt12 = 0;
        _trgrt12I = 0;
    }
    ;
    in_182541836_3 = ((_trgrt12) || (!(_bounseInputD39O)));
    rst_182541836_3 = !(_bounseInputD31O);
    if((in_182541836_3)&&(!tmp_182541836_3)) 
    {
        out_182541836_3=!out_182541836_3;
    }
    if(rst_182541836_3) 
    {
        out_182541836_3=0;
    }
    tmp_182541836_3=in_182541836_3;
    if(out_182541836_3)
    {
        _swi1=1;
    }
    else
    {
        _swi1=0;
    }
    if((_swi1 == 0))
    {
        _dms1Q0 = 1;
    }
    else 
    {
        _dms1Q0 = 0;
    }
    if((_swi1 == 1))
    {
        _dms1Q1 = 1;
    }
    else 
    {
        _dms1Q1 = 0;
    }
    _gtv20 = _dms1Q1;
    _gtv21 = _dms1Q0;
    //Плата:16
//Наименование:Каретка Х намотка
//Комментарии:Каретка Х намотка -пермещение каретки во время намотки.
    if (_gtv14 == 1) 
    {
        _gtv15 = (_menuValueArray_int[1]);
        bool  _tmp1 = _gtv16;
        if (_tmp1)  
        {
             if (! _trgt1I) _trgt1 = ! _trgt1;
        }
        _trgt1I = _tmp1;
        _gtv22 = !(_trgt1);
        _gtv25 =  (digitalRead (14));
        if ((_gtv23) == (_gtv15)) 
        {
            _gtv1 = 1;
        }
    }
    //Плата:17
//Наименование:Y мотор намотка
//Комментарии:Y мотор намотка
    if (_gtv3) 
    {
         if (_trgrt21I) 
        {
             _trgrt21 = 0;
        }
         else 
        {
            _trgrt21 = 1;
            _trgrt21I = 1;
        }
    }
     else 
    {
        _trgrt21 = 0;
        _trgrt21I = 0;
    }
    ;
    digitalWrite(56, !(((_gtv3) || (((_gtv14) && (!(0)))))));
    if (_gtv14) 
    {
         if (_trgrt13I) 
        {
             _trgrt13 = 0;
        }
         else 
        {
            _trgrt13 = 1;
            _trgrt13I = 1;
        }
    }
     else 
    {
        _trgrt13 = 0;
        _trgrt13I = 0;
    }
    ;
    if (_gtv21) 
    {
         if (_trgrt10I) 
        {
             _trgrt10 = 0;
        }
         else 
        {
            _trgrt10 = 1;
            _trgrt10I = 1;
        }
    }
     else 
    {
        _trgrt10 = 0;
        _trgrt10I = 0;
    }
    ;
    if (_gtv16) 
    {
         if (_trgrt6I) 
        {
             _trgrt6 = 0;
        }
         else 
        {
            _trgrt6 = 1;
            _trgrt6I = 1;
        }
    }
     else 
    {
        _trgrt6 = 0;
        _trgrt6I = 0;
    }
    ;
    if (_gtv18) 
    {
         if (_trgrt7I) 
        {
             _trgrt7 = 0;
        }
         else 
        {
            _trgrt7 = 1;
            _trgrt7I = 1;
        }
    }
     else 
    {
        _trgrt7 = 0;
        _trgrt7I = 0;
    }
    ;
    if (_gtv5) 
    {
         if (_trgrt20I) 
        {
             _trgrt20 = 0;
        }
         else 
        {
            _trgrt20 = 1;
            _trgrt20I = 1;
        }
    }
     else 
    {
        _trgrt20 = 0;
        _trgrt20I = 0;
    }
    ;
    if (_gtv20) 
    {
         if (_trgrt29I) 
        {
             _trgrt29 = 0;
        }
         else 
        {
            _trgrt29 = 1;
            _trgrt29I = 1;
        }
    }
     else 
    {
        _trgrt29 = 0;
        _trgrt29I = 0;
    }
    ;
    // Отслеживаем изменение направления вращения
    if (curCCW56724086 != (0)) 
    {
        curCCW56724086 = (0);
        stepper56724086.reverse((0));
    }
    // Отслеживаем изменение Ускорение
    if (curAcceleration56724086 != (_gtv10)) 
    {
        curAcceleration56724086 = (_gtv10);
        stepper56724086.setAcceleration((_gtv10));
    }
    //Отслеживаем изменение скорости постоянного вращения
    if (curEndlessSpeed56724086 != (_gtv6)) 
    {
        curEndlessSpeed56724086 = (_gtv6);
        stepper56724086.setSpeed(curEndlessSpeed56724086);
    }
//Запуск постоянного вращения
    if ((((_trgrt21) || (_trgrt13) || (_trgrt10)))) 
    {
        stepper56724086.setRunMode(KEEP_SPEED);
        stepper56724086.setSpeed(curEndlessSpeed56724086);
    }
    //Резкая остановка ШД
    if ((((_trgrt6) || (_trgrt7) || (_trgrt20) || (_trgrt29)))) 
    {
         stepper56724086.brake();
    }
    //Плата:18
//Наименование:X мотор каретка
//Комментарии:X мотор каретка
    digitalWrite(38, 0);
    if (_gtv19) 
    {
         if (_trgrt3I) 
        {
             _trgrt3 = 0;
        }
         else 
        {
            _trgrt3 = 1;
            _trgrt3I = 1;
        }
    }
     else 
    {
        _trgrt3 = 0;
        _trgrt3I = 0;
    }
    ;
    if (_gtv1) 
    {
         if (_trgrt16I) 
        {
             _trgrt16 = 0;
        }
         else 
        {
            _trgrt16 = 1;
            _trgrt16I = 1;
        }
    }
     else 
    {
        _trgrt16 = 0;
        _trgrt16I = 0;
    }
    ;
    if (_gtv2) 
    {
         if (_trgrt4I) 
        {
             _trgrt4 = 0;
        }
         else 
        {
            _trgrt4 = 1;
            _trgrt4I = 1;
        }
    }
     else 
    {
        _trgrt4 = 0;
        _trgrt4I = 0;
    }
    ;
    if (_trgrt4) 
    {
        _gtv2 = 0;
    }
    digitalWrite(13, _gtv25);
    if (_gtv25) 
    {
         if (_trgrt31I) 
        {
             _trgrt31 = 0;
        }
         else 
        {
            _trgrt31 = 1;
            _trgrt31I = 1;
        }
    }
     else 
    {
        _trgrt31 = 0;
        _trgrt31I = 0;
    }
    ;
    // Отслеживаем изменение направления вращения
    if (curCCW69894407 != (_gtv22)) 
    {
        curCCW69894407 = (_gtv22);
        stepper69894407.reverse((_gtv22));
    }
    // Отслеживаем изменение Максимальная скорость
    if (curMaxSpeed69894407 != (2000.00)) 
    {
        curMaxSpeed69894407 = (2000.00);
        stepper69894407.setMaxSpeed((2000.00));
    }
    // Отслеживаем изменение Ускорение
    if (curAcceleration69894407 != (1900.00)) 
    {
        curAcceleration69894407 = (1900.00);
        stepper69894407.setAcceleration((1900.00));
    }
    //Резкая остановка ШД
    if ((0)) 
    {
         stepper69894407.brake();
    }
    //Резкая остановка и сброс координат в 0
    if ((((_trgrt3) || (_trgrt16)))) 
    {
         stepper69894407.reset();
    }
    //Запуск шагов ШД
    if ((((_trgrt4) || (_trgrt31)))) 
    {
        stepper69894407.setRunMode(FOLLOW_POS);
        stepper69894407.setTarget((_gtv15), RELATIVE);
    }
    //Вывод текущей позиции ШД
      static uint32_t tmr269894407;
    if (millis() - tmr269894407 > 20) 
    {
        tmr269894407 = millis();
        Out_123216258_69894407 = stepper69894407.getCurrent();
    }
    if (0) 
    {
        _dispTempLength1 = ((((String("S:")) + ((String(Out_123216258_69894407, DEC)))))).length();
        if (_disp3oldLength > _dispTempLength1) 
        {
            _isNeedClearDisp1 = 1;
        }
        _disp3oldLength = _dispTempLength1;
        _lcd1.setCursor(11, 3);
        _lcd1.print((((String("S:")) + ((String(Out_123216258_69894407, DEC))))));
    }
     else 
    {
        if (_disp3oldLength > 0) 
        {
            _isNeedClearDisp1 = 1;
            _disp3oldLength = 0;
        }
    }
    _gtv23 = Out_123216258_69894407;
    if (((_trgrt3) || (_trgrt16))) 
    {
        _gtv1 = 0;
    }
    if (((_trgrt3) || (_trgrt16))) 
    {
        _gtv19 = 0;
    }
    //Плата:19
//Наименование:Дисплей
//Комментарии:Дисплей
    if (((_gtv13) && (!(_gtv8)))) 
    {
        _dispTempLength1 = ((((String("\xE0\xB8\x61\xBC\x65\xBF\x70: ")) + ((_floatToStringWitRaz((_menuValueArray_float[0]),2)))))).length();
        if (_disp11oldLength > _dispTempLength1) 
        {
            _isNeedClearDisp1 = 1;
        }
        _disp11oldLength = _dispTempLength1;
        _lcd1.setCursor(0, 1);
        _lcd1.print((((String("\xE0\xB8\x61\xBC\x65\xBF\x70: ")) + ((_floatToStringWitRaz((_menuValueArray_float[0]),2))))));
    }
     else 
    {
        if (_disp11oldLength > 0) 
        {
            _isNeedClearDisp1 = 1;
            _disp11oldLength = 0;
        }
    }
    if (((_gtv13) && (!(_gtv8)))) 
    {
        _dispTempLength1 = ((((String("\x42\xB8\xBF\xBA\x6F\xB3:  ")) + ((String((_menuValueArray_byte[0]), DEC)))))).length();
        if (_disp10oldLength > _dispTempLength1) 
        {
            _isNeedClearDisp1 = 1;
        }
        _disp10oldLength = _dispTempLength1;
        _lcd1.setCursor(0, 0);
        _lcd1.print((((String("\x42\xB8\xBF\xBA\x6F\xB3:  ")) + ((String((_menuValueArray_byte[0]), DEC))))));
    }
     else 
    {
        if (_disp10oldLength > 0) 
        {
            _isNeedClearDisp1 = 1;
            _disp10oldLength = 0;
        }
    }
    if (((((_gtv26) || (_gtv30) || (_gtv3))) && (!(_gtv13)))) 
    {
        _dispTempLength1 = ((String("\x42\x6F\xB7\xB3\x70\x61\xBF"))).length();
        if (_disp12oldLength > _dispTempLength1) 
        {
            _isNeedClearDisp1 = 1;
        }
        _disp12oldLength = _dispTempLength1;
        _lcd1.setCursor(0, 2);
        _lcd1.print((String("\x42\x6F\xB7\xB3\x70\x61\xBF")));
    }
     else 
    {
        if (_disp12oldLength > 0) 
        {
            _isNeedClearDisp1 = 1;
            _disp12oldLength = 0;
        }
    }
    if (0) 
    {
        _dispTempLength1 = ((String("4"))).length();
        if (_disp6oldLength > _dispTempLength1) 
        {
            _isNeedClearDisp1 = 1;
        }
        _disp6oldLength = _dispTempLength1;
        _lcd1.setCursor(0, 3);
        _lcd1.print((String("4")));
    }
     else 
    {
        if (_disp6oldLength > 0) 
        {
            _isNeedClearDisp1 = 1;
            _disp6oldLength = 0;
        }
    }
    //Плата:20
//Наименование:Проходит цыкл
}
String  _floatToStringWitRaz(float value, int raz)
{
    return String(value,raz);
}
bool _isTimer(unsigned long startTime, unsigned long period)
{
    unsigned long currentTime;
    currentTime = millis();
    if (currentTime>= startTime) 
    {
        return (currentTime>=(startTime + period));
    }
     else 
    {
        return (currentTime >=(4294967295-startTime+period));
    }
}
String _readStringFromProgmem (char *string)
{
    String result = String("");
    while (pgm_read_byte(string)!='\0')
    {
        result=result+ char(pgm_read_byte(string));
        	string++;
        	
    }
    return result;
}
void _menuUpEvents (int menuIndex)
{
    int tempIndex = pgm_read_byte(&_menuParametrsArray[((_MainMenus[menuIndex]).currentItem).startInArrayIndex]);
    int parIndex = pgm_read_byte(&_menuParametrsArray[ (((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+5]);
    int parentStartIndex;
    int parentStopIndex;
    if (parIndex == 0) 
    {
        parentStartIndex = (_MainMenus[menuIndex]).startIndex;
        parentStopIndex =(_MainMenus[menuIndex]).stopIndex;
    }
    else 
    {
        parentStartIndex = pgm_read_byte(&_menuParametrsArray[((_MenuItems[parIndex - 1]).startInArrayIndex)+3]);
        parentStopIndex = pgm_read_byte(&_menuParametrsArray[((_MenuItems[parIndex-1]).startInArrayIndex)+4]);
    }
    if (tempIndex == parentStartIndex) 
    {
        if((_MainMenus[menuIndex]).isSwitchMenuAroundRing) 
        {
            (_MainMenus[menuIndex]).currentItem = _MenuItems[parentStopIndex -1];
            return;
        }
         else
        {
            return;
        }
    }
    (_MainMenus[menuIndex]).currentItem = _MenuItems[tempIndex - 2];
    return;
}
void _menuDownEvents (int menuIndex)
{
    int tempIndex = pgm_read_byte(&_menuParametrsArray[((_MainMenus[menuIndex]).currentItem).startInArrayIndex]);
    int parIndex = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+5]);
    int parentStartIndex;
    int parentStopIndex;
    if (parIndex == 0) 
    {
        parentStartIndex = (_MainMenus[menuIndex]).startIndex;
        parentStopIndex =(_MainMenus[menuIndex]).stopIndex;
    }
    else 
    {
        parentStartIndex = pgm_read_byte(&_menuParametrsArray[((_MenuItems[parIndex-1]).startInArrayIndex)+3]);
        parentStopIndex = pgm_read_byte(&_menuParametrsArray[((_MenuItems[parIndex-1]).startInArrayIndex)+4]);
    }
    if (tempIndex == parentStopIndex) 
    {
        if((_MainMenus[menuIndex]).isSwitchMenuAroundRing) 
        {
            (_MainMenus[menuIndex]).currentItem = _MenuItems[parentStartIndex -1];
            return;
        }
         else
        {
            return;
        }
    }
    (_MainMenus[menuIndex]).currentItem = _MenuItems[tempIndex];
    return;
}
void _valueUpEvents (int menuIndex)
{
    int valIndex = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+2]);
    int itemType = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+1]);
    int indexMax = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+6]);
    int indexStep = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+8]);
    if (itemType == 2) 
    {
        if (! indexMax == 0) 
        {
             if (! (byte(pgm_read_byte(&_menuConstantValuesArray_byte[indexMax -1])) > byte(_menuValueArray_byte[valIndex -1]))) 
            {
                return;
            }
        }
        _menuValueArray_byte[valIndex -1] = _menuValueArray_byte[valIndex -1] + (pgm_read_byte(&_menuConstantValuesArray_byte[indexStep -1]));
    }
    if (itemType == 4) 
    {
        if (! indexMax == 0) 
        {
             if (! (int(pgm_read_word(&_menuConstantValuesArray_int[indexMax -1])) > int(_menuValueArray_int[valIndex -1]))) 
            {
                return;
            }
        }
        _menuValueArray_int[valIndex -1] = _menuValueArray_int[valIndex -1] + (pgm_read_word(&_menuConstantValuesArray_int[indexStep -1]));
    }
    if (itemType == 8) 
    {
        if (! indexMax == 0) 
        {
             if (! (float(pgm_read_float(&_menuConstantValuesArray_float[indexMax -1])) > float(_menuValueArray_float[valIndex -1]))) 
            {
                return;
            }
        }
        _menuValueArray_float[valIndex -1] = _menuValueArray_float[valIndex -1] + (pgm_read_float(&_menuConstantValuesArray_float[indexStep -1]));
    }
}
void _valueDownEvents (int menuIndex)
{
    int valIndex = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+2]);
    int itemType = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+1]);
    int indexMin = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+7]);
    int indexStep = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+8]);
    if (itemType == 2) 
    {
        if (! indexMin == 0) 
        {
             if (! ((byte(pgm_read_byte(&_menuConstantValuesArray_byte[indexMin - 1]))) < byte(_menuValueArray_byte[valIndex - 1]))) 
            {
                return;
            }
        }
        _menuValueArray_byte[valIndex - 1] = _menuValueArray_byte[valIndex - 1] - (pgm_read_byte(&_menuConstantValuesArray_byte[indexStep - 1]));
    }
    if (itemType == 4) 
    {
        if (! indexMin == 0) 
        {
             if (! ((int(pgm_read_word(&_menuConstantValuesArray_int[indexMin - 1]))) < int(_menuValueArray_int[valIndex - 1]))) 
            {
                return;
            }
        }
        _menuValueArray_int[valIndex - 1] = _menuValueArray_int[valIndex - 1] - (pgm_read_word(&_menuConstantValuesArray_int[indexStep - 1]));
    }
    if (itemType == 8) 
    {
        if (! indexMin == 0) 
        {
             if (! ((float(pgm_read_float(&_menuConstantValuesArray_float[indexMin - 1]))) < float(_menuValueArray_float[valIndex - 1]))) 
            {
                return;
            }
        }
        _menuValueArray_float[valIndex - 1] = _menuValueArray_float[valIndex - 1] - (pgm_read_float(&_menuConstantValuesArray_float[indexStep - 1]));
    }
}
String _menuOutputValueString (int menuIndex)
{
    int itemType = pgm_read_byte(&_menuParametrsArray[ (((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+1]);
    int valIndex = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+2]);
    int indexMin = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+7]);
    int indexMax = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+6]);
    if(valIndex == 0)
    {
         return "";
    }
    int convFormat = pgm_read_byte(&_menuParametrsArray[(((_MainMenus[menuIndex]).currentItem).startInArrayIndex)+9]);
    if(itemType == 2) 
    {
         return _convertNamber(itemType, convFormat, valIndex, indexMax, indexMin);
    }
    if(itemType == 4) 
    {
         return _convertNamber(itemType, convFormat, valIndex, indexMax, indexMin);
    }
    if(itemType == 8) 
    {
         return _convertFloat(itemType, convFormat, valIndex, indexMax, indexMin);
    }
    return "";
}
void _menuUpdateToEEpromItems()
{
    (updateFloatToEEPROM(1, 0, 0x0, ((_menuValueArray_float[0]))));
    (updateByteToEEPROM(5, 0, 0x0, ((_menuValueArray_byte[0]))));
    (updateIntegerToEEPROM(6, 0, 0x0, ((_menuValueArray_int[0]))));
    (updateIntegerToEEPROM(8, 0, 0x0, ((_menuValueArray_int[1]))));
}
String _convertNamber(int itemType, int convFormat, int valIndex, int indexMax, int indexMin)
{
    if (itemType== 2) 
    {
        if (convFormat == 4) 
        {
             return String((_menuValueArray_byte[valIndex - 1 ]),DEC);
        }
        if (convFormat == 5) 
        {
             return String((_menuValueArray_byte[valIndex - 1]),HEX);
        }
        if (convFormat == 6) 
        {
             return String((_menuValueArray_byte[valIndex -1]),BIN);
        }
    }
    if (itemType== 4) 
    {
        if (convFormat == 4) 
        {
             return String((_menuValueArray_int[valIndex - 1 ]),DEC);
        }
        if (convFormat == 5) 
        {
             return String((_menuValueArray_int[valIndex - 1]),HEX);
        }
        if (convFormat == 6) 
        {
             return String((_menuValueArray_int[valIndex -1]),BIN);
        }
    }
    if (itemType== 8) 
    {
        if (convFormat == 4) 
        {
             return String((_menuValueArray_float[valIndex - 1 ]),DEC);
        }
        if (convFormat == 5) 
        {
             return String((_menuValueArray_float[valIndex - 1]),HEX);
        }
        if (convFormat == 6) 
        {
             return String((_menuValueArray_float[valIndex -1]),BIN);
        }
    }
}
String _convertFloat(int itemType, int convFormat, int valIndex , int indexMax, int indexMin)
{
    return String((_menuValueArray_float[valIndex -1]),convFormat);
}
byte readByteFromEEPROM(int addres, byte bitAddres, byte chipAddres)
{
    return EEPROM.read(addres);
}
void updateByteToEEPROM(int addres, byte bitAddres, byte chipAddres, byte value)
{
    return EEPROM.update(addres, value);
}
int readIntegerFromEEPROM(int addres, byte bitAddres, byte chipAddres)
{
    byte hight = readByteFromEEPROM(addres,  bitAddres,  chipAddres);
    byte low = readByteFromEEPROM((addres+1),  bitAddres,  chipAddres);
    return  word(hight, low);
}
void updateIntegerToEEPROM(int addres, byte bitAddres, byte chipAddres, int value)
{
    updateByteToEEPROM(addres,  bitAddres,  chipAddres, highByte(value));
    updateByteToEEPROM((addres+1),  bitAddres,  chipAddres, lowByte(value));
}
float readFloatFromEEPROM(int addres, byte bitAddres, byte chipAddres)
{
    byte x[4];
    for(byte i = 0; i < 4; i++) 
    {
         x[i] = readByteFromEEPROM((addres+i),  bitAddres,  chipAddres);
    }
    float *y = (float *)&x;
    return y[0];
}
void updateFloatToEEPROM(int addres, byte bitAddres, byte chipAddres, float value)
{
    byte *x = (byte *)&value;
    for(byte i = 0; i < 4; i++) 
    {
        updateByteToEEPROM((addres+i),  bitAddres,  chipAddres, x[i]);
    }
}

/*
// обработчик
ISR(TIMER1_A) 
{
// обработчик
    ISR(TIMER3_A) 
    {
        Ready56724086 = !stepper56724086.tick();
        Ready69894407 = !stepper69894407.tick();
    }
}
*/

// обработчик
ISR(TIMER1_A) 
{
    Ready56724086 = !stepper56724086.tick();
}

// обработчик
ISR(TIMER3_A) 
{
    Ready69894407 = !stepper69894407.tick();
}
