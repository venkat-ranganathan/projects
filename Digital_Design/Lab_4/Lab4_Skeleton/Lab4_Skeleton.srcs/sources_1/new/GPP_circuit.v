`timescale 1ns / 1ps

module GPP_circuit(
    input [7:0] sw,
    input clk,btn,
    output [15:0] led,
    output [6:0] seg,
    output [3:0] an,
    output dp
    );
    wire sw_in;
    wire [8:0] instruction;
    wire [3:0] instr_addr;
    wire [3:0] sseg_data_muxed;
    wire C_flag, Z_flag, N_flag;
    wire [7:0] out_data_Rd;
    wire [7:0] out_data_ALU;

    // Display ALU result in R_destination to led[15:8], ALU_Results to led[7:0]
    assign led={out_data_Rd, out_data_ALU}; 
    
    PushButton_Debouncer PushButton_Debouncer_MPP_Circuit(
        .clk(clk),
        .PB(btn),
        .PB_up(sw_in)
        );
    
    sseg_mux sseg_mux_mpp(
        .clk(clk),
        .leftmost({3'b000, instruction[8]}),
        .left_center(instruction[7:4]),
        .right_center(instruction[3:0]),
        .rightmost(instr_addr),
        .leftmost_dp(C_flag),
        .left_center_dp(Z_flag),
        .right_center_dp(N_flag),
        .rightmost_dp(1'b0),
        .dp_out(dp),
        .data_out(sseg_data_muxed),
        .anode(an)
        );
        
    sseg_numbers sseg_numbers_mpp(
        .seg_control(sseg_data_muxed),
        .segment(seg) 
    );
    
    MPP MPP_Circuit(
        .Input(sw),
        .clk(clk),
        .step(sw_in),
        .Output_A(out_data_Rd),
        .ALU_Results(out_data_ALU),
        .C(C_flag),
        .Z(Z_flag),
        .N(N_flag),
        .Instruction_out(instruction),
        .Instruction_addr_out(instr_addr)
        );
        
endmodule
