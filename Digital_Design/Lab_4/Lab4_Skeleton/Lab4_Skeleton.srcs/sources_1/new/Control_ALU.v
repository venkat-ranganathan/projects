`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/26/2019 10:56:31 PM
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
    input [3:0] A,[3:0] B,[3:0] Opsel,
    input C,Z,N,
    output [3:0] G
    );
    
    reg [3:0] G_reg;
    
    assign G = G_reg;
    
    always @ (*)
    begin
        case (Opsel)
            0: G_reg <= A + 1;
            1: G_reg <= A + 1;
            2: G_reg <= A + 1;
            3: G_reg <= A + 1;
            4: G_reg <= A + 1;
            5: G_reg <= A + 1;
            6: G_reg <= A + 1;
            7: G_reg <= A + 1;
            8: G_reg <= B;
            9: G_reg <= (C == 0 ? B : A + 1);
            10: G_reg <= (C == 1 ? B : A + 1);
            11: G_reg <= (Z == 0 ? B : A + 1);
            12: G_reg <= (Z == 1 ? B : A + 1);
            13: G_reg <= (N == 0 ? B : A + 1);
            14: G_reg <= (N == 1 ? B : A + 1);
            default:  G_reg <= 4'b0000;
        endcase
    end
          
endmodule
