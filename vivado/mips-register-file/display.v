`timescale 1ns / 1ps

module display(
	input ShowMem,
	input [5:0] Addr,
	input [31:0] RegData, MemData,
	input clk, clr,
	output reg [4:0] ReadReg,
	output reg [5:0] ReadMem,
    output [6:0] a2g,
	output [7:0] an,
	output dp,
	input [15:0] DataIn
);
// 显示模块 Display Module
	reg [31:0] Data;

	always @(*)
	begin
		if (ShowMem === 1'b0)
		begin
			ReadReg <= Addr[4:0];
			ReadMem <= 6'b000_000;
			Data[15:0] <= RegData[15:0];
		end
		else
		begin
			ReadReg <= 5'b0_0000;
			ReadMem <= Addr;
			Data[15:0] <= MemData[15:0];
		end
		Data[31:16] <= DataIn[15:0];
	end

	async7seg seg(Data, clk, clr, a2g[6:0], an[7:0], dp);
endmodule
