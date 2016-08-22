' startvm.vbs
' ========
'
' Put this script in "Start Program" folder. You'll always get your vm turned
' on in headless mode

CreateObject("Wscript.Shell").Run """%ProgramFiles%\Oracle\VirtualBox\VBoxManage.exe""" & " startvm 24e2752d-2e58-43c5-932f-054d2bbd93e2 --type headless", 0
