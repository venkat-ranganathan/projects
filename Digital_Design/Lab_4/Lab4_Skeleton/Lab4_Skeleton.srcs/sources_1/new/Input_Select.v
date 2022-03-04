`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/26/2019 11:46:06 PM
// Design Name: 
// Module Name: Input_Select
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


module Input_Select(
    input [7:0] Input,[7:0] R_data_b,
    input use_input,
    output [7:0] B
    );
    
    assign B = use_input == 1 ? Input : R_data_b;
    
endmodule
