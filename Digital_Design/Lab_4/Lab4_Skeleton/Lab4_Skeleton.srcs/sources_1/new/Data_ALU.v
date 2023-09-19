`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/26/2019 10:19:08 PM
// Design Name: 
// Module Name: Data_ALU
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


module Data_ALU(
    input [7:0] A,[7:0] B,
    input [2:0] Opsel,
    output [7:0] F,
    output ALU_C, ALU_Z, ALU_N
    );
    
    reg [7:0] carry;
    reg [7:0] result_sig;
        
    always @ (*)
    begin
        case (Opsel)
            0: {carry,result_sig} <= B;
            1: {carry,result_sig} <= A^B;
            2: {carry,result_sig} <= A&B;
            3: {carry,result_sig} <= A|B;
            4: {carry,result_sig} <= A+B;
            5: {carry,result_sig} <= A-B;
            6: {carry,result_sig} <= B>>1;
            default: {carry,result_sig} <= A*B;
        endcase
    end 
  
    assign F = result_sig;
    
    assign  ALU_C = |carry;
    assign  ALU_Z = ~(|result_sig); 
    assign  ALU_N = result_sig[7];
    
        
endmodule
