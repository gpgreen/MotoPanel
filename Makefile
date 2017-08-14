all:
	@echo "To work on elements of a hardware project, use one of the following targets:"
	@echo " Target (speedo) 'speedoe' (gschem) 'speedoupdate' (gsch2pcb) 'speedopcb' (pcb)"

speedoe:
	gschem speedo/power.sch speedo/cpu.sch speedo/airp.sch 2>&1 > /dev/null &

speedoupdate:
	gsch2pcb speedo/project

speedopcb:
	pcb speedo/speedo.pcb 2>&1 > /dev/null &

