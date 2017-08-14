v 20130925 2
C 40000 40000 0 0 0 title-B.sym
T 49600 41000 9 12 1 0 0 0 1
SPEEDO - SENSORS
T 50000 40400 9 10 1 0 0 0 1
airp.sch
T 51000 40100 9 10 1 0 0 0 1
3
T 51500 40100 9 10 1 0 0 0 1
3
T 54000 40400 9 10 1 0 0 0 1
1
T 54000 40100 9 10 1 0 0 0 1
Greg Green
C 44300 46500 1 180 0 resistor-1.sym
{
T 44000 46100 5 10 0 0 180 0 1
device=RESISTOR
T 44300 46500 5 10 0 0 90 0 1
footprint=0603
T 43700 46800 5 10 1 1 0 0 1
refdes=R501
T 43700 46600 5 10 1 1 0 0 1
value=390
}
C 42500 46200 1 0 0 diode-1.sym
{
T 42900 46800 5 10 0 0 0 0 1
device=DIODE
T 42800 46700 5 10 1 1 0 0 1
refdes=D31
}
C 45200 46700 1 180 0 diode-2.sym
{
T 44800 46100 5 10 0 0 180 0 1
device=DIODE
T 44600 46700 5 10 1 1 0 0 1
refdes=D32
}
C 42700 43100 1 0 0 4N25-1.sym
{
T 43600 45100 5 10 0 0 0 0 1
device=4N25
T 44500 44900 5 10 1 1 0 6 1
refdes=U3
T 42700 43100 5 10 0 0 0 0 1
footprint=DIP6
}
C 41900 43400 1 90 0 capacitor-1.sym
{
T 41200 43600 5 10 0 0 90 0 1
device=CAPACITOR
T 41000 43600 5 10 0 0 90 0 1
symversion=0.1
T 41900 43400 5 10 0 0 0 0 1
footprint=0603
T 40800 43900 5 10 1 1 0 0 1
refdes=C501
T 40800 43700 5 10 1 1 0 0 1
value=0.001uF
}
C 45400 44300 1 270 0 capacitor-1.sym
{
T 46100 44100 5 10 0 0 270 0 1
device=CAPACITOR
T 46300 44100 5 10 0 0 270 0 1
symversion=0.1
T 45400 44300 5 10 0 0 180 0 1
footprint=0603
T 45900 43900 5 10 1 1 0 0 1
refdes=C502
T 45900 43700 5 10 1 1 0 0 1
value=0.01uF
}
C 46500 44400 1 180 0 resistor-1.sym
{
T 46200 44000 5 10 0 0 180 0 1
device=RESISTOR
T 46500 44400 5 10 0 0 90 0 1
footprint=0603
T 45800 44700 5 10 1 1 0 0 1
refdes=R502
T 45800 44500 5 10 1 1 0 0 1
value=4.7K
}
N 45200 46400 45200 45400 4
N 45200 45400 42700 45400 4
N 42700 45400 42700 44300 4
N 42700 44300 41700 44300 4
N 41700 43400 42700 43400 4
N 44800 43400 46500 43400 4
C 46400 43100 1 0 0 gnd-1.sym
N 45600 44300 44800 44300 4
C 46300 44300 1 0 0 3.3V-plus-1.sym
C 42500 46500 1 180 0 io-1.sym
{
T 41600 46300 5 10 0 0 180 0 1
net=COIL:1
T 42300 45900 5 10 0 0 180 0 1
device=none
T 41700 46400 5 10 1 1 180 1 1
value=COIL
}
C 46500 43300 1 0 0 io-1.sym
{
T 47400 43500 5 10 0 0 0 0 1
net=TACH:1
T 46700 43900 5 10 0 0 0 0 1
device=none
T 47300 43400 5 10 1 1 0 1 1
value=TACH
}
C 41600 43100 1 0 0 gnd-1.sym