`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01/22/2020 05:57:53 PM
// Design Name: 
// Module Name: Instruction_ROM
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


module Instruction_ROM(
    input [3:0] Current_Instruction_address,
    output [8:0] Instruction
    );
    
    reg [8:0] Instruction_reg;
    assign Instruction = Instruction_reg;
    
    always @ (*)
    begin
        case (Current_Instruction_address)
            0:  Instruction_reg <= (9'h100); // inputting hex value of 9bit binary for each instruction
            1:  Instruction_reg <= (9'h104);
            2:  Instruction_reg <= (9'h01A);
            3:  Instruction_reg <= (9'h078);
            4:  Instruction_reg <= (9'h049);
            5:  Instruction_reg <= (9'h083);
            6:  Instruction_reg <= (9'h000);
            7:  Instruction_reg <= (9'h000);
            8:  Instruction_reg <= (9'h000);
            9:  Instruction_reg <= (9'h000);
            10: Instruction_reg <= (9'h000);
            11: Instruction_reg <= (9'h000);
            12: Instruction_reg <= (9'h000);
            13: Instruction_reg <= (9'h000);
            14: Instruction_reg <= (9'h000);
            default:  Instruction_reg <= (9'h000);
        endcase
    end
    
endmodule
