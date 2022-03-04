`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01/20/2020 05:37:39 PM
// Design Name: 
// Module Name: MPP
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: This is the Multi-purpose processor model.
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
    output [8:0] Instruction_out,
    output [3:0] Instruction_addr_out
    );
    
    wire [7:0] Input_select;
    wire [7:0] R_data_a;
    wire [7:0] R_data_b;    
    wire [7:0] W_data;
    
    wire [8:0] instruction;
    wire [3:0] Current_Instruction_address;
    
    wire we;
    
    // set we given step button pressed and write_enable_not
    and AND(we,step,!instruction[7]);
    
    assign Instruction_out = instruction;
    assign Instruction_addr_out = Current_Instruction_address;
    
    // Set ALU_Results to output current ALU operation results
    assign ALU_Results=W_data;
    
    //  use_input=1: choose input, use_input=0: choose R_data_b 
    // use_input instruction[8]   
    Input_Select Input_select_MPP(
        .Input(Input),
        .R_data_b(R_data_b),
        .use_input(instruction[8]),
        .B(Input_select)
        );  
    // Opcode instruction[6:4]    
    Data_ALU Data_ALU_MPP(
        .A(R_data_a),
        .B(Input_select),
        .Opsel(instruction[6:4]),
        .F(W_data)
        );
    
    // R_destination: instruction[3:2]
    // R_souorce: instruction[1:0]  
    // write_enable_not: instruction[7] 
    MPP_RegFile MPP_Reg(
        .W_data(W_data),
        .W_addr(instruction[3:2]),
        .R_addr_a(instruction[3:2]),
        .R_addr_b(instruction[1:0]),
        .clk(clk),
        .W_enable(we),
        .R_data_a(R_data_a),
        .R_data_b(R_data_b)
        );
        assign Output_A = R_data_a;
        assign Output_B = R_data_b;    

    // Control logic unit
    Control_ALU Control_ALU_MPP(
        .clk(clk),
        .step(step),
        .JMP_addr(instruction[3:0]),
        .Opsel(instruction[7:4]),
        .instruction_addr(Current_Instruction_address)        
        );
        
        
    // Instrunction ROM to save sequential machine code
    Instruction_ROM Instruction_ROM_MPP(
        .Current_Instruction_address(Current_Instruction_address),
        .Instruction(instruction)
        );      
endmodule
