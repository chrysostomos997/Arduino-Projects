# RFID DATA LOGGER FOR GREEK ARMY PATROL 

This project was made during my mandatory 12 month service in Greek army. 

The purpose of this project was to develop a data logger to help the Greek army save time during patrols. 
The data logger was built using an Arduino Uno microcontroller, an RFID reader, an SD card module, an RTC module ,a passive buzzer and an reset button. 
The system records the time and location of each patrol using the RFID reader and stores the data on the SD card.
The RTC module ensures that the time stamps are accurate. The data can be easily accessed and analyzed after the patrol is completed, which can help with mission planning and analysis. 
This project provides an efficient and cost-effective solution for the Greek army to streamline their patrol operations.

**Here some Photos of the Data logger:**


<table>
  <tr>
    <td>
      <figure>
        <img src="https://github.com/chrysostomos997/Arduino-Projects/blob/3e837ae898260a457f43b8fa9ae2d71168ee8ef2/RFID%20DATA%20LOGGER%20FOR%20GREEK%20ARMY%20PATROL/PHOTOS/DATA%20LOGGER.jpg" />
        <figcaption></figcaption>
      </figure>
    </td>
    <td>
      <figure>
        <img src="https://github.com/chrysostomos997/Arduino-Projects/blob/3e837ae898260a457f43b8fa9ae2d71168ee8ef2/RFID%20DATA%20LOGGER%20FOR%20GREEK%20ARMY%20PATROL/PHOTOS/DATA%20LOGGER1%20.jpg" />
        <figcaption></figcaption>
      </figure>
    </td>
  </tr>
</table>



<h1>OPERATION</h1>

<table>
  <tr>
    <td>
      <figure>
        <img src="https://github.com/chrysostomos997/Arduino-Projects/blob/87a27933851ceeac2d464b676317bcfaeed742f1/RFID%20DATA%20LOGGER%20FOR%20GREEK%20ARMY%20PATROL/PHOTOS/Operation.gif" />
        <figcaption></figcaption>
      </figure>
    </td>
    <td>
      <figure>
        <img src="https://github.com/chrysostomos997/Arduino-Projects/blob/d4828a4276a2e2ff3886e6c5231d81a49929b3ec/RFID%20DATA%20LOGGER%20FOR%20GREEK%20ARMY%20PATROL/PHOTOS/SD%20CARD%20ERROR.gif" />
        <figcaption></figcaption>
      </figure>
    </td>
  </tr>
</table>




<h1>SHEMATIC OF DATA LOGGER</h1>

![Image description](https://github.com/chrysostomos997/Arduino-Projects/blob/6cae8a543df1a9808042c0eb21c0a6e54174da21/RFID%20DATA%20LOGGER%20FOR%20GREEK%20ARMY%20PATROL/PHOTOS/SHEMATIC.jpg)




<h1>DATA STORAGE</h1>

<p align="center">
  <img src="https://github.com/chrysostomos997/Arduino-Projects/blob/a03a9fb377990ad98a128aa16d1a5385d0196c0b/RFID%20DATA%20LOGGER%20FOR%20GREEK%20ARMY%20PATROL/PHOTOS/SD%20CARD.jpg" alt="your-image-description" width="400" />
</p>


Inside the SD card, there are two items: data (tags) and an Excel file that contains the data. "Peripolo" refers to patrol activities, while "EFODOS" refers to patrols conducted by Army officers. At the end of each day, the commanding officer signs the Excel file to certify the accuracy of the data.

<table>
  <tr>
    <td>
      <figure>
        <img src="https://github.com/chrysostomos997/Arduino-Projects/blob/a03a9fb377990ad98a128aa16d1a5385d0196c0b/RFID%20DATA%20LOGGER%20FOR%20GREEK%20ARMY%20PATROL/PHOTOS/data.jpg" />
        <figcaption></figcaption>
      </figure>
    </td>
    <td>
      <figure>
        <img src="https://github.com/chrysostomos997/Arduino-Projects/blob/a03a9fb377990ad98a128aa16d1a5385d0196c0b/RFID%20DATA%20LOGGER%20FOR%20GREEK%20ARMY%20PATROL/PHOTOS/Excel.jpg" />
        <figcaption></figcaption>
      </figure>
    </td>
  </tr>
</table>


<h1>PROBLEMS</h1>

One of the problems I encountered was that the time recorded in the SD card was incorrect whenever a tag was triggered. This issue was caused by RF interference.

RF interference is a common problem in electronic circuits, particularly in high-frequency applications such as wireless communication systems. It occurs when electromagnetic waves at radio frequencies interfere with the operation of electronic devices, causing noise, distortion, signal loss, or complete failure of the electronic device or circuit.

One effective way to minimize the impact of RF interference is to physically separate circuits that are particularly sensitive to interference. This can be achieved by increasing the distance between the circuits or using shielding or other barriers to block the interference. In the photo provided, it appears that the two circuits have been separated from each other, likely resulting in reduced interference and improved performance.


![Image description](https://github.com/chrysostomos997/Arduino-Projects/blob/ed1d791cb0caa58363329ed65e6555f3b4d3f6e1/RFID%20DATA%20LOGGER%20FOR%20GREEK%20ARMY%20PATROL/PHOTOS/STOP%20RF%20INTERFERENCE.jpg)


