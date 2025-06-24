#include <Keyboard.h>
/*
Tested on chromeOS v137
*/

#define SSID_NAME ""
#define NETWORK_PASSWORD ""
#define USERNAME ""
#define PASSWORD ""

#define RXLED 17

void light_led()
{
    pinMode(RXLED, OUTPUT);
    digitalWrite(RXLED, LOW);
}

void write_space()
{
    Keyboard.write(' ');
}

void write_tab()
{
    Keyboard.write('\t');
}

void write_down()
{
    Keyboard.write(KEY_DOWN_ARROW);
}

void write_enter()
{
    Keyboard.write(KEY_RETURN);
}

void setup()
{

    light_led();
    delay(4000);
    Keyboard.begin();

    write_space();
    delay(3000);

    write_tab();
    delay(500);
    write_tab();
    delay(500);
    write_tab();            
    delay(500);

    write_space();
    delay(1000);

    write_tab();
    delay(1000);

    write_space();
    delay(1000);

    write_tab();
    delay(200);
    write_tab();
    delay(200);
    write_tab();
    delay(200);

    write_space();
    delay(400);
    write_space();
    delay(400);
    
    write_tab();
    delay(1000);

    write_space();
    delay(2000);

    // Type in SSID name
    Keyboard.print(SSID_NAME);
    delay(200);

    write_tab();
    delay(500);

    write_space();
    delay(500);

    write_down();
    delay(200);
    write_down();
    delay(200);

    write_enter();
    delay(500);

    write_tab();
    delay(200);

    // Write network password
    Keyboard.print(NETWORK_PASSWORD);
    delay(200);

    // Connect to network
    write_enter();

    // Wait processing
    delay(10000);
                          
    write_tab();
    delay(200);
    write_tab();
    delay(200);
    write_tab();
    delay(200);

    write_space();
    delay(15000);

    /* ENROLL BLOCK */
    write_tab();
    delay(200);
    write_tab();
    delay(200);
    write_enter();
    delay(5000);

    // have to tab 8 times before we can type in device enrollment
    for (int i = 0; i < 8; i++) {
        write_tab();
        delay(100);
    }

    // Type in username
    Keyboard.print(USERNAME);
    delay(50);
    write_enter();
    delay(10000);

    // Type in password
    Keyboard.print(PASSWORD);
    delay(50);
    write_enter();

    /* END ENROLL BLOCK */


    // wait for enrollment to finish
    delay(80000);


    // Prepare to log in
    write_space();
    delay(40000);

    // LOGIN

    // Type in username
    Keyboard.print(USERNAME);
    delay(50);
    write_enter();
    delay(15000);

    // Type in password
    Keyboard.print(PASSWORD);
    delay(50);
    write_enter();

    delay(20000);

    // Sometimes there is a "control your data prompt". Split 40s delay into two groups so we can bypass this 
    write_space();
    delay(200);
    write_space();
    delay(200);

    delay(20000);

    // should be logged in

    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('t');
    delay(100);
    Keyboard.releaseAll();
    delay(4000); // Wait for tab to open

    // Skip ad privacy bs in Chrome Tab
    write_tab();
    delay(200);
    write_tab();
    delay(200);
    write_tab();
    delay(200);

    write_space();
    delay(400);


    // Open update screen
    Keyboard.print("chrome://os-settings/help");
    delay(50);
    write_enter();
    delay(4000);

    write_tab();
    delay(500);


    // start updates
    write_space();

    // should be updating. we're done
}

void loop()
{

}
