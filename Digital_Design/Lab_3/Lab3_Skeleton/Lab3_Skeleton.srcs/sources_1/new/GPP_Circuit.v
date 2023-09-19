`timescale 1ns / 1ps

module GPP_Circuit(
    input [7:0] sw,
    input clk,btn,
    output [15:0] LED,
    output [6:0] seg,
    output [3:0] an
    );
    
    wire sw_in;
    wire [3:0] sseg_data_muxed;
    wire [7:0] out_data_Rd;
    wire [7:0] out_data_ALU;
    wire [8:0] instruction;
    wire [3:0] instr_addr;
    
    PushButton_Debouncer PushButton_Debouncer_MPP_Circuit(
        .clk(clk),
        .PB(btn),
        .PB_up(sw_in)
        );

    MPP MPP_Circuit(
        .Input(sw[7:0]),
        .clk(clk),
        .step(sw_in),
        .Output_A(out_data_Rd),
//        .Output_B(out_data_b),
        .ALU_Results(out_data_ALU),
        .Instruction_out(instruction),
        .Instruction_addr_out(instr_addr)
        );
        
    // Display ALU result in R_destination to LED[15:8], ALU_Results to LED[7:0]
    assign LED={out_data_Rd, out_data_ALU};   
    
    // Display instrunction code in SSEG
    sseg_mux sseg_mux_mpp(
        .clk(clk),
        .leftmost({3'b000, instruction[8]}),
        .left_center(instruction[7:4]),
        .right_center(instruction[3:0]),
        .rightmost(instr_addr),
        .leftmost_dp(1'b1),
        .left_center_dp(1'b1),
        .right_center_dp(1'b1),
        .rightmost_dp(1'b1),
        
        .data_out(sseg_data_muxed),
        .anode(an)
    );
    
    sseg_numbers sseg_numbers_mpp(
        .seg_control(sseg_data_muxed),
        .segment(seg) 
    );
    endmodule
