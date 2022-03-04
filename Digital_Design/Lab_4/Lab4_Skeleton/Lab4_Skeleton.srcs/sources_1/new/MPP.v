`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/26/2019 11:26:28 PM
// Design Name: 
// Module Name: MPP
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


module MPP(
    input [7:0] Input,
    input clk,step,
    output [7:0] Output_A, Output_B, ALU_Results,
    output C,Z,N,
    output [8:0] Instruction_out,
    output [3:0] Instruction_addr_out
    );
    wire [8:0] Instruction;
    wire [7:0] R_data_a;
    wire [7:0] R_data_b;
    wire [7:0] W_data;
    wire [7:0] Input_select;
    wire [3:0] Current_Instruction_address;
    wire [3:0] G;
    wire ALU_C;
    wire ALU_Z;
    wire ALU_N;
    wire capture_C;
    wire capture_Z;
    wire capture_N;
    wire we;
    
    assign Instruction_out = Instruction;
    assign Instruction_addr_out = Current_Instruction_address;
    // set Rd=Output_A, Rs=R_data_b
    assign Output_A = R_data_a;
    assign Output_B = R_data_b; 
    // Set ALU_Results to output current ALU operation results
    assign ALU_Results=W_data;
    
    Input_Select Input_select_MPP(
        .Input(Input),
        .R_data_b(R_data_b),
        .use_input(Instruction[8]),
        .B(Input_select)
        );    
    Data_ALU Data_ALU_MPP(
        .A(R_data_a),
        .B(Input_select),
        .Opsel(Instruction[6:4]),
        .F(W_data),
        .ALU_C(ALU_C),
        .ALU_Z(ALU_Z),
        .ALU_N(ALU_N)
        );
        
    and AND1(we,step,!Instruction[7]);
    Reg_File Reg_File_MPP(
        .W_data(W_data),
        .W_addr(Instruction[3:2]),
        .R_addr_a(Instruction[3:2]),
        .R_addr_b(Instruction[1:0]),
        .clk(clk),
        .we(we),
        .R_data_a(R_data_a),
        .R_data_b(R_data_b)
        );
        
    Control_ALU Control_ALU_MPP(
        .A(Current_Instruction_address),
        .B(Instruction[3:0]),
        .Opsel(Instruction[7:4]),
        .C(C),
        .Z(Z),
        .N(N),
        .G(G)        
        );
        
    PC PC_MPP(
        .D(G),
        .clk(clk),
        .step(step),
        .Q(Current_Instruction_address)
        );
      
    Instruction_ROM Instruction_ROM_MPP(
        .Current_Instruction_address(Current_Instruction_address),
        .Instruction(Instruction)
        );
        
    Instruction_Decoder Instruction_Decoder_MPP(
        .opcode(Instruction[7:4]),
        .capture_C(capture_C),
        .capture_Z(capture_Z),
        .capture_N(capture_N)
        );
     Flags Flags_MPP(
        .ALU_C(ALU_C),
        .ALU_Z(ALU_Z),
        .ALU_N(ALU_N),
        .capture_C(capture_C),
        .capture_Z(capture_Z),
        .capture_N(capture_N),
        .clk(clk),
        .step(step),
        .C(C),
        .Z(Z),
        .N(N)
        );
             
endmodule
