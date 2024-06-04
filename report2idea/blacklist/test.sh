#!/bin/bash

# input data:
in='
H4sICBJrGmACA3Rlc3RfaW5wdXQyLnVuaXJlYwCtmN1u4zYQheP2FQr0NlBvFwRn+N/H6E0LLAJV
cWRHW9lyJaVpuvC7dygnsWUPdy3HRhDDlDSkPh2emdGPN8Pnp2K5bMtl0ZcP+X1dzP+qq66/ufn5
dvbb16xr53lXrvv8/qUvu+zXW2M/3WabtumbeVPTb6CfXfPUzst807R9POXzHY31XV4XXR/PMDoo
0PRPeKvjoWW/i7mhycrhEhmjvE21qJvn7jV0X7TL3SmfMwgowHoBygjvsrv3meno/qA0AkFlh/O8
BZS7dS2qll/Y+93n1QMd9zREbPLnap2vqvXTKwAxhHnZDNNWm+xw6fs7gsMFvMGT2x9+YZiCU1K7
MVfLcDX0+XSr6cMSttoRF+QJ030aFrJNUEYphR44Ho6ocDgC1goYDYRATwCPr7LjAUff48s8Rfaj
EXBHka0WDsdzSYo1PgnisElIY5hYWlYayGsD6BIzSP5IG4AfUoezltMHoJLSb2c1IxI0wxq/IxFv
EVhxkHQEOsOLQ3HKwIQwFMRnOsLunECNqR1J+8uw0IFlbgCFkubK+xEdC9xYnjY4xDNoS34jQiAP
cqmNyMF2Ka/zQHhHIndGJFnT9gs8a8OyVlpRMDxlPfjh5ebHuh+AUdvZ7xxtj+H7tHnWEskXFM8a
YVJe8cLIlIidFF5PUHFclwx4ZRUHjitqrXA7qxiwR44xaPIYq1LAy9gAiUMmMjabTGSKrLPCj3IJ
DcQ8kYIdBG/TKqHimD7cKWuFH4EtWdgot7M/LkUtdeBzt6HcHVL2DFNYo9IEMJkCY86cYsbv67qm
jFmySjueLJyT+NB6afjCU3thnZ+AVqVkHEBom0DrDRmIn4BWE1p99bpTcWgN2cMjR9bYcHGW01YJ
K2GCPSQrCivcqK5EMLHSTLgDCosTOCsrKS/qa7sDW8B5GbazPxnSSvlg5AdYExQbEhp2alKaiypO
wo11twx8jczLGJ2w/toyRm3YEkI6rbezh6/jhVhNeL2mSiCcoWdKl/ubz2kJ8f5NBKNjY0J+lyXK
ibj0qsubdf2SL/5+WNNY3z6V+2BPbZw0WzVt8U9VrL/Q6LqoxdOmqcX8vyTVtlyUbdnGS7MDOjEa
03ocCeT15jWV4JZHzpIMO0s8FMhOG97GSuduO3tmvRi1P69TZYUM9JDQ6Sv2qKhPelT4VgMIifTH
lBaa/mzgG8APeYeWIdH+IZJVrznwSir8AHhFwtbop7x++eabAXtMXbsLqDNdt1HWSSVAmytDT/Tc
VM4tTuzEIj10FGFIz5fYCeV20IEKMWIAkPKTUztZFHV36iebx6p7rNZLUf5brDZ1mfISmOoleOIl
mroJVMI53kscynPdxFDnasLgqOBtNJRTzpo6P3Jec/JWEcy5pIeKIHYTjpzrfNCsb983TV+2e8rN
6jqYFcvZq1hOKpYzBJ9oP/B4W2L0bbL/4Ie3W8R5znAOVlGBCniZnqmEQqT4htxVZWkTOUvNbbHq
mtVz0ZbvpJt2mfSHaclxZ3FHqMkULTVGeH565LorpMoTEIShvnV7M5P/A8hpBXJAFwAA
'

# output data:
out='
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
D30IdopNMOSkCXT+BBMydERZNAAA
'

blconfig="
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
P3M111h/IfqTx1ijCYfB1P9Y/QuhfCd2mzUAAA==
"

configfile="`mktemp`"
echo "$blconfig" | base64 -d | gunzip > "$configfile"

test -z "$srcdir" && export srcdir=.

. $srcdir/../test.sh

test_conversion "blacklist" "blacklist" "$in" "$out" --blacklist-config "$configfile"
result=$?

rm "$configfile"

exit $result

