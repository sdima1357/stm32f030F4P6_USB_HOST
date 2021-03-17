
#ifndef USB_HOST_H
#define USB_HOST_H

/*******************************
*  Samsonov Dima Haifa@Israel  *
*  sdima1357@gmail.com         *
*  3/2021					   *
********************************/


//#define TIMER_DIVIDER         2  //  Hardware timer clock divider
//#define TIMER_SCALE           (TIMER_BASE_CLK / TIMER_DIVIDER)  // convert counter value to seconds
//#define TIMER_INTERVAL0_SEC   (0.001) // sample test interval for the first timer
//#define  TIME_MULT  25
//#define  TIME_SCALE (512)


// 84MHZ / 1.5 = 56 - ~22(overhead delay) = 34
//#define  TIME_DELAY (34)
#define  TIME_DELAY (10)

//1024/(84/4/1.5) = 71.14

#define  TIME_SCALE 1024
//#define  TIME_MULT  74
//"1024/(48/1.5)"
#define  TIME_MULT  32






// non configured device -  must be zero
#define  ZERO_USB_ADDRESS   0

// any number less 127, but no zero
#define  ASSIGNED_USB_ADDRESS    3



void printState();
void usb_process();
void led(int k);

#define  NUM_USB 2
void initStates(int _DP0,int _DM0,int _DP1,int _DM1);

typedef __packed struct
{
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t bcdUSB;
    uint8_t bDeviceClass;
    uint8_t bDeviceSubClass;
    uint8_t bDeviceProtocol;
    uint8_t bMaxPacketSize0;
    uint16_t idVendor;
    uint16_t idProduct;
    uint16_t bcdDevice;
    uint8_t iManufacturer;
    uint8_t iProduct;
    uint8_t iSerialNumber;
    uint8_t bNumConfigurations;
} sDevDesc;

typedef __packed struct
{
    uint8_t bLength;
	uint8_t bType;
	uint16_t wLength;
	uint8_t bNumIntf;
	uint8_t bCV;
	uint8_t bIndex;
	uint8_t bAttr;
	uint8_t bMaxPower;
} sCfgDesc;
typedef __packed struct
{
    uint8_t bLength;
	uint8_t bType;
	uint8_t iNum;
	uint8_t iAltString;
	uint8_t bEndPoints;
	uint8_t iClass;
	uint8_t iSub;
	uint8_t iProto;
	uint8_t iIndex;
} sIntfDesc;
typedef __packed struct
{
    uint8_t bLength;
	uint8_t bType;
	uint8_t bEPAdd;
	uint8_t bAttr;
	uint16_t wPayLoad;               /* low-speed this must be 0x08 */
	uint8_t bInterval;
} sEPDesc;

typedef __packed struct
{
  uint8_t   bLength;
  uint8_t   bDescriptorType;
  uint16_t  bcdHID;
  uint8_t   bCountryCode;
  uint8_t   bNumDescriptors;
  uint8_t   bReportDescriptorType;
  uint8_t   wItemLengthL;
  uint8_t   wItemLengthH;
} HIDDescriptor;

typedef __packed struct
{
    uint8_t bLength;
	uint8_t bType;
	uint16_t wLang;
} sStrDesc;



#endif
