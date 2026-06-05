

<img width="1584" height="672" alt="Carbsion Banner" src="https://github.com/user-attachments/assets/67661e50-5f1e-43cb-9ddb-9bfc348443cb" />


# Carbsion
### by Dhairya


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
- `src/cad/` - mechanical CAD sources
`production/` - **for fabrication outputs**
- `production/pcb/` - PCB fabrication files (Gerbers, BOM, Pick & Place)
- `production/cad/` - 3D printing files
`pics/` - images used in the README and documentation
`Electronic cad/` - 3d model of PCB from EasyEDA 

**SOFTWARE**
`firmware/` - All the code files
- `firmware/carb_scan/` - The code for the AI carb scanner
- `firmware/carb_scan/Testing/` - The micro python code files to test first
- `firmware/carb_scan/C++/` - Main C++ code files to run the main software. ***Note- I have not made any files in this rn as i have to learn C++ and will make the files after testing with micropython***
- `firmware/scan/` - Code files for the scanning part
- `firmware/scan/main/` - Main basic files to scan and recieve data from the sensor (non decrypted data)
- `firmware/scan/decrypt/` - Decryption code for the encrypted data  


## Schematic




## PCB 





## CAD





- ***Required 3d Printed parts***





## BOM- Bill Of Materials





## License 
This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.



## Credits 

***I used the following for making this project***

- ***My Dad*** - For inspiring the AI carb scanning feature
- ***EasyEDA*** - For PCB design
- ***FreeCAD*** - For designing the Case
- ***JLCPCB*** - Will be using to manufacture the PCB
- **[APX HUB by @Gabouin](https://github.com/Gabouin/APX-USB-HUB)** - Readme template
