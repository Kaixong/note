(defpackage amtec-srv
  (:use cl
        roslisp-msg-protocol)
  (:export
   "SETPOSITION"
   "<SETPOSITION-REQUEST>"
   "<SETPOSITION-RESPONSE>"
   "SWEEPPAN"
   "<SWEEPPAN-REQUEST>"
   "<SWEEPPAN-RESPONSE>"
   "HALT"
   "<HALT-REQUEST>"
   "<HALT-RESPONSE>"
   "SETVELOCITY"
   "<SETVELOCITY-REQUEST>"
   "<SETVELOCITY-RESPONSE>"
   "TARGETACCELERATION"
   "<TARGETACCELERATION-REQUEST>"
   "<TARGETACCELERATION-RESPONSE>"
   "GETSTATUS"
   "<GETSTATUS-REQUEST>"
   "<GETSTATUS-RESPONSE>"
   "SETPOSITIONVELOCITY"
   "<SETPOSITIONVELOCITY-REQUEST>"
   "<SETPOSITIONVELOCITY-RESPONSE>"
   "HOME"
   "<HOME-REQUEST>"
   "<HOME-RESPONSE>"
   "ADDTWOINTS"
   "<ADDTWOINTS-REQUEST>"
   "<ADDTWOINTS-RESPONSE>"
   "TARGETVELOCITY"
   "<TARGETVELOCITY-REQUEST>"
   "<TARGETVELOCITY-RESPONSE>"
   "RESET"
   "<RESET-REQUEST>"
   "<RESET-RESPONSE>"
   "SWEEPTILT"
   "<SWEEPTILT-REQUEST>"
   "<SWEEPTILT-RESPONSE>"
  ))

