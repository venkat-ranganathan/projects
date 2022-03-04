`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01/22/2020 05:57:03 PM
// Design Name: 
// Module Name: Control_ALU
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module Control_ALU(
    input [3:0] JMP_addr,[3:0] Opsel,
    output [3:0] instruction_addr,
    input clk, step
    );
    
    wire [3:0] next_instruction, select_instruction, instruction_address;
    assign instruction_address = instruction_addr; // assigns old output instruction_addr to new instruction_address wire
    
    adder #(4) adder_c( // to re-uise adder with different bit width, use adder #(n)
    .a(instruction_address),
    .b(4'b0001),
    .sum(next_instruction),
    .cin(1'b0)
    );
    
    mux16 #(4) mux16(
    .in0(next_instruction),
    .in1(next_instruction),
    .in2(next_instruction),
    .in3(next_instruction),
    .in4(next_instruction),
    .in5(next_instruction),
    .in6(next_instruction),
    .in7(next_instruction),
    .in8(JMP_addr),
    .sel(Opsel),
    .out(select_instruction)
    );
    
    RegParallelLoad #(4) reg_4b( // to re-uise register with different bit width, use register (or whatever name) #(n)
    .clk(clk),
    .load(step),
    .d(select_instruction),
    .q(instruction_address),
    .clr(1'b0)
    );
    // ====================== Add your code here ================================;
    
endmodule
