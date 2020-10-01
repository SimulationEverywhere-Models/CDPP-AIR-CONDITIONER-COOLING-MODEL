[top]
components : Memorizer Processor
in : InT
in : InB
in : InM
out : OutR
out : OutF
Link : InT InT@Memorizer
Link : InB InB@Memorizer
Link : InM InM@Processor
Link : OutT@Memorizer InT@Processor
Link : OutB@Memorizer InB@Processor
Link : OutR@Processor OutR
Link : OutF@Processor OutF

[Memorizer]
components : BM@BM TM@TM
in : InT
in : InB
out : OutT
out : OutB
Link : InT In@TM
Link : InB In@BM
Link : Out@TM OutT
Link : Out@BM OutB

[Processor]
components : BP@BP TP@TP
in : InT
in : InB
in : InM
out : OutR
out : OutF
Link : InT InT@TP
Link : InM InM@TP
Link : InB InB@BP
Link : InM InM@BP
Link : Temp@TP Temp@BP
Link : Blow@BP Blow@TP
Link : Out@TP OutR
Link : Out@BP OutF
