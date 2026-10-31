
#include <Servo.h>
#include <Adafruit_NeoPixel.h>

#define NEO_PIXEL_PIN     4  // The Arduino R3 digital pin connected to the NeoPixel DI (Data Input)
#define NUM_PIXELS      4  // neopixel strip size
#define SERVO_PWM_PIN   2
#define RED_LED_PIN     10
#define BLUE_LED_PIN    5
#define GREEN_LED_PIN   6
#define USONIC_NUMER_OF_PINS  4 // The number of pins on the ultrasonic distance sensor.

#if USONIC_NUMER_OF_PINS == 4
  #define USONIC_TRIGGER_PIN  7
  #define USONIC_ECHO_PIN   8
#elif USONIC_NUMER_OF_PINS == 3
  #define USONIC_TRIGGER_PIN  7
  #define USONIC_ECHO_PIN   7
#endif

Servo servo1;
// Pre-defined list of 4 distinct colors to pass to our function
// Syntax: strip.Color(Red, Green, Blue) -> values range from 0 to 255
uint32_t colors[4];

// Initialize the NeoPixel strip object
Adafruit_NeoPixel strip(NUM_PIXELS, NEO_PIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setFourPixels(uint32_t colorArray[]);
long getCmDistanceFromSensor(void);

void setup() {
  // Initialize serial communication at 57600 bits per second
  Serial.begin(57600);
  
  // Attach the function you want to call to the timer interrupt
  servo1.attach(SERVO_PWM_PIN);
  
  #if USONIC_NUMER_OF_PINS == 4
    pinMode(USONIC_TRIGGER_PIN, OUTPUT);
    pinMode(USONIC_ECHO_PIN, INPUT);
  #elif USONIC_NUMER_OF_PINS == 3
    pinMode(USONIC_ECHO_PIN, INPUT);
  #endif
  
  strip.begin();           // Initialize the NeoPixel data pin
  strip.setBrightness(150); // Set brightness to a reasonable level (0-255)
  strip.show();            // Initialize all pixels to 'off'

  // Define four distinct colors
  colors[0] = strip.Color(255, 0, 0);   // Pixel 0: Red
  colors[1] = strip.Color(0, 255, 0);   // Pixel 1: Green
  colors[2] = strip.Color(0, 0, 255);   // Pixel 2: Blue
  colors[3] = strip.Color(255, 255, 0); // Pixel 3: Yellow

  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(BLUE_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);

  Serial.print("Setup complete");
}

void loop() {
  // Establish variables for duration of the ping, and the distance result
  // in inches and centimeters:
  long distanceCm = getCmDistanceFromSensor();
  Serial.print(" distance (cm): ");
  Serial.println(distanceCm);

  // if the distance is in range, move the servo
  switch (distanceCm) {
    case 0 ... 50:
      servo1.write(10);
      digitalWrite(RED_LED_PIN, HIGH);
      digitalWrite(BLUE_LED_PIN, LOW);
      digitalWrite(GREEN_LED_PIN, LOW);
      colors[0] = strip.Color(255, 0, 0);   // Pixel 0: Red
      colors[1] = strip.Color(255, 255, 0); 
      colors[2] = strip.Color(255, 0, 255);
      colors[3] = strip.Color(255, 255, 0); 
      break;
    case 51 ... 100:
      servo1.write(45);
      digitalWrite(RED_LED_PIN, LOW);
      digitalWrite(BLUE_LED_PIN, HIGH);
      digitalWrite(GREEN_LED_PIN, LOW);
      colors[0] = strip.Color(255, 255, 0);   // Pixel 0: Red
      colors[1] = strip.Color(255, 255, 0); 
      colors[2] = strip.Color(255, 255, 255);
      colors[3] = strip.Color(255, 255, 0); 
    case 101 ... 2500:
      servo1.write(85);
      digitalWrite(RED_LED_PIN, LOW);
      digitalWrite(BLUE_LED_PIN, LOW);
      digitalWrite(GREEN_LED_PIN, HIGH);
      colors[0] = strip.Color(125, 120, 25);   // Pixel 0: Red
      colors[1] = strip.Color(255, 100, 10); 
      colors[2] = strip.Color(255, 57, 60);
      colors[3] = strip.Color(255, 85, 90); 
    default:
      Serial.println("Out of range.");
      break;
  }
  setFourPixels(colors);
  
  // Wait 100 milliseconds before the next reading
  delay(100);
}

/**
 * Sets each pixel in the 4-LED strip to a unique color simultaneously
 * @param colorArray An array containing exactly 4 uint32_t color codes
 */
void setFourPixels(uint32_t colorArray[]) {
  for (int i = 0; i < 4; i++) {
    // Assign the matching color from the array to each index (0, 1, 2, 3)
    strip.setPixelColor(i, colorArray[i]);
  }
  
  // Push the data out to the physical strip so they update at the exact same time
  strip.show(); 
}

long getCmDistanceFromSensor(void) {
  #if USONIC_NUMER_OF_PINS == 4
    digitalWrite(USONIC_TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(USONIC_TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(USONIC_TRIGGER_PIN, LOW);
  #elif USONIC_NUMER_OF_PINS == 3
    // 1. Send a short LOW pulse to ensure a clean HIGH pulse
    pinMode(USONIC_ECHO_PIN, OUTPUT);
    digitalWrite(USONIC_ECHO_PIN, LOW);
    delayMicroseconds(2);

    // 2. Trigger the sensor by sending a HIGH pulse for 5 to 10 microseconds
    digitalWrite(USONIC_ECHO_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(USONIC_ECHO_PIN, LOW);

    // 3. Switch the same pin to INPUT to read the returning pulse
    pinMode(USONIC_ECHO_PIN, INPUT);
 #endif 

    long duration = pulseIn(USONIC_ECHO_PIN, HIGH);
    long distanceCm = duration * 0.034 / 2;
    return distanceCm;
}

void timerInterupFunction() {
  
}
