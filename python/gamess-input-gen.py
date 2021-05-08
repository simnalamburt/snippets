# Use like this:
#
#     _() { python gamess-input-gen.py "${1}" He2 | tee >(clip.exe) }; _ 0.4

from sys import argv

try:
    dist = float(argv[1])
    kind = argv[2]
    if kind != 'N2' and kind != 'O2' and kind != 'He2':
        raise
    if kind == 'N2':
        print(f'''\
 $BASIS GBASIS=N31 NGAUSS=6 $END
 $CONTRL SCFTYP=RHF RUNTYP=ENERGY $END
 $DATA
Title
C1
N 7.0 0.0 0.0 0.0
N 7.0 {dist} 0.0 0.0
 $END''')
    elif kind == 'O2':
        print(f'''\
 $BASIS GBASIS=N31 NGAUSS=6 $END
 $CONTRL SCFTYP=UHF MULT=3 RUNTYP=ENERGY $END
 $DATA
Title
C1
O 8.0 0.0 0.0 0.0
O 8.0 {dist} 0.0 0.0
 $END''')
    elif kind == 'He2':
        print(f'''\
 $BASIS GBASIS=N31 NGAUSS=6 $END
 $CONTRL SCFTYP=RHF RUNTYP=ENERGY $END
 $DATA
Title
C1
He 2.0 0.0 0.0 0.0
He 2.0 {dist} 0.0 0.0
 $END''')
    else:
        raise

except:
    print(f'''\
Usage:
  {argv[0]} <distance> <kind>

Option:
  <distance>    Distance between atoms (ex: 2.5)
  <kind>        Should be one of "N2", "O2", and "He2"
''')
    exit(1)
