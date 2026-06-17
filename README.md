

<img width="1584" height="672" alt="Carbsion Banner" src="https://github.com/user-attachments/assets/67661e50-5f1e-43cb-9ddb-9bfc348443cb" />


# Carbsion
### by Dhairya


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


- `production/cad/` - 3D printing files


`pics/` - images used in the README and documentation


`Electronic cad/` - 3d model of PCB from EasyEDA 


`3d Models with electronics/` - 3d model of the case with pcb

**SOFTWARE (will write all the software after finishing building the hardware part)**



`firmware/` - All the code files


- `firmware/carb_scan/` - The code for the AI carb scanner


- `firmware/carb_scan/Testing/` - The micro python code files to test first


- `firmware/carb_scan/C++/` - Main C++ code files to run the main software. ***Note- I have not made any files in this rn as i have to learn C++ and will make the files after testing with micropython***


- `firmware/scan/` - Code files for the scanning part


- `firmware/scan/main/` - Main basic files to scan and recieve data from the sensor (non decrypted data)


- `firmware/scan/decrypt/` - Decryption code for the encrypted data  



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

| No. | Quantity | Comment | Designator | Footprint | Value | Manufacturer Part | Manufacturer | Supplier Part | Supplier |
|------:|-----------:|:-------------------------------|:------------------------------|:---------------------------------------|:--------|:-------------------------------|:-------------------|:----------------|:-----------|
| 1 | 1 | AMS1117-3.3 | AMS1117-3.3 | SOT-223-3_L6.5-W3.4-P2.30-LS7.0-BR | | AMS1117-3.3 | YONGYUTAI(永裕泰) | C2891839 | LCSC |
| 2 | 6 | 100nF | C1,C2,C5,C6,C7,C9 | C0603 | 100nF | | | | |
| 3 | 2 | 10µF | C3,C4 | C0603 | 10µF | | | | |
| 4 | 1 | 10uF | C10 | C0603 | 10uF | | | | |
| 5 | 1 | CH340E | CH340E | MSOP-10_L3.0-W3.0-P0.50-LS5.0-BL | | CH340E | WCH(南京沁恒) | C99652 | LCSC |
| 6 | 1 | 2.54-2P WZDK-R Pitch Connector | CN1 | CONN-TH_2.54-2P-WZDK-R-PITCH-CONNECTOR | | 2.54-2P WZDK-R Pitch Connector | SHOU HAN(首韩) | C49023803 | LCSC |
| 7 | 2 | 1N4007 | D1,D2 | SMA_L4.4-W2.8-LS5.4-RD | | | | C727081 | |
| 8 | 1 | 2.4GHz | ESP32_S3_WROOM32_1 | WIFIM-SMD_ESP32-S3-WROOM-1-N8 | 2.4GHz | ESP32-S3-WROOM-1-N4 | ESPRESSIF(乐鑫) | C2913197 | LCSC |
| 9 | 1 | 0.5-24P翻盖 | FFC_CONN | FPC-SMD_24P-P0.50_C2835077 | | 0.5-24P翻盖 | BOOMELE(博穆精密) | C3010047 | LCSC |
| 10 | 1 | Conn_01_13 | PN5180_NFC | HDR-TH_13P-P2.54-V-M | | Conn_01_13 | HCTL(华灿天禄) | C2894936 | LCSC |
| 11 | 2 | 5.1K | R1,R2 | R0603 | 5.1K | | | | |
| 12 | 8 | 10K | R3,R7,R10,R11,R12,R13,R14,R15 | R0603 | 10K | | | | |
| 13 | 1 | 2K | R4 | R0603 | 2K | | | | |
| 14 | 2 | 1K | R5,R6 | R0603 | 1K | | | | |
| 15 | 2 | 22Ω | R8,R9 | R0603 | 22Ω | | | | |
| 16 | 6 | HC-QC6660-C-R | SW1,SW2,SW3,SW4,SW5,SW6 | SW-TH_4P-L6.0-W6.0-P4.50-LS6.5-1 | | HC-QC6660-C-R | HC(虹成电子) | C55014072 | LCSC |
| 17 | 1 | TFT DISPLAY PINS LEFT | TFTDISPLAYLEFT | CONN-TH_4P-P3.50_KF332J-3.5-4P | | TFT DISPLAY PINS LEFT | KEFA(科发) | C19711763 | LCSC |
| 18 | 1 | PZ254V-11-14P | TFTDISPLAYRIGHT | CONN-TH_PZ254V-11-14P | | PZ254V-11-14P | XFCN(兴飞) | C22465874 | LCSC |
| 19 | 1 | TP4056 | TP4056 | ESOP-8_L4.9-W3.9-P1.27-LS6.0-BL-EP3.1 | | TP4056 | GOODWORK(固得沃克) | C21713961 | LCSC |
| 20 | 1 | TYPE-C-16PIN | TPY-C-16-PIN | USB-C-SMD_TYPE-C16PIN-SHOUHAN | | TYPE-C-16PIN | JXTCONN(聚兴泰) | C53207801 | LCSC |
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

