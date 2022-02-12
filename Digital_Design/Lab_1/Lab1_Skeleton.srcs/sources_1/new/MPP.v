`timescale 1ns / 1ps

module MPP(
    input [7:0] Input,
    input clk,step,
    input [3:0] instruction,
    output [7:0] Result
    );
    
    wire [7:0] Input_select;
    wire [7:0] R_data_a;
    wire [7:0] R_data_b;
    
    wire [7:0] result_sig;
    
    wire [3:0] machine_code;
    
    Input_Select Input_select_MPP(
        .Input(Input),
        .R_data_b(R_data_b),
        .use_input(machine_code[0]),
        .B(Input_select)
        );  
        
    Data_ALU Data_ALU_MPP(
        .A(R_data_a),
        .B(Input_select),
        .Opsel(machine_code[3:1]),
        .F(result_sig)
        );
        
    Parallel_Load_Reg_8 Parallel_load_reg8(
        .clk(clk),
        .load(1'b1),
        .d(result_sig),
        .q(Result)
        );
        
    control_unit control_unit( // changed control_unit to Control_Unit on left
    .clk(clk),
    .machine_code(machine_code)
    );


    assign R_data_a = Result;
    assign R_data_b = Result;
            
endmodule
