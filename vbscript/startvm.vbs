' startvm.vbs
' ========
'
' Put this script in "Startup" "시작 프로그램" folder.
'
'     # Turn on the "Run" windows with the `WIN + R` key and type below
'     shell:startup

CreateObject("Wscript.Shell").Run """%ProgramFiles%\Oracle\VirtualBox\VBoxManage.exe""" & " startvm 24e2752d-2e58-43c5-932f-054d2bbd93e2 --type headless", 0
