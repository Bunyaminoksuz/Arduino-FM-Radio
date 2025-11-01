# Arduino-FM-Radio
Making FM Radio using PAM8403, TEA5767, ENCODER and ARDUINO TR
In this project, frequency control is provided via the TEA5767 FM radio module using Arduino, and these frequencies are increased or decreased with user inputs by means of a rotary encoder. The system also displays the signal level on the serial monitor.

### ENCODER Connections

| Encoder Pin | Arduino Pin | Description |
| :--- | :--- | :--- |
| CLK (A) | D2 | Encoder Clock pin |
| DT (B) | D3 | Encoder Data pin |
| SW | D4 (optional) | Encoder button (not used) |
| VCC | 5V | Power input |
| GND | GND | Ground connection |

### TEA5767 FM Module (I2C) Connections

| TEA5767 Pin | Arduino Pin | Description |
| :--- | :--- | :--- |
| SDA | A4 | I2C data line |
| SCL | A5 | I2C clock line |
| VCC | 3.3V / 5V | Power connection (depending on module type) |
| GND | GND | Ground connection |

### Hardware Used and Their Roles

| Component | Function |
| :--- | :--- |
| Arduino Uno | Controls the entire system, performs data read/write operations. |
| TEA5767 FM Module | Used to receive and play FM radio signals. |
| Rotary Encoder | Allows the user to increase and decrease the frequency. |
| Encoder Button | (Not used in the code, but can be added later) |
| LCD Display | Used to display frequency and signal information. |

### Libraries Used

| Library | Purpose |
| :--- | :--- |
| Wire.h | To provide I2C communication |
| TEA5767.h | To control the TEA5767 module |
| Encoder.h | To get input from the rotary encoder |
