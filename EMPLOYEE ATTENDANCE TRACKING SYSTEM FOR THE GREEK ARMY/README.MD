# EMPLOYEE ATTENDACE TRACKING SYSTEM FOR THE GREEK ARMY 

This project was made during my mandatory 12 month service in Greek army.

This project aims to develop an efficient employee attendance tracking system for the Greek Army, utilizing Arduino Uno, RFID reader, RTC module, and SD card module. The system is designed to accurately monitor and record the arrival times of 70 officers equipped with RFID cards. By leveraging these hardware components, the project enables seamless data collection, storage, promoting effective workforce management within the Greek Army.

The code includes the required libraries and defines the necessary pins for the RFID module, LEDs, buzzer, RTC, and SD card module. In the setup function, it initializes the necessary components, sets the current date and time for the RTC, and performs SD card initialization. The loop function continuously checks for the presence of an RFID card.

If a new card is detected, the code reads the card's unique identifier (UID) and searches for a match in the "uids.txt" file stored on the SD card. If a match is found, it retrieves the corresponding name from the "names.txt" file and saves it in the "data.txt" file. The current date and time from the RTC are also appended to the "data.txt" file.

<h1>SD CARD</h1>

<p align="center">
  <img src="https://github.com/chrysostomos997/Arduino-Projects/blob/497716ed01c1e46fc865472d70539c5d09d5177c/EMPLOYEE%20ATTENDANCE%20TRACKING%20SYSTEM%20FOR%20THE%20GREEK%20ARMY/MICRO%20SD%20CARD.jpg" alt="your-image-description" width="400" />
</p>


<table>
  <tr>
    <td>
      <figure>
        <img src="https://github.com/chrysostomos997/Arduino-Projects/blob/5343e720b6d65f184505c504fae7895be96f2f0a/EMPLOYEE%20ATTENDANCE%20TRACKING%20SYSTEM%20FOR%20THE%20GREEK%20ARMY/uids.jpg" />
        <figcaption></figcaption>
      </figure>
    </td>
    <td>
      <figure>
        <img src="https://github.com/chrysostomos997/Arduino-Projects/blob/5343e720b6d65f184505c504fae7895be96f2f0a/EMPLOYEE%20ATTENDANCE%20TRACKING%20SYSTEM%20FOR%20THE%20GREEK%20ARMY/names.jpg" />
        <figcaption></figcaption>
      </figure>
    </td>
  </tr>
</table>






Overall, this code allows for logging the RFID card UID, associated name, and the timestamp of each card swipe onto the SD card.

Please note that the code snippet provided might require additional setup or modifications to work correctly in your specific Arduino environment.

In conclusion, this project presents an effective solution for monitoring and recording officer arrival times within the Greek Army, utilizing Arduino Uno, RFID reader, RTC module, and SD card module. By leveraging these technologies, the Greek Army can streamline their attendance tracking processes, foster punctuality among officers, and optimize workforce management strategies to ensure operational excellence.
 -->

