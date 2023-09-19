`timescale 1ns / 1ps

module MPP_RegFile(
    input [7:0] W_data,[1:0] W_addr,
    input [1:0] R_addr_a,[1:0] R_addr_b,
    input clk,W_enable,
    output [7:0] R_data_a,[7:0] R_data_b
    );
    
    wire [3:0] write; // need to specify bit width of wire
    wire [7:0] reg_0, reg_1, reg_2, reg_3;
    
    // ====================== Add your code here ================================;
    
    decoder Decoder(
    .en(W_enable),
    .in(W_addr),
    .out(write)
    );
    
    RegParallelLoad Register_0(
    .clk(clk),
    .load(write[0]),
    .clr(),
    .d(W_data),
    .q(reg_0)
    );
    
    RegParallelLoad Register_1(
    .clk(clk),
    .load(write[1]),
    .clr(),
    .d(W_data),
    .q(reg_1)
    );
    
    RegParallelLoad Register_2(
    .clk(clk),
    .load(write[2]),
    .clr(),
    .d(W_data),
    .q(reg_2)
    );
    
    RegParallelLoad Register_3(
    .clk(clk),
    .load(write[3]),
    .clr(),
    .d(W_data),
    .q(reg_3)
    );
    
    mux4 mux_4_a(
    .in0(reg_0),
    .in1(reg_1),
    .in2(reg_2),
    .in3(reg_3),
    .sel(R_addr_a),
    .out(R_data_a)
    );
    
    mux4 mux_4_b(
    .in0(reg_0),
    .in1(reg_1),
    .in2(reg_2),
    .in3(reg_3),
    .sel(R_addr_b),
    .out(R_data_b)
    );
    
endmodule