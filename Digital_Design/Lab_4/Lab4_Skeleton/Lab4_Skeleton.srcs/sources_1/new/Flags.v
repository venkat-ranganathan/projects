`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/26/2019 11:18:56 PM
// Design Name: 
// Module Name: Flags
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


module Flags(
    input ALU_C,ALU_Z,ALU_N,capture_C,capture_Z,capture_N,clk,step,
    output reg C,reg Z,reg N
    );
    
    always @ (posedge clk)
        begin
            if (capture_C & step)
                begin
                    C <= ALU_C;
                end
            if (capture_Z & step)
                begin
                    Z <= ALU_Z;
                end
            if (capture_N & step)
                begin
                    N <= ALU_N;
                end
        end
             
endmodule
