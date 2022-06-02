# Ookami-Corne
Ookami Corne Layout

How to compile and flash. 

Compile: qmk compile -kb crkbd/rev1/common -km okami

Flash Right MCU: qmk flash -kb crkbd/rev1/common -km okami -bl dfu-split-right

Flash Left MCU: qmk flash -kb crkbd/rev1/common -km okami -bl dfu-split-left
