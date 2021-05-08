# Use like this:
#
#     $ _() { python gamess-input-gen.py "${1}" | tee >(clip.exe) }; _ 0.4

from sys import argv

try:
    dist = float(argv[1])
except:
    print(f'''\
Usage:
  {argv[0]} <distance>

Option:
  <distance>    Distance between atoms (ex: 2.5)
''')
    exit(1)

print(f'''\
 $BASIS GBASIS=N31 NGAUSS=6 $END
 $CONTRL SCFTYP=RHF RUNTYP=ENERGY $END
 $DATA
Title
C1
N 7.0 0.0 0.0 0.0
N 7.0 {dist} 0.0 0.0
 $END
''')
