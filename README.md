

<img width="1983" height="793" alt="image" src="https://github.com/user-attachments/assets/21226fef-1388-4fb1-8194-61569ccf21fc" />



# Carbsion
### by Dhairya


***Viewing Links--->***

***EASY EDA VIEW LINK (got from OSHW Lab) --->  
https://pro.easyeda.com/editor#id=53606adbf2524134a1bd79dfdb3195bb***



***OSHW Lab Project Homepage Link VIEW LINK ---> 
https://oshwlab.com/dhairyak/project_lsiedtbk***




***Note for reviwer ---> after submiting for review i realised that the USB C traces were not differential pairs so well while this was in review i changed them to be differential pairs (Pic at end)***

## About Carbsion

**Carbsion is a project i have been working on it is a custom built reader for scanning the freestyle libre 1 sensors to read the blood glucose readings.
The unique thing about this is that its not JUST a reader it is instead also integrated with a camera for AI food carbs scanning and also a customizable Insulin Calculator which uses user inputed insulin to carb ratio.**

## Inspiration 

**This project was inspired by a web app my dad built it allowed me to scan my food and get insulin calculated which ngl helped improve my HBA1C (used to check how well managed the diabetes is) significantly**


**Hence as school started and i cant take a phone to school i decided to make a reader X scanner device that is almost as big as the actuall Freestyle libre reader**


## Features 

- **Freestyle libre 1 sensor scanning and data reading** - This was the hardest part as the sensor isnt really made to be able to read using other devices however it can be done and ig i DID IT *(BTW ITS JUST FREESTYLE LIBRE 1 SINCE I USE 1 ONLY AND THE ENCRYPTION OF 2 AND 3 IS WAY STRONGER)*
- **Integrated Camera** - For AI food scanning
- **An ESP32 Wroom 32** - for actually sending the AI API requests and running the entire device
- **SENSOR DATA DECRYPTION** - This is a part of the first feature allowing the data from the sensor to actually be made *HUMAN readable* I got to know that the freeStyle libre 1 uses a simple XOR encryption that can be decrrypted simply using the decrypting code u can find in this repo


## Repo Structure 

**CAD AND PCB**
`src/` - source files for PCB and CAD

- `src/easyeda/` - EasyEDA source files


- `src/freeCAD/` - mechanical CAD sources


`production/` - **for fabrication outputs**


- `production/pcb/` - PCB fabrication files (Gerbers, BOM, Pick & Place)


- `production/cad/` - 3D printing files (top and bottom case)


`pics/` - images used in the README and documentation


**SOFTWARE**



`firmware/` - All the code files


- `firmware/carb_scan/` - The code for the AI carb scanner


- `firmware/carb_scan/C++` - parent folder for the C++ code


- `firmware/carb_scan/src` - main source .cpp files


- `firmware/carb_scan/include` - config.h and libre.h files




## Schematic
<img width="548" height="265" alt="Screenshot 2026-06-14 141442" src="https://github.com/user-attachments/assets/a78b906e-2a16-445e-a780-e45d5d2ba151" />
<img width="465" height="345" alt="Screenshot 2026-06-14 141429" src="https://github.com/user-attachments/assets/de16d55e-e8d8-45fb-ba95-94ac5ca546db" />
<img width="306" height="349" alt="Screenshot 2026-06-14 141416" src="https://github.com/user-attachments/assets/dee15d79-7191-4477-b853-aec0ce2aeb90" />
<img width="249" height="284" alt="Screenshot 2026-06-14 141403" src="https://github.com/user-attachments/assets/ad4fbc83-e5dd-4790-bd91-9f85816b2ead" />
<img width="476" height="343" alt="Screenshot 2026-06-14 141355" src="https://github.com/user-attachments/assets/5fade892-4339-4fb1-973f-8283ac2216a3" />




## PCB 
<img width="269" height="337" alt="Screenshot 2026-06-14 141643" src="https://github.com/user-attachments/assets/88db0df7-ef49-4ca0-9ced-ef729b915cbc" />
<img width="302" height="250" alt="Screenshot 2026-06-14 141908" src="https://github.com/user-attachments/assets/4d80661c-97b6-40b9-9dbf-422937f5f667" />
<img width="313" height="358" alt="Screenshot 2026-06-14 141852" src="https://github.com/user-attachments/assets/037b4ccc-818a-44d0-936f-6dc9ee5172a2" />
<img width="233" height="309" alt="Screenshot 2026-06-14 141830" src="https://github.com/user-attachments/assets/83b48f5b-7615-43aa-adf4-c0d033efc01a" />
<img width="472" height="328" alt="Screenshot 2026-06-14 141745" src="https://github.com/user-attachments/assets/3374b5d0-a9b5-4070-b365-e42ae237424f" />
<img width="565" height="309" alt="Screenshot 2026-06-14 141714" src="https://github.com/user-attachments/assets/f5992e0b-23fb-4219-a5fa-45557988c0ce" />
<img width="402" height="323" alt="Screenshot 2026-06-14 141703" src="https://github.com/user-attachments/assets/7923a9b2-376b-470f-919c-0902493c0b47" />





## CAD
<img width="1762" height="992" alt="Screenshot 2026-05-29 164434" src="https://github.com/user-attachments/assets/c2489ea5-795e-46bb-98ff-60e4165b13d3" />
<img width="1919" height="1079" alt="Screenshot 2026-05-29 164319" src="https://github.com/user-attachments/assets/529dc611-1e92-4ae5-ab7b-70720c46d506" />
<img width="1028" height="715" alt="Screenshot 2026-05-29 164305" src="https://github.com/user-attachments/assets/f4ab60ca-eb00-4f5f-bcaa-565c7b3f07cb" />
<img width="870" height="760" alt="Screenshot 2026-05-29 160254" src="https://github.com/user-attachments/assets/4a455665-f802-4d28-9974-7593a3a9e01d" />
<img width="857" height="775" alt="Screenshot 2026-05-29 164550" src="https://github.com/user-attachments/assets/631a6b1c-5927-42fc-a986-672ae1a08c07" />




## BOM- Bill Of Materials

<details>
<summary> Bill of Materials (BOM) **(btw this is a collapsible BOM this is my first readme that has a collapsable BOM its pretty cool)** </summary>
| # | Product / Cost | Seller | Qty | Unit Price (USD) | Total (USD) | Link |
|---:|---|---|---:|---:|---:|---|
| 1 | **2.8" SPI Touch Screen Module TFT Interface 240×320** | Robu.in | 1 | **$8.38** | **$8.38** | [Robu.in](https://robu.in/product/2-8-inch-spi-touch-screen-module-tft-interface-240320/?utm_source=chatgpt.com) |
| 2 | **PN5180 NFC RF Sensor Module, ISO15693 RFID, ICODE2** | Amazon.in | 1 | **$20.69** | **$20.69** | [Amazon.in](https://www.amazon.in/gp/product/B09G2KXPRL/ref=ox_sc_act_title_1?smid=AZU3LIF9T5UMI&psc=1) |
| 3 | **40-Pin 2.54mm Male + Female Berg Strip Connector — Pair of 5** | Amazon.in | 1 | **$1.04** | **$1.04** | [Amazon.in](https://www.amazon.in/gp/product/B0DNMD4THF/ref=ox_sc_act_title_2?smid=A366YFPXO3CTI5&psc=1) |
| 4 | **OV2640 200W Pixel Wide Angle Camera** | FlyRobo | 1 | **$9.44** | **$9.44** | [FlyRobo](https://www.flyrobo.in/ov2640-200w-pixel-wide-angle-camera?utm_source=chatgpt.com) |
| 5 | **ESP32-S3-WROOM-1-N16R8 Wi-Fi/BLE Module, 16MB Flash, PCB Antenna** | Evelta | 1 | **$3.41** | **$3.41** | [Evelta](https://evelta.com/esp32-s3-wroom-1-n16r8-wi-fi-ble-module-transceiver-16mb-flash-pcb-antenna/?utm_source=chatgpt.com) |
| 6 | **Carbsion gerbers_Y32 — PCB** | JLCPCB | 5 | **$1.40** | **$7.00** | [JLCPCB](https://jlcpcb.com/) |
| 7 | **Carbsion gerbers_Y32 — Economic PCBA, Bottom-Side SMT Assembly** | JLCPCB | 5 | **$10.38** | **$51.90** | [JLCPCB](https://jlcpcb.com/) |
| 8 | **JLCPCB Shipping** | JLCPCB | 1 | **$8.98** | **$8.98** | [JLCPCB](https://jlcpcb.com/) |
| 9 | **Tax** | — | 1 | **$33.94** | **$33.94** | — |
| | | | | **GRAND TOTAL** | **$144.78** | |

### Cost Breakdown

**$8.38 + $20.69 + $1.04 + $9.44 + $3.41 + $7.00 + $51.90 + $8.98 + $33.94 = $144.78 USD**
</details>


## License 
This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.



## Credits 

***I used the following for making this project***

- ***My Dad*** - For inspiring the AI carb scanning feature
- ***EasyEDA*** - For PCB design
- ***FreeCAD*** - For designing the Case
- ***JLCPCB*** - Will be using to manufacture the PCB
- **[APX HUB by @Gabouin](https://github.com/Gabouin/APX-USB-HUB)** - Readme template






### Differential Pair update Pic - 

<img width="650" height="427" alt="image" src="https://github.com/user-attachments/assets/16595d78-9198-4cd2-bbad-7260fa8856c8" />

