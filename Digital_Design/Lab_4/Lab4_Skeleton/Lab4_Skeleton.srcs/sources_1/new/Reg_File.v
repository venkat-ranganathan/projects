`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/26/2019 09:35:55 PM
// Design Name: 
// Module Name: Reg_File
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


module Reg_File(
    input [7:0] W_data,[7:0] W_addr,
    input [1:0] R_addr_a,[1:0] R_addr_b,
    input clk,we,
    output [7:0] R_data_a,[7:0] R_data_b
    );
    reg [7:0] Register_0;
    reg [7:0] Register_1;
    reg [7:0] Register_2;
    reg [7:0] Register_3;
    
    reg [7:0] R_data_a_reg;
    reg [7:0] R_data_b_reg;
    
    assign R_data_a = R_data_a_reg;
    assign R_data_b = R_data_b_reg;
    
    always @ (*)
    begin
        case(R_addr_a)
            0: R_data_a_reg <= Register_0;
            1: R_data_a_reg <= Register_1;
            2: R_data_a_reg <= Register_2;
            default: R_data_a_reg <= Register_3;
        endcase
    end
    
    always @ (*)
    begin
        case(R_addr_b)
            0: R_data_b_reg <= Register_0;
            1: R_data_b_reg <= Register_1;
            2: R_data_b_reg <= Register_2;
            default: R_data_b_reg <= Register_3;
        endcase
    end 
    
    always @ (posedge clk)
        begin
            if (we) 
                case(W_addr)
                0: Register_0 <= W_data;
                1: Register_1 <= W_data;
                2: Register_2 <= W_data;
                3: Register_3 <= W_data;
                endcase
        end
                                 
endmodule
