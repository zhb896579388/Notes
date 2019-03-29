`timescale 1ns / 1ps

module topcpu(
    input CLK100MHZ,
    input [8:0] SW,
    output CG, CF, CE, CD, CC, CB, CA,
    output [7:0] AN,
    output DP,
	output [15:0] LED
);

	wire [31:0] out, addr, PC;
	wire mw;
	wire [4:0] ReadReg;
	wire [5:0] ReadMem;
	wire [31:0] RegData, MemData;
    wire clk1, clk190x4, clk1hz;
	wire cpuclk;

	assign cpuclk = clk1hz & (~SW[8]);
	assign LED = PC[19:4];
	
	top topmips(cpuclk, SW[7], out, addr, mw, ReadReg, ReadMem, RegData, MemData, PC);
	display displaydata(SW[0], SW[6:1], RegData, MemData, clk190x4, SW[7], ReadReg, ReadMem, {CG, CF, CE, CD, CC, CB, CA}, AN[7:0], DP);
	clkdiv clocker(CLK100MHZ, SW[7], clk1, clk190x4, clk1hz);

endmodule
